#include "PCSTree.h"
#include "PCSNode.h"
#include "PCSTreeForwardIterator.h"
#include "PCSTreeReverseIterator.h"

namespace Azul
{

	// constructor
	PCSTree::PCSTree()
		: mInfo{ 0 }, pRoot(nullptr)
	{
	};

	// destructor
	PCSTree::~PCSTree()
	{
		// TODO
		// Should remove the whole tree
		// Not in this PA, maybe add object pool in the future
	};

	// get Root
	PCSNode* PCSTree::GetRoot() const
	{
		return this->pRoot;
	}

	// insert
	void PCSTree::Insert(PCSNode* const pInNode, PCSNode* const pParent)
	{
		assert(pInNode != nullptr);

		if (pParent != nullptr)
		{
			pParent->AddChild(pInNode); // add to the front

			// Track the node's level and update info
			int level = this->privGetNodeLevel(pInNode);
			if (level > this->mInfo.currNumLevels)
			{
				this->privIncreaseNumLevels();
				assert(level == this->mInfo.currNumLevels);
			}
		}
		else
		{
			// The tree is empty, set the root
			assert(this->pRoot == pParent);

			this->pRoot = pInNode;
			pInNode->SetParent(nullptr);

			this->privIncreaseNumLevels();
		}

		// If this node is the last one of the tree, 
		// make root's reverse pointer link to it
		if (pInNode->GetForward() == nullptr)
		{
			assert(this->pRoot != nullptr);

			this->pRoot->SetReverse(pInNode);
		}

		// update info
		this->privIncreaseNumNodes();
	}

	// Remove
	void PCSTree::Remove(PCSNode* const pInNode)
	{
		assert(pInNode != nullptr);

		// Remove node from list
		PCSNode* pNextSibling = pInNode->GetNextSibling();
		PCSNode* pPrevSibling = pInNode->GetPrevSibling();

		if (pPrevSibling != nullptr)
		{
			pPrevSibling->SetNextSibling(pNextSibling);
		}
		else
		{
			PCSNode* pParent = pInNode->GetParent();

			if (pParent != nullptr)
			{
				pParent->SetChild(pNextSibling);
			}
			else
			{
				this->pRoot = nullptr;
			}

		}

		if (pNextSibling != nullptr)
		{
			pNextSibling->SetPrevSibling(pPrevSibling);
		}

		//----------------------------
		// Add for iterator:
		//  - Wash all removed nodes
		//  - Correct iterator link
		//----------------------------

		PCSNode* pFwdNode;
		PCSNode* pRevNode;

		pRevNode = pInNode->GetReverse();

		pFwdNode = nullptr;

		if (pInNode->GetChild() == nullptr)
		{
			pFwdNode = pInNode->GetForward();
		}
		else
		{
			pFwdNode = pInNode->GetNextSibling();

			if (pFwdNode == nullptr)
			{
				PCSNode* pTmp = pInNode->GetParent();
				while (pTmp != nullptr)
				{
					if (pTmp->GetNextSibling() != nullptr)
					{
						pFwdNode = pTmp->GetNextSibling();
						break;
					}
					pTmp = pTmp->GetParent();
				}
			}
		}

		// Wash all the removed node in the sub tree
		this->privRemoveSubTree(pInNode, pFwdNode);

		// Correct iterator link
		if (this->pRoot != nullptr)
		{
			assert(pRevNode != nullptr);
			pRevNode->SetForward(pFwdNode);

			if (pFwdNode != nullptr)
			{
				pFwdNode->SetReverse(pRevNode);
			}
			else
			{
				this->pRoot->SetReverse(pRevNode);
			}
		}
	}

	// get tree info
	void PCSTree::GetInfo(Info& info)
	{
		info.currNumNodes = this->mInfo.currNumNodes;
		info.maxNumNodes = this->mInfo.maxNumNodes;
		info.currNumLevels = this->mInfo.currNumLevels;
		info.maxNumLevels = this->mInfo.maxNumLevels;
	}

	void PCSTree::Print() const
	{
		PCSTreeForwardIterator FI(this->pRoot);

		PCSNode* pTmp = FI.First();

		Trace::out("\n---------------------------------------\n");
		Trace::out("* PCSTree Print: \n\n");

		while (!FI.IsDone())
		{
			pTmp->PrintNode();
			pTmp = FI.Next();
		}

		Trace::out("---------------------------------------\n\n");
	}

	//--------------------------------
	// Helper methods
	//--------------------------------

	// Increment number of nodes
	void PCSTree::privIncreaseNumNodes()
	{
		this->mInfo.currNumNodes++;
		if (this->mInfo.maxNumNodes < this->mInfo.currNumNodes)
		{
			this->mInfo.maxNumNodes = this->mInfo.currNumNodes;
		}
	}
	// Increment number of levels
	void PCSTree::privIncreaseNumLevels()
	{
		this->mInfo.currNumLevels++;
		if (this->mInfo.maxNumLevels < this->mInfo.currNumLevels)
		{
			this->mInfo.maxNumLevels = this->mInfo.currNumLevels;
		}
	}
	// Decrease number of nodes with value of val
	void PCSTree::privDecreaseNumNodes(int val)
	{
		this->mInfo.currNumNodes -= val;
	}
	// Decrease number of nodes with value of val
	void PCSTree::privUpdateNumLevels(int val)
	{
		this->mInfo.currNumLevels = val;
	}

	// Get level of the node
	int PCSTree::privGetNodeLevel(PCSNode* pNode)
	{
		assert(pNode != nullptr);

		int level = 1;
		PCSNode* pParent = pNode->GetParent();

		while (pParent != nullptr)
		{
			level++;
			pParent = pParent->GetParent();
		}

		return level;
	}

	// Get the max level of the tree
	int PCSTree::privGetMaxLevel()
	{
		if (this->pRoot == nullptr)
		{
			return 0;
		}

		PCSNode* pNext = this->pRoot;
		PCSNode* pTmp = nullptr;

		int maxLevel = 0;
		int levelTracing = 1;

		while (pNext != nullptr)
		{
			pTmp = pNext;
			levelTracing += this->privDeltaLevelToNextNode(pNext, pTmp);
			if (maxLevel < levelTracing)
			{
				maxLevel = levelTracing;
			}
		}

		return maxLevel;
	}

	// Iterator - get next node and return the value of delta level between curr node and next node
	int PCSTree::privDeltaLevelToNextNode(PCSNode*& outNextNode, const PCSNode* const pCurrNode) const
	{
		assert(pCurrNode != nullptr);

		PCSNode* pSibling = pCurrNode->GetNextSibling();
		PCSNode* pParent = pCurrNode->GetParent();
		PCSNode* pChild = pCurrNode->GetChild();

		outNextNode = nullptr;

		int deltaLevel = 0;

		// DFS
		if (pChild != nullptr)
		{
			// if pNode has children, go to child node
			outNextNode = pChild;
			deltaLevel++;
		}
		else
		{
			// While pNode has no child
			if (pSibling != nullptr)
			{
				// Go to sibling if there is one
				outNextNode = pSibling;
			}
			else
			{
				// if no sibling, go back to parent and go to parent's sibling
				while (pParent != nullptr)
				{
					outNextNode = pParent->GetNextSibling();

					deltaLevel--;

					if (outNextNode != nullptr)
					{
						break;
					}
					else
					{
						pParent = pParent->GetParent();
					}
				}
			}
		}

		return deltaLevel;
	}

	// Removing helper - wash all nodes in the sub tree
	void PCSTree::privRemoveSubTree(PCSNode* root, const PCSNode* const pStopFlag)
	{
		// Wash all removed nodes

		assert(root != nullptr);

		int numNodes = 0;

		PCSTreeForwardIterator FI(root);
		PCSNode* pCurr = FI.First();
		PCSNode* pNext = pCurr;

		// Keep iterating until get to pStopFlag
		while (pNext != pStopFlag)
		{
			numNodes++;

			pCurr = pNext;
			pNext = FI.Next();

			pCurr->Wash();
		}

		// Update Info
		int currLevel = this->privGetMaxLevel();
		if (currLevel < this->mInfo.currNumLevels)
		{
			this->privUpdateNumLevels(currLevel);
		}

		this->privDecreaseNumNodes(numNodes);
	}

}


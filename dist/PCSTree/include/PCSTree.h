#ifndef PCSTREE_H
#define PCSTREE_H

namespace Azul
{

	// forward declare
	class PCSNode;

	// PCSTree class 
	class PCSTree
	{
	public:
		// Simple data structure
		struct Info
		{
			int currNumNodes;
			int maxNumNodes;
			int currNumLevels;
			int maxNumLevels;
		};

	public:
		// constructor
		PCSTree();

		// copy constructor 
		PCSTree(const PCSTree& in) = delete;

		// assignment operator
		PCSTree& operator = (const PCSTree& in) = delete;

		// destructor
		~PCSTree();

		// get Root
		PCSNode* GetRoot() const;

		// insert
		void Insert(PCSNode* const pInNode, PCSNode* const pParent);

		// remove
		void Remove(PCSNode* const pInNode);

		// get info
		void GetInfo(Info& info);
		void Print() const;

	private:

		// Info helper
		void privIncreaseNumNodes();
		void privIncreaseNumLevels();
		void privDecreaseNumNodes(int val);
		void privUpdateNumLevels(int val);

		// Level helper
		int privGetNodeLevel(PCSNode* pNode);
		int privGetMaxLevel();

		// Iterator - return an int : the value of delta level between curr node and next node
		int privDeltaLevelToNextNode(PCSNode*& outNextNode, const PCSNode* const pCurrNode) const;

		// Removing helper
		void privRemoveSubTree(PCSNode* root, const PCSNode* const pStopFlag);

	private:

		// Data
		Info	mInfo;
		PCSNode* pRoot;

	};

}

#endif
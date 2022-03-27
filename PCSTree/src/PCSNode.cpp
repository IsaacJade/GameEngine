#include "PCSTree.h"
#include "PCSNode.h"

namespace Azul
{// constructor
	PCSNode::PCSNode()
		: pParent(nullptr), pChild(nullptr), pNextSibling(nullptr), pPrevSibling(nullptr)
		, pForward(nullptr), pReverse(nullptr)
		, pName{ 0 }
	{
	}

	// copy constructor
	PCSNode::PCSNode(const PCSNode& in)
		: pParent(in.pParent), pChild(in.pChild), pNextSibling(in.pNextSibling), pPrevSibling(in.pPrevSibling)
		, pForward(in.pForward), pReverse(in.pReverse)
		, pName{ 0 }
	{
		memcpy(this->pName, in.pName, PCSNode::NAME_SIZE - 1);
	}

	// Specialize Constructor
	PCSNode::PCSNode(PCSNode* const pInParent, PCSNode* const pInChild, PCSNode* const pInNextSibling, PCSNode* const pInPrevSibling, const char* const pInName)
		: pParent(pInParent), pChild(pInChild), pNextSibling(pInNextSibling), pPrevSibling(pInPrevSibling)
		, pForward(nullptr), pReverse(nullptr)
		, pName{ 0 }
	{
		assert(pInName != nullptr);
		memcpy(this->pName, pInName, PCSNode::NAME_SIZE - 1);
	}

	PCSNode::PCSNode(const char* const pInName)
		:pParent(nullptr), pChild(nullptr), pNextSibling(nullptr), pPrevSibling(nullptr)
		, pForward(nullptr), pReverse(nullptr)
		, pName{ 0 }
	{
		assert(pInName != nullptr);
		memcpy(this->pName, pInName, PCSNode::NAME_SIZE - 1);
	}

	// destructor
	PCSNode::~PCSNode()
	{
		//REPLACE_ME(0);
	}

	// assignment operator
	PCSNode& PCSNode::operator = (const PCSNode& in)
	{
		this->pParent = in.pParent;
		this->pChild = in.pChild;
		this->pNextSibling = in.pNextSibling;
		this->pPrevSibling = in.pPrevSibling;
		this->pForward = in.pForward;
		this->pReverse = in.pReverse;

		memcpy(this->pName, in.pName, PCSNode::NAME_SIZE);
		this->pName[PCSNode::NAME_SIZE - 1] = 0;

		return *this;
	}

	void PCSNode::SetParent(PCSNode* const pIn)
	{
		this->pParent = pIn;
	}

	void PCSNode::SetChild(PCSNode* const pIn)
	{
		this->pChild = pIn;
	}

	void PCSNode::SetNextSibling(PCSNode* const pIn)
	{
		this->pNextSibling = pIn;
	}

	void PCSNode::SetPrevSibling(PCSNode* const pIn)
	{
		this->pPrevSibling = pIn;
	}

	void PCSNode::SetForward(PCSNode* const pIn)
	{
		this->pForward = pIn;
	}

	void PCSNode::SetReverse(PCSNode* const pIn)
	{
		this->pReverse = pIn;
	}

	PCSNode* PCSNode::GetParent(void) const
	{
		return this->pParent;
	}

	PCSNode* PCSNode::GetChild(void) const
	{
		return this->pChild;
	}

	PCSNode* PCSNode::GetNextSibling(void) const
	{
		return this->pNextSibling;
	}

	PCSNode* PCSNode::GetPrevSibling(void) const
	{
		return this->pPrevSibling;
	}

	PCSNode* PCSNode::GetForward(void) const
	{
		return this->pForward;
	}

	PCSNode* PCSNode::GetReverse(void) const
	{
		return this->pReverse;
	}

	PCSNode::Code PCSNode::SetName(const char* const pInName)
	{
		if (pInName == nullptr)
		{
			return Code::FAIL_NULL_PTR;
		}
		else
		{
			memcpy(this->pName, pInName, PCSNode::NAME_SIZE);

			// Make sure the last char is null char
			this->pName[PCSNode::NAME_SIZE - 1] = '\0';

			return Code::SUCCESS;
		}
	}

	PCSNode::Code PCSNode::GetName(char* const pOutBuffer, unsigned int sizeOutBuffer) const
	{
		if (pOutBuffer == nullptr)
		{
			// Null pointer checking
			return Code::FAIL_NULL_PTR;
		}
		else
		{
			if (sizeOutBuffer <= 0)
			{
				return Code::FAIL_RETURN_NOT_INITIALIZED;
			}
			else if (sizeOutBuffer >= PCSNode::NAME_SIZE)
			{
				// sizeOutBuffer is too big
				// Only copy the whole name 

				memcpy(pOutBuffer, this->pName, PCSNode::NAME_SIZE);

				return Code::SUCCESS;
			}
			else
			{
				// sizeOutBuffer is too small
				// Copy out-size of the name, and make sure the out buffer ends with '\0'

				memcpy(pOutBuffer, this->pName, sizeOutBuffer);

				// Make sure the last char is null char
				pOutBuffer[sizeOutBuffer - 1] = '\0';

				return Code::SUCCESS;
			}
		}
	}

	void PCSNode::PrintNode() const
	{
		Trace::out("\n");
		Trace::out("      * Name: %s\n", this->pName);
		Trace::out("     address: 0x%08X\n", this);

		if (this->pParent != nullptr)
		{
			Trace::out("      parent: %s  (0x%08X)\n", this->pParent->pName, this->pParent);
		}
		else
		{
			Trace::out("      parent: null\n");
		}

		if (this->pChild != nullptr)
		{
			Trace::out("       child: %s  (0x%08X)\n", this->pChild->pName, this->pChild);
		}
		else
		{
			Trace::out("       child: null\n");
		}

		if (this->pPrevSibling != nullptr)
		{
			Trace::out(" prevSibling: %s  (0x%08X)\n", this->pPrevSibling->pName, this->pPrevSibling);
		}
		else
		{
			Trace::out(" prevSibling: null\n");
		}

		if (this->pNextSibling != nullptr)
		{
			Trace::out(" nextSibling: %s  (0x%08X)\n", this->pNextSibling->pName, this->pNextSibling);
		}
		else
		{
			Trace::out(" nextSibling: null\n");
		}

		Trace::out("\n");

	}

	void PCSNode::PrintChildren() const
	{
		PCSNode* pTmp = this->pChild;

		Trace::out("\n---------------------------------------\n");
		Trace::out("* %s's Children: \n\n", this->pName);

		int count = 0;

		while (pTmp != nullptr)
		{
			count++;
			Trace::out("- %d -\n", count);
			pTmp->PrintNode();
			pTmp = pTmp->pNextSibling;
		}

		Trace::out("---------------------------------------\n\n");
	}

	void PCSNode::PrintSiblings() const
	{
		Trace::out("\n---------------------------------------\n");
		Trace::out("* %s's Siblings: \n\n", this->pName);

		PCSNode* pTmp = this->pParent;

		if (pTmp != nullptr)
		{
			pTmp = pTmp->pChild;

			int count = 0;

			while (pTmp != nullptr)
			{
				count++;
				Trace::out("- %d -\n", count);
				pTmp->PrintNode();
				pTmp = pTmp->pNextSibling;
			}
		}
		else
		{
			Trace::out("- 1 -\n");
			this->PrintNode();
		}

		Trace::out("---------------------------------------\n\n");
	}

	int PCSNode::GetNumSiblings() const
	{
		int numSiblings = 0;
		PCSNode* pTmp = this->pPrevSibling;
		while (pTmp != nullptr)
		{
			numSiblings++;
			pTmp = pTmp->pPrevSibling;
		}

		pTmp = this->pNextSibling;
		while (pTmp != nullptr)
		{
			numSiblings++;
			pTmp = pTmp->pNextSibling;
		}

		numSiblings++;
		return numSiblings;
	}

	int PCSNode::GetNumChildren() const
	{
		int numChild = 0;
		PCSNode* pTmp = this->pChild;

		while (pTmp != nullptr)
		{
			numChild++;
			pTmp = pTmp->pNextSibling;
		}

		return numChild;
	}

	//------------------
	// Helper methods
	//------------------

	// Add node to the front of the child list
	void PCSNode::AddChild(PCSNode* const pIn)
	{
		assert(pIn != nullptr);

		if (this->pForward != nullptr)
		{
			this->pForward->pReverse = pIn;
		}
		pIn->pForward = this->pForward;

		pIn->pReverse = this;
		this->pForward = pIn;



		if (this->pChild != nullptr)
		{
			this->pChild->pPrevSibling = pIn;
		}

		pIn->pNextSibling = this->pChild;
		pIn->pPrevSibling = nullptr;

		this->pChild = pIn;

		pIn->pParent = this;
	}

	// Clear the pointers
	void PCSNode::Wash()
	{
		this->pParent = nullptr;
		this->pChild = nullptr;
		this->pNextSibling = nullptr;
		this->pPrevSibling = nullptr;

		this->pForward = nullptr;
		this->pReverse = nullptr;
	}
}
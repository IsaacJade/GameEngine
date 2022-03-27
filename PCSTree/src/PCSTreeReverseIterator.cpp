#include "PCSTreeReverseIterator.h"
#include "PCSTreeForwardIterator.h"

namespace Azul
{
	PCSTreeReverseIterator::PCSTreeReverseIterator(PCSNode* rootNode)
	{
		PCSTreeForwardIterator pForward = PCSTreeForwardIterator(rootNode);

		this->root = rootNode;
		this->current = rootNode;
		this->prevNode = nullptr;

		PCSNode* pPrev = this->root;
		PCSNode* pNode = pForward.First();

		while (!pForward.IsDone())
		{
			pPrev = pNode;
			pNode = pForward.Next();

			if (pNode != nullptr)
			{
				pNode->SetReverse(pPrev);
			}
		}
		this->root->SetReverse(pPrev) ;
	}

	PCSNode* PCSTreeReverseIterator::First()
	{
		this->current = this->root->GetReverse();

		return this->current;
	}

	PCSNode* PCSTreeReverseIterator::Next()
	{
		this->prevNode = this->current;
		this->current = this->current->GetReverse();

		return this->current;
	}

	bool PCSTreeReverseIterator::IsDone()
	{
		return (this->prevNode == this->root);
	}

	PCSNode* PCSTreeReverseIterator::CurrentItem()
	{
		return this->current;
	}

}


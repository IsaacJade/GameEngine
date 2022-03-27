#include "PCSTreeForwardIterator.h"

namespace Azul
{
	PCSTreeForwardIterator::PCSTreeForwardIterator(PCSNode* rootNode)
		: root(rootNode), current(rootNode)
	{
	}

	PCSNode* PCSTreeForwardIterator::First()
	{
		this->current = this->root;
		return  this->current;
	}

	PCSNode* PCSTreeForwardIterator::Next()
	{
		assert(this->current != nullptr);

		this->current = this->current->GetForward();

		return  this->current;
	}

	bool PCSTreeForwardIterator::IsDone()
	{
		return  (this->current == nullptr);
	}

	PCSNode* PCSTreeForwardIterator::CurrentItem()
	{
		return  this->current;
	}
}


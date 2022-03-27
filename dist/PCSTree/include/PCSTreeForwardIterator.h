#ifndef PCSTREE_FORWARD_ITERATOR_H
#define PCSTREE_FORWARD_ITERATOR_H

#include "PCSTreeIterator.h"

namespace Azul
{
	class PCSTreeForwardIterator : public PCSTreeIterator
	{
	public:
		PCSTreeForwardIterator(PCSNode* rootNode);

		virtual PCSNode* First() override;
		virtual PCSNode* Next() override;
		virtual bool IsDone() override;
		virtual PCSNode* CurrentItem() override;

		PCSNode* privNextStep(PCSNode* pNode, PCSNode* pParent, PCSNode* pChild, PCSNode* pSibling);

	private:
		// YOU can store what you want... here
		// these were my variables...
		PCSNode* root;
		PCSNode* current;
	};

}

#endif
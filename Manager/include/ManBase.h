#ifndef MAN_BASE_H
#define MAN_BASE_H

class ListBase;

#include "Iterator.h"

class ManBase
{
protected:
	//----------------------------------------------------------------------
	// Constructor
	//----------------------------------------------------------------------
	ManBase(int DeltaGrow);
	//ManBase(ListBase* poActive, ListBase* poReserve, int InitialNumReserved = 5, int DeltaGrow = 2);
	ManBase(const ManBase &) = delete;
	ManBase &operator = (const ManBase &) = delete;
	virtual ~ManBase();
	
	//----------------------------------------------------------------------
	// Base methods - called in Derived class but lives in Base
	//----------------------------------------------------------------------
	void baseSetReserve(int reserveNum, int reserveGrow);
	
	DLink *baseAddToFront();
	DLink *baseAddToEnd();

	Iterator *baseGetActiveIterator();
	Iterator *baseGetReserveIterator();

	DLink *baseFind(DLink *pNodeTarget);

	void baseRemove(DLink *pNodeBase);

	void baseDump();

	//----------------------------------------------------------------------
	// Abstract methods - the "contract" Derived class must implement
	//----------------------------------------------------------------------
	virtual DLink *derivedCreateNode() = 0;

	//----------------------------------------------------------------------
	// Protected methods - helpers
	//----------------------------------------------------------------------
	void proFillReservedPool(int count);

	//----------------------------------------------------------------------
	// Data:
	//----------------------------------------------------------------------
	ListBase *poActive;
	ListBase *poReserve;
	int mDeltaGrow;
	int mTotalNumNodes;
	int mNumReserved;
	int mNumActive;

};

#endif
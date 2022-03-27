//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "MeshNodeMan.h"
#include "MeshNull.h"

MeshNodeMan *MeshNodeMan::posInstance = nullptr;

//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
MeshNodeMan::MeshNodeMan(int reserveNum, int reserveGrow)
    : ManBase(reserveGrow)
{
    // Preload the reserve
    this->proFillReservedPool(reserveNum);

    // initialize derived data here
    Mesh *pMesh = new MeshNull();
    assert(pMesh);
    this->poNodeCompare = new MeshNode();
    assert(this->poNodeCompare);
    this->poNodeCompare->Set("null_mesh", pMesh);
}

MeshNodeMan::~MeshNodeMan()
{
    delete this->poNodeCompare;
    this->poNodeCompare = nullptr;

    // iterate through the list and delete
    Iterator *pIt = this->baseGetActiveIterator();

    DLink *pNode = pIt->First();

    // Walk through the nodes
    while(!pIt->IsDone())
    {
        MeshNode *pDeleteMe = (MeshNode *) pIt->Curr();
        pNode = pIt->Next();
        delete pDeleteMe;
    }

    pIt = this->baseGetReserveIterator();

    pNode = pIt->First();

    // Walk through the nodes
    while(!pIt->IsDone())
    {
        MeshNode *pDeleteMe = (MeshNode *) pIt->Curr();
        pNode = pIt->Next();
        delete pDeleteMe;
    }
}

//----------------------------------------------------------------------
// Static Methods
//----------------------------------------------------------------------
void MeshNodeMan::Create(int reserveNum, int reserveGrow)
{
    // make sure values are ressonable 
    assert(reserveNum >= 0);
    assert(reserveGrow > 0);

    // initialize the singleton here
    assert(posInstance == nullptr);

    // Do the initialization
    if(posInstance == nullptr)
    {
        posInstance = new MeshNodeMan(reserveNum, reserveGrow);
    }

}

void MeshNodeMan::Destroy()
{
    MeshNodeMan *pMan = MeshNodeMan::privGetInstance();
    assert(pMan != nullptr);
    AZUL_UNUSED_VAR(pMan);

    delete MeshNodeMan::posInstance;
    MeshNodeMan::posInstance = nullptr;
}

MeshNode *MeshNodeMan::Add(char * name, Mesh *pMesh)
{
    MeshNodeMan *pMan = MeshNodeMan::privGetInstance();

    assert(pMesh);

    MeshNode *pNode = (MeshNode *) pMan->baseAddToFront();
    assert(pNode != nullptr);

    // Initialize the date
    pNode->Set(name, pMesh);

    return pNode;
}

Mesh *MeshNodeMan::Find(char * name)
{
    MeshNodeMan *pMan = MeshNodeMan::privGetInstance();
    assert(pMan != nullptr);

    // Compare functions only compares two Nodes

    // So:  Use the Compare Node - as a reference
    //      use in the Compare() function
    Mesh *pMesh = pMan->poNodeCompare->GetMesh();
    assert(pMesh);

    pMesh->_name = my_string(name);

    MeshNode *pData = (MeshNode *) pMan->baseFind(pMan->poNodeCompare);

    if(pData)
    {
        pMesh = pData->GetMesh();
    }
    else
    {
        pMesh = nullptr;
    }

    return pMesh;
}

void MeshNodeMan::Remove(MeshNode *pNode)
{
    assert(pNode != nullptr);

    MeshNodeMan *pMan = MeshNodeMan::privGetInstance();
    assert(pMan != nullptr);

    pMan->baseRemove(pNode);
}

void MeshNodeMan::Dump()
{
    MeshNodeMan *pMan = MeshNodeMan::privGetInstance();
    assert(pMan != nullptr);

    pMan->baseDump();
}

//----------------------------------------------------------------------
// Private methods
//----------------------------------------------------------------------
MeshNodeMan *MeshNodeMan::privGetInstance()
{
    // Safety - this forces users to call Create() first before using class
    assert(posInstance != nullptr);

    return posInstance;
}

//----------------------------------------------------------------------
// Override Abstract methods
//----------------------------------------------------------------------
DLink *MeshNodeMan::derivedCreateNode()
{
    DLink *pNodeBase = new MeshNode();
    assert(pNodeBase != nullptr);

    return pNodeBase;
}








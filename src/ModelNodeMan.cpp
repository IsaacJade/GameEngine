#include "ModelNodeMan.h"

ModelNodeMan* ModelNodeMan::posInstance = nullptr;

//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
ModelNodeMan::ModelNodeMan(int reserveNum, int reserveGrow)
    : ManBase(reserveGrow)
{
    // Preload the reserve
    this->proFillReservedPool(reserveNum);

    // initialize derived data here
    Model* pModel = new Model();
    assert(pModel);
    this->poNodeCompare = new ModelNode();
    assert(this->poNodeCompare);
    this->poNodeCompare->Set(Model::Name::NOT_INITIALIZED, pModel);
}

ModelNodeMan::~ModelNodeMan()
{
    delete this->poNodeCompare;
    this->poNodeCompare = nullptr;

    // iterate through the list and delete
    Iterator* pIt = this->baseGetActiveIterator();

    DLink* pNode = pIt->First();

    // Walk through the nodes
    while (!pIt->IsDone())
    {
        ModelNode* pDeleteMe = (ModelNode*)pIt->Curr();
        pNode = pIt->Next();
        delete pDeleteMe;
    }

    pIt = this->baseGetReserveIterator();

    pNode = pIt->First();

    // Walk through the nodes
    while (!pIt->IsDone())
    {
        ModelNode* pDeleteMe = (ModelNode*)pIt->Curr();
        pNode = pIt->Next();
        delete pDeleteMe;
    }
}

//----------------------------------------------------------------------
// Static Methods
//----------------------------------------------------------------------
void ModelNodeMan::Create(int reserveNum, int reserveGrow)
{
    // make sure values are ressonable 
    assert(reserveNum >= 0);
    assert(reserveGrow > 0);

    // initialize the singleton here
    assert(posInstance == nullptr);

    // Do the initialization
    if (posInstance == nullptr)
    {
        posInstance = new ModelNodeMan(reserveNum, reserveGrow);
    }

}

void ModelNodeMan::Destroy()
{
    ModelNodeMan* pMan = ModelNodeMan::privGetInstance();
    assert(pMan != nullptr);
    AZUL_UNUSED_VAR(pMan);

    delete ModelNodeMan::posInstance;
    ModelNodeMan::posInstance = nullptr;
}

ModelNode* ModelNodeMan::Add(Model::Name name, Model* pModel)
{
    ModelNodeMan* pMan = ModelNodeMan::privGetInstance();

    assert(pModel);

    ModelNode* pNode = (ModelNode*)pMan->baseAddToFront();
    assert(pNode != nullptr);

    // Initialize the date
    pNode->Set(name, pModel);

    return pNode;
}

Model* ModelNodeMan::Find(Model::Name _name)
{
    ModelNodeMan* pMan = ModelNodeMan::privGetInstance();
    assert(pMan != nullptr);

    // Compare functions only compares two Nodes

    // So:  Use the Compare Node - as a reference
    //      use in the Compare() function
    Model* pModel = pMan->poNodeCompare->GetModel();
    assert(pModel);

    pModel->name = _name;

    ModelNode* pData = (ModelNode*)pMan->baseFind(pMan->poNodeCompare);

    if (pData)
    {
        pModel = pData->GetModel();
    }
    else
    {
        pModel = nullptr;
    }

    return pModel;
}

void ModelNodeMan::Remove(ModelNode* pNode)
{
    assert(pNode != nullptr);

    ModelNodeMan* pMan = ModelNodeMan::privGetInstance();
    assert(pMan != nullptr);

    pMan->baseRemove(pNode);
}

void ModelNodeMan::Dump()
{
    ModelNodeMan* pMan = ModelNodeMan::privGetInstance();
    assert(pMan != nullptr);

    pMan->baseDump();
}

//----------------------------------------------------------------------
// Private methods
//----------------------------------------------------------------------
ModelNodeMan* ModelNodeMan::privGetInstance()
{
    // Safety - this forces users to call Create() first before using class
    assert(posInstance != nullptr);

    return posInstance;
}

//----------------------------------------------------------------------
// Override Abstract methods
//----------------------------------------------------------------------
DLink* ModelNodeMan::derivedCreateNode()
{
    DLink* pNodeBase = new ModelNode();
    assert(pNodeBase != nullptr);

    return pNodeBase;
}








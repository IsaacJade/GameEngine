#include "ShaderMan.h"
#include "ShaderObject.h"

ShaderMan *ShaderMan::posInstance = nullptr;

//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
ShaderMan::ShaderMan(int reserveNum, int reserveGrow)
    : ManBase(reserveGrow)
{
    // Preload the reserve
    this->proFillReservedPool(reserveNum);

    // initialize derived data here
    this->poNodeCompare = new ShaderObject();
}

ShaderMan::~ShaderMan()
{
    delete this->poNodeCompare;
    this->poNodeCompare = nullptr;

    // iterate through the list and delete
    Iterator *pIt = this->baseGetActiveIterator();

    DLink *pNode = pIt->First();

    // Walk through the nodes
    while(!pIt->IsDone())
    {
        ShaderObject *pDeleteMe = (ShaderObject *) pIt->Curr();
        pNode = pIt->Next();
        delete pDeleteMe;
    }

    pIt = this->baseGetReserveIterator();

    pNode = pIt->First();

    // Walk through the nodes
    while(!pIt->IsDone())
    {
        ShaderObject *pDeleteMe = (ShaderObject *) pIt->Curr();
        pNode = pIt->Next();
        delete pDeleteMe;
    }
}

//----------------------------------------------------------------------
// Static Methods
//----------------------------------------------------------------------
void ShaderMan::Create(int reserveNum, int reserveGrow)
{
    // make sure values are ressonable 
    assert(reserveNum >= 0);
    assert(reserveGrow > 0);

    // initialize the singleton here
    assert(posInstance == nullptr);

    // Do the initialization
    if(posInstance == nullptr)
    {
        posInstance = new ShaderMan(reserveNum, reserveGrow);
    }

}

void ShaderMan::Destroy()
{
    ShaderMan *pMan = ShaderMan::privGetInstance();
    assert(pMan != nullptr);
    AZUL_UNUSED_VAR(pMan);

    delete ShaderMan::posInstance;
    ShaderMan::posInstance = nullptr;
}

ShaderObject *ShaderMan::Add(ShaderObject::Name name, const char *const pName, const ShaderObject::Type type)
{
    ShaderMan *pMan = ShaderMan::privGetInstance();

    ShaderObject *pNode = (ShaderObject *) pMan->baseAddToFront();
    assert(pNode != nullptr);

    // Initialize the date
    assert(pName);
    pNode->Set(name, pName, type);

    return pNode;
}

ShaderObject *ShaderMan::Find(ShaderObject::Name _name)
{
    ShaderMan *pMan = ShaderMan::privGetInstance();
    assert(pMan != nullptr);

    // Compare functions only compares two Nodes

    // So:  Use the Compare Node - as a reference
    //      use in the Compare() function
    pMan->poNodeCompare->name = _name;

    ShaderObject *pData = (ShaderObject *) pMan->baseFind(pMan->poNodeCompare);
    return pData;
}

void ShaderMan::Remove(ShaderObject *pNode)
{
    assert(pNode != nullptr);

    ShaderMan *pMan = ShaderMan::privGetInstance();
    assert(pMan != nullptr);

    pMan->baseRemove(pNode);
}

void ShaderMan::Dump()
{
    ShaderMan *pMan = ShaderMan::privGetInstance();
    assert(pMan != nullptr);

    pMan->baseDump();
}

//----------------------------------------------------------------------
// Private methods
//----------------------------------------------------------------------
ShaderMan *ShaderMan::privGetInstance()
{
    // Safety - this forces users to call Create() first before using class
    assert(posInstance != nullptr);

    return posInstance;
}

//----------------------------------------------------------------------
// Override Abstract methods
//----------------------------------------------------------------------
DLink *ShaderMan::derivedCreateNode()
{
    DLink *pNodeBase = new ShaderObject();
    assert(pNodeBase != nullptr);

    return pNodeBase;
}





#include "MeshNode.h"
#include "StringThis.h"

MeshNode::MeshNode()
    : DLink(),
    poMesh(nullptr)
{
    this->privClear();
}

MeshNode::~MeshNode()
{
    this->privClear();
}

void MeshNode::Set(char * name, Mesh *pMesh)
{
   assert(pMesh);
   this->poMesh = pMesh;

   this->poMesh->SetName(name);
}

Mesh * MeshNode::GetMesh()
{
    return this->poMesh;
}

void MeshNode::privClear()
{
    if(this->poMesh)
    {
        delete this->poMesh;
    }
    this->poMesh = nullptr;
}

const char * MeshNode::GetName()
{
    const char *pName = nullptr;
    if(this->poMesh)
    {
        pName = this->poMesh->GetName();
    }

    return pName;
}

void MeshNode::Wash()
{
    this->privClear();
}

bool MeshNode::Compare(DLink *pTargetNode)
{
    // This is used in ManBase.Find() 
    assert(pTargetNode);

    MeshNode *pDataB = (MeshNode *) pTargetNode;

    bool status = false;

    assert(pDataB->poMesh);
    assert(this->poMesh);

    if(this->poMesh->_name == pDataB->poMesh->_name)
    {
        status = true;
    }

    return status;
}

void MeshNode::Dump()
{
    Trace::out("      MeshNode(%p)\n", this);

    // Data:
    if(this->poMesh)
    {
        Trace::out("      Mesh(%p) \n", this->poMesh);
        Trace::out("      Name: %s \n", this->GetName());
    }
    else
    {
        Trace::out("      Name: %s \n", "null");
    }

    DLink::Dump();
}

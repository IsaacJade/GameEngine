
#include "ModelNode.h"
#include "StringThis.h"

ModelNode::ModelNode()
    : DLink(),
    poModel(nullptr)
{
    this->privClear();
}

ModelNode::~ModelNode()
{
    this->privClear();
}

void ModelNode::Set(Model::Name name, Model* pModel)
{
    assert(pModel);
    this->poModel = pModel;

    this->poModel->SetName(name);
}

Model* ModelNode::GetModel()
{
    return this->poModel;
}

void ModelNode::privClear()
{
    if (this->poModel)
    {
        delete this->poModel;
    }
    this->poModel = nullptr;
}

const char* ModelNode::GetName()
{
    const char* pName = nullptr;
    if (this->poModel)
    {
        pName = this->poModel->GetName();
    }

    return pName;
}

void ModelNode::Wash()
{
    this->privClear();
}

bool ModelNode::Compare(DLink* pTargetNode)
{
    // This is used in ManBase.Find() 
    assert(pTargetNode);

    ModelNode* pDataB = (ModelNode*)pTargetNode;

    bool status = false;

    assert(pDataB->poModel);
    assert(this->poModel);

    if (this->poModel->name == pDataB->poModel->name)
    {
        status = true;
    }

    return status;
}

void ModelNode::Dump()
{
    Trace::out("      ModelNode(%p)\n", this);

    // Data:
    if (this->poModel)
    {
        Trace::out("      Model(%p) \n", this->poModel);
        //Trace::out("      Name: %s \n", StringMe(this->poModel->name));
    }
    else
    {
        Trace::out("      Name: %s \n", "null");
    }

    DLink::Dump();
}


// --- End of File ---

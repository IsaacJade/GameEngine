#ifndef MODEL_NODE_H
#define MODEL_NODE_H

#include "DLink.h"
#include "Model.h"

class ModelNode : public DLink
{
public:
    ModelNode();
    ModelNode(const Model&) = delete;
    ModelNode& operator = (const Model&) = delete;
    virtual ~ModelNode();

    void Set(Model::Name name, Model* pMesh);
    Model* GetModel();

    virtual const char* GetName() override;
    virtual void Wash() override;
    virtual bool Compare(DLink* pTargetNode) override;
    virtual void Dump() override;

private:
    void privClear();

    //--------------------------------------------------
    // Data
    //--------------------------------------------------
    Model* poModel;
};
#endif
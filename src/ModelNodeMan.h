#ifndef MODEL_MAN_H
#define MODEL_MAN_H 

#include "ManBase.h"
#include "ModelNode.h"
#include "Model.h"

class ModelNodeMan : public ManBase
{
public:
    static void Create(int reserveNum = 0, int reserveGrow = 1);
    static void Destroy();
    static ModelNode* Add(Model::Name name, Model* pModel);
    static Model* Find(Model::Name name);
    static void Remove(ModelNode* pNode);
    static void Dump();

private:
    static ModelNodeMan* privGetInstance();

    ~ModelNodeMan();
    ModelNodeMan(int reserveNum, int reserveGrow);

protected:
    DLink* derivedCreateNode() override;

private:
    ModelNode* poNodeCompare;
    static ModelNodeMan* posInstance;

};

#endif


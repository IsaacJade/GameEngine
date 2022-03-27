#ifndef MESH_NODE_H
#define MESH_NODE_H

#include "DLink.h"
#include "Mesh.h"

class MeshNode : public DLink
{
public:
    MeshNode();
    MeshNode(const Mesh &) = delete;
    MeshNode &operator = (const Mesh &) = delete;
    virtual ~MeshNode();

    void Set(char * name ,Mesh *pMesh);
    Mesh *GetMesh();

    virtual const char *GetName() override;
    virtual void Wash() override;
    virtual bool Compare(DLink *pTargetNode) override;
    virtual void Dump() override;

private:
    void privClear();

    //--------------------------------------------------
    // Data
    //--------------------------------------------------
    Mesh *poMesh;
};

#endif

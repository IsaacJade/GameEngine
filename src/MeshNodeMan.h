#ifndef MESH_MAN_H
#define MESH_MAN_H 

#include "ManBase.h"
#include "MeshNode.h"
#include "Mesh.h"

class MeshNodeMan : public ManBase
{
    //----------------------------------------------------------------------
    // Static Methods
    //----------------------------------------------------------------------
public:
    static void Create(int reserveNum = 0, int reserveGrow = 1);
    static void Destroy();
    static MeshNode *Add(char * name, Mesh *pMesh );
    static Mesh *Find(char* name);
    static void Remove(MeshNode *pNode);
    static void Dump();

    //----------------------------------------------------------------------
    // Private methods
    //----------------------------------------------------------------------
private:
    static MeshNodeMan *privGetInstance();

    ~MeshNodeMan();
    MeshNodeMan(int reserveNum, int reserveGrow);

    //----------------------------------------------------------------------
    // Override Abstract methods
    //----------------------------------------------------------------------
protected:
    DLink *derivedCreateNode() override;

    //----------------------------------------------------------------------
    // Data: unique data for this manager 
    //----------------------------------------------------------------------
private:
    MeshNode *poNodeCompare;
    static MeshNodeMan *posInstance;

};

#endif

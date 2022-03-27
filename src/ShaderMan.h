#ifndef SHADER_MAN_H
#define SHADER_MAN_H 

#include "ManBase.h"
#include "ShaderObject.h"

class ShaderMan : public ManBase
{
    //----------------------------------------------------------------------
    // Static Methods
    //----------------------------------------------------------------------
public:
    static void Create(int reserveNum = 0, int reserveGrow = 1);
    static void Destroy();
    static ShaderObject *Add(ShaderObject::Name name, const char *const pName, const ShaderObject::Type type );
    static ShaderObject *Find(ShaderObject::Name name);
    static void Remove(ShaderObject *pNode);
    static void Dump();

    //----------------------------------------------------------------------
    // Private methods
    //----------------------------------------------------------------------
private:
    static ShaderMan *privGetInstance();
    
    ShaderMan() = delete;
    ShaderMan(const ShaderMan &) = delete;
    ShaderMan &operator=(const ShaderMan &) = delete;
    virtual ~ShaderMan();

    ShaderMan(int reserveNum, int reserveGrow);

    //----------------------------------------------------------------------
    // Override Abstract methods
    //----------------------------------------------------------------------
protected:
    DLink *derivedCreateNode() override;


    //----------------------------------------------------------------------
    // Data: unique data for this manager 
    //----------------------------------------------------------------------
private:
    ShaderObject *poNodeCompare;
    static ShaderMan *posInstance;

};

#endif
#include "Mesh.h"
#include "StringThis.h"
#include "SSBO.h"

Mesh::Mesh()
	: numVerts(0),
	numTris(0),    
	vao(0),
	vbo_verts(0),
	vbo_norms(0),
	vbo_uv(0),
	vbo_index(0),
	vbo_color(0),
	vbo_weight(0),
	vbo_joint(0),
	poInverseBind(),
	numInverseBind(0)
{
}

Mesh::~Mesh()
{
	delete this->poInverseBind;
}

void Mesh::Wash()
{
	this->numVerts = 0;
	this->numTris = 0;
	vao = 0;
	vbo_verts = 0;
	vbo_norms = 0;	
	vbo_uv = 0;
	vbo_index = 0;
	vbo_color = 0;
	vbo_weight = 0;
	vbo_joint = 0;
}

bool Mesh::Compare(DLink *pTarget)
{
	// This is used in ManBase.Find() 
	assert(pTarget != nullptr);

	Mesh *pDataB = (Mesh *) pTarget;

	bool status = false;
	if(this->_name == pDataB->_name)
	{
		status = true;
	}

	return status;
}

void Mesh::SetName(char* name)
{
	this->_name = my_string(name);
}

const char *Mesh::GetName()
{
	return _name.c_str();
}



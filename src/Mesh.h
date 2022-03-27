#ifndef MESH_H
#define MESH_H

#include "sb7.h"
#include "MathEngine.h"
#include "DLink.h"
#include "BoundingSphere.h"
#include "Texture.h"
#include "my_string.h"

namespace Azul
{
	class SSBO;
}

using namespace Azul;

class Mesh
{
public:
	enum class Name
	{	
		CUBE,
		CRATE,
		BONE_2,
		SPHERE,
		PYRAMID,
		CAMERA,
		SPRITE,
		Bone,
		Bone_001,
		Bone_L,
		Bone_L_001,
		Bone_L_002,
		Bone_R,
		Bone_R_001,
		Bone_R_002,
		NULL_MESH,
		DEFAULT,
		NOT_INITIALIZED
	};

public:
	Mesh();
	Mesh(Mesh &copyMesh);
	Mesh &operator = (Mesh &copyMesh);
	virtual ~Mesh();
	// Data
	int numVerts;
	int numTris;    

	GLuint vao;
	GLuint vbo_verts;  // x,y,z         Layout: 0
	GLuint vbo_norms;  // nx,ny,nz      Layout: 1
	GLuint vbo_uv;     // u,v           Layout: 2
	GLuint vbo_index;  // trilist       Layout: 3
	GLuint vbo_color;  // r,g,b,a       Layout: 4

	// Skin data
	GLuint vbo_weight; // wa,wb,wc,wd   Layout: 5
	GLuint vbo_joint;  // ja,jb,jc,jd   Layout: 6

	void Wash();
	bool Compare(DLink *pTarget);
	const char *GetName();
	void SetName(char * name);

	
	SSBO			*poInverseBind;
	unsigned int     numInverseBind;

protected:


public:
	my_string _name;
	Texture::Name textName;
	unsigned int hash;
};

#endif

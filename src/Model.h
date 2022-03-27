
#ifndef MODEL_H
#define MODEL_H

#include "sb7.h"
#include "MathEngine.h"
#include "DLink.h"
#include "BoundingSphere.h"
#include "Mesh.h"
#include "modelData.h"

namespace Azul
{
	class Clip;
	class Skeleton;
}

using namespace Azul;

class Model
{
public:
	enum class Name
	{
		ANTIQUECAMERA,
		CRATE,
		FISH,
		SPACE,
		CHICKEN,
		DOGE,
		R2D2,
		BONEA,
		MOUSEY,
		CORSET,
		NULL_MESH,
		DEFAULT,
		NOT_INITIALIZED
	};

public:
	Model();
	Model(Model& copyModel) = delete;
	Model& operator = (Model& copyModel) = delete;
	virtual ~Model();
	Model(const char* const pMeshFileName);
	bool Compare(DLink* pTarget);
	char* GetName();
	void SetName(Model::Name _name);
	void AddClip(const char* const pMeshFileName);
	Skeleton* InitSkeleton();
private:
	void privSetClip(modelData& mB);
	void privLoad(modelData& mB);

	// Data
public:
	Name name;
	Mesh* p_mesh;
	
	Sphere* p_sphere;
	unsigned int BoneCount;

	Clip* p_clip;
private:
	my_string pFileName;

};

#endif
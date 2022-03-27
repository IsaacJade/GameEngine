#include "GraphicsObject.h"
#include "File.h"
#include "MathEngine.h"
#include "Mesh.h"
#include "MeshNodeMan.h"
#include "Model.h"
#include "modelData.h"
#include "ProtoBuffMesh.h"

using namespace Azul;

GraphicsObject::GraphicsObject( Mesh *const _pMesh, const ShaderObject *const _pShaderObj)
	:pShaderObj(_pShaderObj)
{
	this->pMesh = _pMesh;
	this->poWorld = new Matrix(Matrix::Special::Identity);
	assert(this->poWorld);
	assert(_pMesh);
	assert(_pShaderObj);
	this->poCurrSphere = new Sphere();
	this->poRefSphere = new Sphere();
	assert(this->poCurrSphere);
}

GraphicsObject::GraphicsObject(Model* const Model, const ShaderObject* const _pShaderObj)
	:pShaderObj(_pShaderObj)
{
	this->poWorld = new Matrix(Matrix::Special::Identity);
	this->poCurrSphere = new Sphere();
	assert(this->poCurrSphere);
	this->pMesh = Model->p_mesh;
	this->poRefSphere = new Sphere;
	*this->poRefSphere = *Model->p_sphere;
}

GraphicsObject::~GraphicsObject()
{
	//delete pMesh;
	delete this->poWorld;
	delete this->poCurrSphere;
	delete this->poRefSphere;
}

void GraphicsObject::Render()
{

		this->SetState();
		this->SetDataGPU();
		this->Draw();
		this->RestoreState();
	
}

const Mesh *GraphicsObject::GetMesh() const
{
	return this->pMesh;
}


Matrix &GraphicsObject::GetWorld()
{
	return *this->poWorld;
}


void GraphicsObject::SetWorld(Matrix &_world)
{
	*this->poWorld = _world;
}


#ifndef GRAPHICS_OBJECT_H
#define GRAPHICS_OBJECT_H

#include "MathEngine.h"
#include "ShaderObject.h"
#include "RenderMaterial.h"
#include "BoundingSphere.h"

using namespace Azul;

class Mesh;
class Model;

class GraphicsObject : public RenderMaterial
{
public:
	GraphicsObject( Mesh * const Mesh,const ShaderObject * const pShaderObj);
	GraphicsObject( Model* const Model, const ShaderObject* const pShaderObj);
	GraphicsObject() = delete;
	GraphicsObject(const GraphicsObject &) = delete;
	GraphicsObject &operator = (const GraphicsObject &) = delete;
	virtual ~GraphicsObject();

	void Render();
	void SetWorld(Azul::Matrix &_world);

	const Mesh* GetMesh() const;
	Azul::Matrix &GetWorld();

	Sphere *poCurrSphere;
	Sphere* poRefSphere;

protected:
	Mesh        *pMesh;
	Azul::Matrix       *poWorld;
	const ShaderObject *pShaderObj;
};

#endif


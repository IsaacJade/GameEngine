#ifndef GRAPHICS_OBJECT_WIREFRAME_H
#define GRAPHICS_OBJECT_WIREFRAME_H

#include "GraphicsObject.h"

class GraphicsObject_Wireframe :public GraphicsObject
{
public:
	GraphicsObject_Wireframe(Mesh *const _pMesh, const ShaderObject *const _pShaderObj);
	GraphicsObject_Wireframe(Model* const Model, const ShaderObject* const pShaderObj);

	GraphicsObject_Wireframe() = delete;
	GraphicsObject_Wireframe(const GraphicsObject_Wireframe&) = delete;
	GraphicsObject_Wireframe& operator=(const GraphicsObject_Wireframe&) = delete;
	virtual ~GraphicsObject_Wireframe() = default;

	// Rendermaterial contract
	virtual void SetState() override;
	virtual void SetDataGPU() override;
	virtual void Draw() override;
	virtual void RestoreState() override;

	// data:  place uniform instancing here

};

#endif

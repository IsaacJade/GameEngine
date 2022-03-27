#ifndef GRAPHICS_OBJECT_FLAT_TEXTURE_H
#define GRAPHICS_OBJECT_FLAT_TEXTURE_H

#include "GraphicsObject.h"
#include "TextureMan.h"

class GraphicsObject_FlatTexture :public GraphicsObject
{
public:
	GraphicsObject_FlatTexture(Mesh * const pMesh, const ShaderObject * const pShaderObj, Texture::Name _name);
	GraphicsObject_FlatTexture(Model* const Model, const ShaderObject* const pShaderObj, Texture::Name _name);

	GraphicsObject_FlatTexture() = delete;
	GraphicsObject_FlatTexture(const GraphicsObject_FlatTexture&) = delete;
	GraphicsObject_FlatTexture& operator= (const GraphicsObject_FlatTexture&) = delete;
	virtual ~GraphicsObject_FlatTexture() = default;

	// Rendermaterial contract
	virtual void SetState() override;
	virtual void SetDataGPU() override;
	virtual void Draw() override;
	virtual void RestoreState() override;

	// data:  place uniform instancing here

	Texture::Name textName;

};
#endif

#ifndef GRAPHICS_OBJECT_SKIN_TEXTURE_H
#define GRAPHICS_OBJECT_SKIN_TEXTURE_H

#include "GraphicsObject.h"
#include "TextureMan.h"

namespace Azul
{
	class SSBO;
}

class GraphicsObject_SkinTexture :public GraphicsObject
{
public:
	GraphicsObject_SkinTexture(Mesh * const pMesh, const ShaderObject * const pShaderObj, Texture::Name _name);

	GraphicsObject_SkinTexture() = delete;
	GraphicsObject_SkinTexture(const GraphicsObject_SkinTexture &) = delete;
	GraphicsObject_SkinTexture &operator= (const GraphicsObject_SkinTexture &) = delete;
	virtual ~GraphicsObject_SkinTexture();

	void SetBoneWorld(Matrix *pBoneWorld, unsigned int numB);

	// Rendermaterial contract
	virtual void SetState() override;
	virtual void SetDataGPU() override;
	virtual void Draw() override;
	virtual void RestoreState() override;

	// -------------------------
	// 	   Data
	// -------------------------

	Matrix* pMWorld;
	SSBO*pBoneWorld;
	unsigned int numBone;
	Texture::Name textName;

};
#endif

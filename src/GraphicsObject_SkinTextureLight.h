#ifndef GRAPHICS_OBJECT_SKIN_TEXTURELIGHT_H
#define GRAPHICS_OBJECT_SKIN_TEXTURELIGHT_H

#include "GraphicsObject.h"
#include "TextureMan.h"

namespace Azul
{
	class SSBO;
}

class GraphicsObject_SkinTextureLight :public GraphicsObject
{
public:
	GraphicsObject_SkinTextureLight(Mesh * const pMesh, const ShaderObject * const pShaderObj, Texture::Name _name, Vect& LightColor, Vect& LightPos);

	GraphicsObject_SkinTextureLight() = delete;
	GraphicsObject_SkinTextureLight(const GraphicsObject_SkinTextureLight &) = delete;
	GraphicsObject_SkinTextureLight &operator= (const GraphicsObject_SkinTextureLight &) = delete;
	virtual ~GraphicsObject_SkinTextureLight();

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
	Vect* poLightColor;
	Vect* poLightPos;

};
#endif

#pragma once
#include "Texture.h"
#include "Image.h"
#include "GraphicsObject.h"
#include "ShaderObject.h"
class Glyph;

namespace Azul
{
	class GraphicsObject_Font : public GraphicsObject
	{
	public:
		GraphicsObject_Font(Mesh* pMesh, ShaderObject* pShaderObj, Glyph* _pGlyph, Rect rect);
		virtual ~GraphicsObject_Font();
		
		// Rendermaterial contract
		virtual void SetState() override;
		virtual void SetDataGPU() override;
		virtual void Draw() override;
		virtual void RestoreState() override;
		// data:  place uniform instancing here
		void updateGlyph(Glyph* p_G);
			//GLuint textureID;
		Glyph* pGlyph;
		Matrix* poMatrix_uv;
		Matrix* poMatrix_orig;

		float origWidth;
		float origHeight;

		float origPosX;
		float origPosY;

	};
}

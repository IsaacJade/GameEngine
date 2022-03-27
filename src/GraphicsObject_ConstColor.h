#ifndef GRAPHICS_OBJECT_CONST_COLOR_H
#define GRAPHICS_OBJECT_CONST_COLOR_H

#include "GraphicsObject.h"

using namespace Azul;

	class GraphicsObject_ConstColor :public GraphicsObject
	{
	public:
		GraphicsObject_ConstColor(Mesh* _pMesh, ShaderObject* _pShaderObj, Vect& LightColor, Vect& LightPos);
		GraphicsObject_ConstColor(Model* const Model, const ShaderObject* const pShaderObj, Vect& LightColor, Vect& LightPos);

		GraphicsObject_ConstColor() = delete;
		GraphicsObject_ConstColor(const GraphicsObject_ConstColor&) = delete;
		GraphicsObject_ConstColor& operator = (const GraphicsObject_ConstColor&) = delete;
		virtual ~GraphicsObject_ConstColor();

		// Rendermaterial contract
		virtual void SetState() override;
		virtual void SetDataGPU() override;
		virtual void Draw() override;
		virtual void RestoreState() override;

		// data:  place uniform instancing here
		Vect* poLightColor;
		Vect* poLightPos;
	};



#endif
#include "GraphicsObject_Null.h"

GraphicsObject_Null::GraphicsObject_Null(Mesh* const pMesh, const ShaderObject* const pShaderObj)
	: GraphicsObject(pMesh, pShaderObj)
{

}

void GraphicsObject_Null::SetState()
{


}

void GraphicsObject_Null::SetDataGPU()
{
}

void GraphicsObject_Null::Draw()
{
}

void GraphicsObject_Null::RestoreState()
{

}

// ---  End of File ---

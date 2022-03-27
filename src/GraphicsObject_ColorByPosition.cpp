#include "MathEngine.h"
#include "Mesh.h"
#include "GraphicsObject_ColorByPosition.h"
#include "Camera.h"
#include "CameraMan.h"

using namespace Azul;

GraphicsObject_ColorByPosition::GraphicsObject_ColorByPosition(Mesh *const Mesh, const ShaderObject *const pShaderObj)
	: GraphicsObject(Mesh, pShaderObj)
{
	assert(pMesh);
	assert(pShaderObj);
	assert(poWorld);
}

GraphicsObject_ColorByPosition::GraphicsObject_ColorByPosition(Model* const Model, const ShaderObject* const pShaderObj)
	:GraphicsObject(Model,pShaderObj)
{
	assert(pMesh);
	assert(pShaderObj);
	assert(poWorld);
}

void GraphicsObject_ColorByPosition::SetState()
{

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
}

void GraphicsObject_ColorByPosition::SetDataGPU()
{
	// use this shader
	this->pShaderObj->SetActive();	

	// set the vao
	glBindVertexArray(this->GetMesh()->vao);

	Camera *pCam = CameraMan::GetCurrent(Camera::Type::PERSPECTIVE_3D);

	Matrix world = this->GetWorld();
	Matrix view = pCam->getViewMatrix();
	Matrix proj = pCam->getProjMatrix();

	glUniformMatrix4fv(this->pShaderObj->GetLocation("proj_matrix"), 1, GL_FALSE, (float*)&proj);
	glUniformMatrix4fv(this->pShaderObj->GetLocation("view_matrix"), 1, GL_FALSE, (float*)&view);
	glUniformMatrix4fv(this->pShaderObj->GetLocation("world_matrix"), 1, GL_FALSE, (float *) &world);

}

void GraphicsObject_ColorByPosition::Draw()
{
	//The starting point of the IBO index buffer object
	glDrawElements(GL_TRIANGLES, 3 * this->GetMesh()->numTris, GL_UNSIGNED_INT, 0);
}

void GraphicsObject_ColorByPosition::RestoreState()
{
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
}

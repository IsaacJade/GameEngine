#include "GraphicsObject_SkinTextureLight.h"
#include "TextureMan.h"
#include "Mesh.h"
#include "Camera.h"
#include "CameraMan.h"
#include "SSBO.h"
using namespace Azul;


GraphicsObject_SkinTextureLight::GraphicsObject_SkinTextureLight(Mesh * const _pMesh, const ShaderObject * const _pShaderObj, Texture::Name _name, Vect& LightColor, Vect& LightPos)
	: GraphicsObject(_pMesh, _pShaderObj), textName(_name)
{
	// check the base class
	assert(this->pMesh);
	assert(this->pShaderObj);
	assert(this->poWorld);

	this->pBoneWorld = new SSBO();
	this->poLightColor = new Vect(LightColor);
	this->poLightPos = new Vect(LightPos);
	assert(poLightColor);
	assert(poLightPos);
}

GraphicsObject_SkinTextureLight::~GraphicsObject_SkinTextureLight()
{
	delete pBoneWorld;
	delete this->poLightColor;
	delete this->poLightPos;
}

void GraphicsObject_SkinTextureLight::SetBoneWorld(Matrix*_pBoneWorld, unsigned int numB)
{
	assert(_pBoneWorld);
	this->pMWorld = _pBoneWorld;
	this->numBone = numB;
	pBoneWorld->Set(numBone, sizeof(Matrix), pMWorld);
}

void GraphicsObject_SkinTextureLight::SetState()
{
	glActiveTexture(GL_TEXTURE0);

	// Bind the texture
	GLuint textureID = TextureMan::FindID(this->textName);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
}

void GraphicsObject_SkinTextureLight::SetDataGPU()
{
	// use this shader
	this->pShaderObj->SetActive();	
	pBoneWorld->Set(numBone, sizeof(Matrix), pMWorld);
	// set the vao
	glBindVertexArray(this->GetMesh()->vao);

	Camera *pCam = CameraMan::GetCurrent(Camera::Type::PERSPECTIVE_3D);

	//Matrix world = this->GetWorld();
	Matrix view = pCam->getViewMatrix();
	Matrix proj = pCam->getProjMatrix();

	// Send the uniforms
	glUniformMatrix4fv(this->pShaderObj->GetLocation("proj_matrix"), 1, GL_FALSE, (float *) &proj);
	glUniformMatrix4fv(this->pShaderObj->GetLocation("view_matrix"), 1, GL_FALSE, (float *) &view);
	this->pBoneWorld->Bind(0);
	this->pMesh->poInverseBind->Bind(1);

	Vect light = *this->poLightPos;
	Vect color = *this->poLightColor;
	glUniform3fv(this->pShaderObj->GetLocation("vLightPos"), 1, (float*)&light);
	glUniform4fv(this->pShaderObj->GetLocation("vColor"), 1, (float*)&color);
}

void GraphicsObject_SkinTextureLight::Draw()
{
	//The starting point of the IBO index buffer object
	glDrawElements(GL_TRIANGLES, 3 * this->GetMesh()->numTris, GL_UNSIGNED_INT, 0);
}

void GraphicsObject_SkinTextureLight::RestoreState()
{
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
}

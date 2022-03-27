#include "GraphicsObject_TextureLight.h"
#include "Mesh.h"
#include "TextureMan.h"
#include "Camera.h"
#include "ShaderObject.h"
#include "CameraMan.h"

using namespace Azul;

GraphicsObject_TextureLight::GraphicsObject_TextureLight(Mesh *_pMesh, ShaderObject *_pShaderObj, Texture::Name _name, Vect &LightColor, Vect &LightPos)
	: GraphicsObject(_pMesh, _pShaderObj),
	textName(_name)
{
	if(textName != Texture::Name::DEFAULT)
	{
		Texture* pTex = TextureMan::Find(textName);
		this->pMesh->hash = pTex->hash;
	}
	this->poLightColor = new Vect(LightColor);
	this->poLightPos = new Vect(LightPos);
	assert(poLightColor);
	assert(poLightPos);
}

GraphicsObject_TextureLight::GraphicsObject_TextureLight(Model* const Model, const ShaderObject* const pShaderObj, Texture::Name _name, Vect& LightColor, Vect& LightPos)
	: GraphicsObject(Model, pShaderObj),
	textName(_name)
{
	this->poLightColor = new Vect(LightColor);
	this->poLightPos = new Vect(LightPos);
	assert(poLightColor);
	assert(poLightPos);
}

GraphicsObject_TextureLight::~GraphicsObject_TextureLight()
{
	delete this->poLightColor;
	delete this->poLightPos;
}

void GraphicsObject_TextureLight::SetState()
{
	glActiveTexture(GL_TEXTURE0);

	// Bind the texture
	GLuint textureID = TextureMan::FindHash(this->GetMesh()->hash);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
}

void GraphicsObject_TextureLight::SetDataGPU()
{
	// use this shader
	this->pShaderObj->SetActive();

	// set the vao
	glBindVertexArray(this->GetMesh()->vao);

	Camera *pCam = CameraMan::GetCurrent(Camera::Type::PERSPECTIVE_3D);

	Matrix world = this->GetWorld();
	Matrix view = pCam->getViewMatrix();
	Matrix proj = pCam->getProjMatrix();

	glUniformMatrix4fv(this->pShaderObj->GetLocation("proj_matrix"), 1, GL_FALSE, (float *) &proj);
	glUniformMatrix4fv(this->pShaderObj->GetLocation("view_matrix"), 1, GL_FALSE, (float *) &view);
	glUniformMatrix4fv(this->pShaderObj->GetLocation("world_matrix"), 1, GL_FALSE, (float *) &world);

	Vect light = *this->poLightPos;
	Vect color = *this->poLightColor;
	glUniform3fv(this->pShaderObj->GetLocation("vLightPos"), 1, (float *) &light);
	glUniform4fv(this->pShaderObj->GetLocation("vColor"), 1, (float *) &color);
}

void GraphicsObject_TextureLight::Draw()
{
	//The starting point of the IBO index buffer object
	glDrawElements(GL_TRIANGLES, 3 * this->GetMesh()->numTris, GL_UNSIGNED_INT, 0);
}

void GraphicsObject_TextureLight::RestoreState()
{
	// undo the states you corrupted
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
}

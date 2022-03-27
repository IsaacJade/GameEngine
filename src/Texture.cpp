#include "Texture.h"
#include "StringThis.h"

Texture::Texture()
	: name(Name::NOT_INITIALIZED),
	textureID(0),
	minFilter(GL_LINEAR),
	magFilter(GL_LINEAR),
	wrapModeS(GL_CLAMP_TO_EDGE),
	wrapModeT(GL_CLAMP_TO_EDGE)
{
	memset(this->assetName, 0, TEXTURE_ASSET_NAME_SIZE);
}


Texture::~Texture()
{

}


void Texture::Set(
	const char *const _assetName,
	Name _name,
	GLuint _TextureID,
	GLenum _minFilter,
	GLenum _magFilter,
	GLenum _wrapModeS,
	GLenum _wrapModeT,
	unsigned int _width,
	unsigned int _height,
	unsigned int _hash)
{
	memcpy(this->assetName, _assetName, TEXTURE_ASSET_NAME_SIZE - 1);
	this->name = _name;
	this->magFilter = _magFilter;
	this->minFilter = _minFilter;
	this->wrapModeS = _wrapModeS;
	this->wrapModeT = _wrapModeT;
	this->textureID = _TextureID;
	this->width = _width;
	this->height = _height;
	this->hash = _hash;
}

bool Texture::Compare(DLink *pTarget)
{
	// This is used in ManBase.Find() 
	assert(pTarget != nullptr);

	Texture *pDataB = (Texture *) pTarget;

	bool status = false;

	if(this->name == pDataB->name || this->hash == pDataB->hash)
	{
		status = true;
	}

	return status;
}

void Texture::Dump()
{
	Trace::out("      Texture(%p)\n", this);

	// Data:
	Trace::out("      Name: %s \n", StringMe(this->name));
	//Trace::out("         x: %d \n", this->x);

	DLink::Dump();
}

void Texture::Wash()
{
	this->name = Name::NOT_INITIALIZED;
	this->hash = 0;
}

const char *Texture::GetName()
{
	// todo - Hack understand why is this needed for print and fix...
	static char pTmp[128];
	strcpy_s(pTmp, 128, StringMe(this->name));
	return pTmp;
}

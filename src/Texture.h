#ifndef TEXTURE_H
#define TEXTURE_H

#include "sb7.h"
#include "DLink.h"

class Texture : public DLink
{
public:
	static const unsigned int TEXTURE_ASSET_NAME_SIZE = 64;

public:
	enum class Name
	{
		HOT_PINK,
		INVADERS,
		STONES,
		RED_BRICK,
		DUCKWEED,
		ROCKS,
		CRATE,
		BONE_2,
		FONT,
		PROTO_LOAD,
		R2D2,
		CHICKEN_BOT,
		MOUSEY,
		DEFAULT,
		NOT_INITIALIZED
	};

public:
	Texture();
	virtual ~Texture() override;

	void Set(const char *const _assetName,
		Name _name,
		GLuint _TextureID,
		GLenum minFilter,
		GLenum magFilter,
		GLenum wrapModeS,
		GLenum wrapModeT,
		unsigned int width,
		unsigned int height,
		unsigned int hash);


	virtual const char *GetName() override;
	virtual bool Compare(DLink *pTarget) override;
	virtual void Dump() override;
	virtual void Wash() override;

private:
	char assetName[TEXTURE_ASSET_NAME_SIZE];

public:
	Name name;
	unsigned int hash;
	GLuint textureID;
	GLenum minFilter;
	GLenum magFilter;
	GLenum wrapModeS;
	GLenum wrapModeT;
	unsigned int    width;
	unsigned int    height;
};

#endif


#ifndef TEXTURE_DATA_OPEN_GL_H
#define TEXTURE_DATA_OPEN_GL_H

#include "textureData.h"
#include "sb7.h"

class textureDataOpenGL
{
public:
	
	static GLenum Get(textureData::TEXTURE_WRAP w);
	static GLenum Get(textureData::TEXTURE_MIN_FILTER min);
	static GLenum Get(textureData::TEXTURE_MAG_FILTER min);

};

#endif


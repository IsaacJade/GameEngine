#ifndef STRING_THIS_H
#define STRING_THIS_H

#include "Texture.h"
#include "Mesh.h"
#include "ShaderObject.h"

class StringThis
{
public:
	static const unsigned int BUFFER_SIZE = 64;
public:

	StringThis(Texture::Name);
	StringThis(Mesh::Name);
	StringThis(ShaderObject::Name);

	operator char *();

	// data:
	char buffer[BUFFER_SIZE];
};

#define StringMe(x)  ((char *)StringThis(x)) 

#endif

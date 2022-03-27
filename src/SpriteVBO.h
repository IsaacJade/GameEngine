#ifndef SPRITE_VBO_H
#define SPRITE_VBO_H

namespace Azul
{
	struct Vert_xyz
	{
		float x;
		float y;
		float z;
	};

	struct Vert_uv
	{
		float u;
		float v;
	};

	struct Vert_xyzuv
	{
		float x;
		float y;
		float z;
		float u;
		float v;
	};

	struct Tri_index
	{
		unsigned int v0;
		unsigned int v1;
		unsigned int v2;
	};
}

#endif


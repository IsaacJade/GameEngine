#ifndef SPRITE_MODEL_H
#define SPRITE_MODEL_H

#include "Mesh.h"

namespace Azul
{
	class SpriteMesh : public Mesh
	{
	public:
		SpriteMesh(const char *const modelFileName);
		~SpriteMesh();

		// tells the compiler do not create or allow it to be used, c++11
		SpriteMesh(const SpriteMesh &) = delete;
		SpriteMesh &operator=(const SpriteMesh &other) = delete;

	private:
		void privCreateVAO(const char *const modelFileName);

	};
}

#endif
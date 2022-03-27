
#ifndef BONE_H
#define BONE_H

#include "MathEngine.h"

namespace Azul
{
	struct Bone : public Align16
	{
		Bone();
		Bone(const Bone &) = default;
		Bone &operator = (const Bone &);
		~Bone() = default;

		Vect  T;
		Quat  Q;
		Vect  S;
	};
}

#endif


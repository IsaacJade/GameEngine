
#include "Bone.h"

namespace Azul
{
	Bone::Bone()
		: T(0.0f, 0.0f, 0.0f, 1.0f),
		Q(0.0f, 0.0f, 0.0f, 1.0f),
		S(1.0f, 1.0f, 1.0f, 1.0f)
	{

	}
	Bone& Bone::operator=(const Bone& r)
	{
		this->Q = r.Q;
		this->S = r.S;
		this->T = r.T;
		return *this;
	}
}


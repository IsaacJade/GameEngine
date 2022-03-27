
#ifndef MIXER_H
#define MIXER_H

#include "AnimTimer.h"
#include "Bone.h"

namespace Azul
{
	class SSBO;
	class Mixer
	{
	public:
		static void Blend(	SSBO *pResult,
							 SSBO *pA,
							 SSBO *pB,
							const float tS,
							const int numBones);
	};
}

#endif


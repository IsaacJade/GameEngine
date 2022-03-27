#ifndef ANIM_H
#define ANIM_H

#include "AnimTimer.h"
#include "MathEngine.h"
#include "GameObjectAnimSkeleton.h"
#include "Clip.h"
#include "Skeleton.h"

namespace Azul
{
	class Anim
	{
	public:
		Anim(Clip* p_clip, int _numClip, int numbone);
		Anim(const Anim&) = delete;
		Anim& operator =(const Anim&) = delete;
		~Anim();
		void SetNext(int i);
		void SwitchCurNext();
		void Animate(AnimTime tCurr, SSBO* pResultBone);
		void Blending(AnimTime tCurr, AnimTime tNext, float tBlend, SSBO* pResultBOne);
		AnimTime FindMaxTime(int index);
		AnimTime CurMaxTime();
		int GetCurFrameCount();

	private:
		Clip* pClipHead;
		Clip* pCurClip;
		Clip* pNextClip;
		SSBO* pTmpBoneA;
		SSBO* pTmpBoneB;
		int numBone;
		int numClip;

		AnimTime* pTimeArr;
	};
}
#endif

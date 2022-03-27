#ifndef ANIM_CONTROLLER_H
#define ANIM_CONTROLLER_H

#include "TimerController.h"
#include "GameObjectAnim.h"
#include "Anim.h"

namespace Azul
{
	class AnimController
	{
		enum State
		{
			Normal,
			Blending
		};
	public:
		AnimController(AnimTime delta, const Vect& trans,const Quat& quat,const Vect& scale, Model* p_model, Texture::Name name, int _numClip);
		AnimController(const AnimController &) = delete;
		AnimController &operator = (const AnimController &) = delete;
		~AnimController();
		Anim* GetAnim();
		void PlayPause();
		void RateReverse();
		void Fast();
		void slow();
		void SwitchClip(int i);
		void BlendClip(int i, float timeInSecond);
		void Update();
		int GetFrameCount();
	private:
		void privNormalUpdate();
		void privBlendUpdate();
		void privSwapClip();

	private:
		bool play = true;
		TimerController *poCurControl;
		TimerController* poNextControl;
		TimerController* poBlendControl;
		Anim *poAnim;
		SSBO* pSSBOBoneArr;
		Skeleton* pSkel;
		State state;
		int curIndex;

	};
}

#endif


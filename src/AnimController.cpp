
#include "AnimController.h"
#include "Anim.h"
#include "Model.h"

namespace Azul
{
	AnimController::AnimController(AnimTime delta, const Vect& trans, const Quat& quat, const Vect& scale, Model* p_model,
	                               Texture::Name name, int _numClip)
	{
		// SSBO Bone arry initialize, Used by skeleton
		this->pSSBOBoneArr = new SSBO();
		auto tmp = new Bone[p_model->BoneCount + 1]();
		this->pSSBOBoneArr->Set(p_model->BoneCount + 1, sizeof(Bone), tmp);
		delete[] tmp;


		this->pSkel = p_model->InitSkeleton();
		pSkel->SetWithTrans(pSSBOBoneArr, trans, quat, scale, name);
		// Animation object
		this->poAnim = new Anim(p_model->p_clip, _numClip, p_model->BoneCount);
		assert(this->poAnim);

		// TimerController
		AnimTime maxTime = poAnim->CurMaxTime();
		AnimTime timeZero = AnimTime(AnimTime::Duration::ZERO);
		auto minTime = AnimTime(AnimTime::Duration::ZERO);
		this->poCurControl = new TimerController(delta, minTime, maxTime);
		this->poCurControl->SetLoop(true);
		this->poNextControl = new TimerController(delta, timeZero, timeZero);
		this->poNextControl->SetLoop(true);
		this->poBlendControl = new TimerController(delta, timeZero, timeZero);
		this->poBlendControl->SetLoop(false);
		assert(this->poCurControl);
		this->state = State::Normal;
		this->curIndex = 0;
	}

	AnimController::~AnimController()
	{
		delete poAnim;
		delete poCurControl;
		delete poNextControl;
		delete poBlendControl;
		delete pSSBOBoneArr;
		delete pSkel;
	}

	Anim* AnimController::GetAnim()
	{
		assert(this->poAnim);

		return this->poAnim;
	}

	void AnimController::PlayPause()
	{
		play = !play;
	}


	void AnimController::RateReverse()
	{
		this->poCurControl->ReverseRate();
		this->poNextControl->ReverseRate();
	}


	void AnimController::Fast()
	{
		this->poCurControl->Faster2();
		this->poNextControl->Faster2();
	}

	void AnimController::slow()
	{
		this->poCurControl->Slower2();
		this->poNextControl->Slower2();
	}

	void AnimController::SwitchClip(int i)
	{
		this->poAnim->SetNext(i);
		this->poAnim->SwitchCurNext();
		this->poCurControl->SetMaxTime(this->poAnim->CurMaxTime());
	}

	void AnimController::BlendClip(int i, float timeInSecond)
	{
		if (this->state != State::Blending && curIndex != i)
		{
			printf("Blending start\n");
			this->state = Blending;
			curIndex = i;
			this->poAnim->SetNext(i);
			this->poNextControl->Reset(AnimTime(AnimTime::Duration::ZERO), this->poAnim->FindMaxTime(i));
			this->poBlendControl->Reset(AnimTime(AnimTime::Duration::ZERO), AnimTime(AnimTime::Duration::ONE_SECOND) * timeInSecond);
		}
	}

	void AnimController::Update()
	{
		if (this->state == State::Normal)
		{
			this->privNormalUpdate();
		}else
		{
			this->privBlendUpdate();
		}
	}
	int AnimController::GetFrameCount()
	{
		return this->poAnim->GetCurFrameCount();
	}
	void AnimController::privNormalUpdate()
	{
		if (!play)
		{
			return;
		}
		this->poCurControl->Update();

		// interpolate all bones
		this->poAnim->Animate(this->poCurControl->GetCurrTime(), pSSBOBoneArr);
	}
	void AnimController::privBlendUpdate()
	{
		if (!play)
		{
			return;
		}
		this->poCurControl->Update();
		this->poNextControl->Update();
		this->poBlendControl->Update();
		float tS = this->poBlendControl->GetCurrTime() / this->poBlendControl->GetMaxTime();

		this->poAnim->Blending(this->poCurControl->GetCurrTime(), this->poNextControl->GetCurrTime(), tS, pSSBOBoneArr);

		if (this->poBlendControl->IsEnd())
		{
			printf("Blending over\n");
			this->state = State::Normal;
			this->privSwapClip();
		}

	}
	void AnimController::privSwapClip()
	{
		TimerController* tmp = this->poNextControl;
		this->poNextControl = this->poCurControl;
		this->poCurControl = tmp;

		this->poAnim->SwitchCurNext();
	}
}


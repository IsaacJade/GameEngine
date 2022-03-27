
#include "Anim.h"
#include "Constants.h"
#include "MathEngine.h"
#include "MathApp.h"
#include "Mixer.h"
#include "Clip.h"
#include "SSBO.h"

namespace Azul
{
	Anim::Anim(Clip* p_clip, int _numClip, int numbone)
		: pClipHead(nullptr),
		  pCurClip(nullptr),
		  pNextClip(nullptr),
		  pTmpBoneA(nullptr),
		  pTmpBoneB(nullptr),
		  numBone(numbone),
		  numClip(_numClip),
		  pTimeArr(nullptr)
	{
		// create tmp ssbo buffer
		this->pTmpBoneA = new SSBO();
		this->pTmpBoneB = new SSBO();
		auto tmp = new Bone[numBone + 1]();
		this->pTmpBoneA->Set(numBone + 1, sizeof(Bone), tmp);
		this->pTmpBoneB->Set(numBone + 1, sizeof(Bone), tmp);
		delete[] tmp;

		// Get this from the AnimMan
		this->pCurClip = p_clip;
		this->pClipHead = p_clip;
		assert(pCurClip);

		pTimeArr = new AnimTime[numClip];
		Clip* head = pClipHead;
		unsigned int i = 0;
		while (head)
		{
			pTimeArr[i++] = head->GetTotalTime();
			head = head->nextClip;
		}
	}

	Anim::~Anim()
	{
		delete pTmpBoneA;
		delete pTmpBoneB;
		delete[] pTimeArr;
	}

	void Anim::SetNext(int index)
	{
		assert(pCurClip);
		assert(pClipHead);
		if (index < numClip)
		{
			pNextClip = pClipHead;
			for (int i = 0; i < index; ++i)
			{
				pNextClip = pNextClip->nextClip;
			}
		}
		//nextMaxTime = pClip->GetTotalTime();
	}

	void Anim::SwitchCurNext()
	{
		this->pCurClip = pNextClip;
		this->pNextClip = nullptr;
	}

	AnimTime Anim::FindMaxTime(int index)
	{
		assert(index < numClip);
		return this->pTimeArr[index];
	}

	AnimTime Anim::CurMaxTime()
	{
		return pCurClip->GetTotalTime();
	}

	int Anim::GetCurFrameCount()
	{
		return this->pCurClip->GetNumFramse();
	}

	void Anim::Animate(AnimTime tCurr, SSBO* pResultBone)
	{
		this->pCurClip->AnimateBones(tCurr, pResultBone);
	}

	void Anim::Blending(AnimTime tCurr, AnimTime tNext, float tBlend, SSBO* pResultBOne)
	{
		assert(pCurClip);
		assert(pNextClip);
		this->pCurClip->AnimateBones(tCurr, pTmpBoneA);
		this->pNextClip->AnimateBones(tNext, pTmpBoneB);
		Mixer::Blend(pResultBOne, pTmpBoneA, pTmpBoneB, tBlend, numBone);
	}
}


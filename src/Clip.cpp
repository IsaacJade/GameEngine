
#include "Clip.h"

#include "animData.h"
#include "AnimTime.h"
#include "Bone.h"
#include "Mixer.h"

namespace Azul
{
	Clip::Clip(std::vector<animData>& clips, int _numbones)
	:nextClip(nullptr),
	prevClip(nullptr),
	numBones(_numbones),
	numFrames(clips.size()),
	TotalTime(AnimTime::Duration::ZERO),
	poHead(nullptr)
	{

		this->privSetClip(clips);
		this->TotalTime = this->privFindMaxTime();
		this->numFrames = (int)clips.size();


		Bone* pBoneResult = new Bone[numBones]();


		delete[] pBoneResult;
	}

	Clip::~Clip()
	{
		FrameBucket *pTmp = poHead;

		while (pTmp != nullptr)
		{
			FrameBucket *pDeleteMe = pTmp;
			pTmp = pTmp->nextBucket;
			delete pDeleteMe;
		}
	}

	void Clip::AnimateBones(AnimTime tCurr, SSBO *pResult)
	{
		// First one 
		FrameBucket *pTmp = this->poHead;

		// Find which key frames
		while(tCurr >= pTmp->KeyTime && pTmp->nextBucket != nullptr)
		{
			pTmp = pTmp->nextBucket;
		}

		// pTmp is the "B" key frame
		// pTmp->prev is the "A" key frame
		FrameBucket *pA = pTmp->prevBucket;
		FrameBucket *pB = pTmp;

		// find the "S" of the time
		float tS = (tCurr - pA->KeyTime) / (pB->KeyTime - pA->KeyTime);

		Mixer::Blend(pResult, pA->pSSBO, pB->pSSBO, tS, this->numBones);

	}

	void Clip::privSetClip(std::vector<animData>& clips)
	{
		//// --------  Frame i  ----------------------------
		//for (auto element : clips)
		//{
		//	Trace::out("\n\n");
		//	Trace::out("----------------------------------\n");
		//	for (unsigned int i = 0; i < element.vectorBone.size(); i++)
		//	{
		//		Bone* pCompute = &element.vectorBone[i];

		//		Trace::out("\n");
		//		Trace::out("[%2d], Time: %+ 5.3f\n", i, element.time);
		//		Trace::out("  T: %+ 5.3f %+ 5.3f %+ 5.3f %+ 5.3f   \n",
		//		           pCompute->T[x], pCompute->T[y], pCompute->T[z], pCompute->T[w]);
		//		Trace::out("  Q: %+ 5.3f %+ 5.3f %+ 5.3f %+ 5.3f   \n",
		//		           pCompute->Q[x], pCompute->Q[y], pCompute->Q[z], pCompute->Q[w]);
		//		Trace::out("  S: %+ 5.3f %+ 5.3f %+ 5.3f %+ 5.3f   \n",
		//		           pCompute->S[x], pCompute->S[y], pCompute->S[z], pCompute->S[w]);
		//	}
		//}

		FrameBucket* pTmp = nullptr;
		FrameBucket* pTmpX = nullptr;
		Bone* poBone;
		// Keyframe: 0  time: 0.000000 seconds

		pTmpX = new FrameBucket();
		pTmpX->prevBucket = pTmp;
		pTmpX->nextBucket = nullptr;
		pTmpX->KeyTime = clips[0].frameIndex * AnimTime(AnimTime::Duration::FILM_24_FRAME);
		pTmpX->pSSBO = new SSBO();
		poBone = new Bone[(unsigned int)this->numBones];
		//pTmp->nextBucket = pTmpX;
		this->poHead = pTmpX;

		pTmp = pTmpX;
		// Possible error in bone no 
		for (int i = 0; i < numBones; ++i)
		{
			
			poBone[i].T = clips[0].vectorBone[i].T;
			poBone[i].Q = clips[0].vectorBone[i].Q;
			poBone[i].S = clips[0].vectorBone[i].S;

		}
		pTmpX->pSSBO->Set(this->numBones, sizeof(Bone), poBone);

		for (unsigned int i = 1; i < clips.size(); ++i)
		{
			pTmpX = new FrameBucket();
			pTmpX->prevBucket = pTmp;
			pTmpX->nextBucket = nullptr;
			pTmpX->KeyTime = clips[i].frameIndex * AnimTime(AnimTime::Duration::FILM_24_FRAME);
			pTmpX->pSSBO = new SSBO();
			pTmp->nextBucket = pTmpX;

			pTmp = pTmpX;

			// Bone: 0 
			for (int j = 0; j < numBones; ++j)
			{
				poBone[j].T = clips[i].vectorBone[j].T;
				poBone[j].Q = clips[i].vectorBone[j].Q;
				poBone[j].S = clips[i].vectorBone[j].S;
			}
			pTmpX->pSSBO->Set(this->numBones, sizeof(Bone), poBone);
		}
		delete[] poBone;
		
	}

	int Clip::privFindNumFrames()
	{
		int count = 0;
		FrameBucket *pTmp = this->poHead;

		while (pTmp->nextBucket != nullptr)
		{
			count++;
			pTmp = pTmp->nextBucket;
		}
		return count;
	}

	AnimTime Clip::privFindMaxTime()
	{
		AnimTime tMax;
		FrameBucket *pTmp = this->poHead;

		while (pTmp->nextBucket != nullptr)
		{
			pTmp = pTmp->nextBucket;
		}

		tMax = pTmp->KeyTime;

		return tMax;
	}

	AnimTime Clip::GetTotalTime()
	{
		return this->TotalTime;
	}

	int Clip::GetNumFramse()
	{
		return this->numFrames;
	}


}


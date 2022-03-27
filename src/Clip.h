#ifndef CLIP_H
#define CLIP_H

#include <vector>

#include "AnimTime.h"
#include "Bone.h"
#include "SSBO.h"

class animData;

namespace Azul
{

	class Clip
	{
	public:

		struct FrameBucket
		{
			~FrameBucket()
			{
				delete pSSBO;
			}

			FrameBucket *nextBucket;
			FrameBucket *prevBucket;
			AnimTime      KeyTime;
			SSBO         *pSSBO;
			char          pad[4];
		};

	public:
		Clip(std::vector<animData>& clips, int _numbones);

		Clip() = delete;
		Clip(const Clip &) = delete;
		Clip &operator = (const Clip &) = delete;
		~Clip();

		AnimTime GetTotalTime();
		int GetNumFramse();
		void AnimateBones(AnimTime tCurr, SSBO *pResult);

		Clip* nextClip;
		Clip* prevClip;

	private:
		void privSetClip(std::vector<animData>& clips);
		AnimTime privFindMaxTime();
		int  privFindNumFrames();

	private:
		int          numBones;
		int          numFrames;
		AnimTime     TotalTime;
		FrameBucket *poHead;
	};
}

#endif


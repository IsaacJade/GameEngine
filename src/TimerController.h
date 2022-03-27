#ifndef TIMER_CONTROLLER_H
#define TIMER_CONTROLLER_H

#include "AnimTimer.h"

namespace Azul
{
	class TimerController
	{
	public:
		TimerController(AnimTime Delta, AnimTime Min, AnimTime Max, float _rate = 1.0f);

		TimerController() = delete;
		TimerController(const TimerController &) = delete;
		TimerController &operator = (const TimerController &) = delete;
		~TimerController() = default;

		void Update();

		void SetCurrTime(const AnimTime time);
		AnimTime GetCurrTime() const;

		void SetDeltaTime(const AnimTime time);
		AnimTime GetDeltaTime() const;

		void SetMaxTime(const AnimTime time);
		AnimTime GetMaxTime() const;

		void SetMinTime(const AnimTime time);
		AnimTime GetMinTime() const;

		bool IsEnd() const;
		void SetLoop(bool bLoop);

		void SetRate(float newRate);
		void Faster2();
		void Slower2();
		void ResetRate();
		void ReverseRate();

		void Reset(AnimTime Min, AnimTime Max);
		void Reset();

	private:
		void Update_Loop();
		void Update_Normal();

	private:
		AnimTime tCurr;
		AnimTime tDelta;
		AnimTime tMax;
		AnimTime tMin;

		float rate;
		bool isEnd;
		bool isLooping;
	};
}

#endif


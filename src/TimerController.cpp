#include "TimerController.h"

namespace Azul
{

	TimerController::TimerController(AnimTime Delta, AnimTime Min, AnimTime Max, float _rate)
		: tCurr(AnimTime::Duration::ZERO),
		tDelta(Delta),
		tMax(Max),
		tMin(Min),
		rate(_rate),
		isEnd(false),
		isLooping(true)
	{
	}

	void TimerController::Update()
	{
		if (this->isLooping)
		{
			this->Update_Loop();
		}
		else
		{
			this->Update_Normal();
		}
	}

	void TimerController::Update_Loop()
	{
		this->isEnd = false; // Just for save

		tCurr += (rate * tDelta);

		if (tCurr > tMax)
		{
			tCurr = tMin;
		}
		else if (tCurr < tMin)
		{
			tCurr = tMax;
		}
		else
		{
			//
		}
	}

	void TimerController::Update_Normal()
	{
		if (!this->isEnd)
		{
			tCurr += (rate * tDelta);

			if (tCurr > tMax)
			{
				tCurr = tMax;

				this->isEnd = true;
			}
			else if (tCurr < tMin)
			{
				tCurr = tMin;

				this->isEnd = true;
			}
			else
			{
				//
			}
		}
	}
	void TimerController::Reset(AnimTime Min, AnimTime Max)
	{
		this->tMin = Min;
		this->tMax = Max;

		this->Reset();
	}

	void TimerController::Reset()
	{
		this->isEnd = false;

		if (rate < 0.0f)
		{
			this->tCurr = this->tMax;
		}
		else
		{
			this->tCurr = this->tMin;
		}
	}

	void TimerController::SetRate(float newRate)
	{
		this->rate = newRate;
	}

	void TimerController::Faster2()
	{
		this->rate *= 2.0f;
	}

	void TimerController::Slower2()
	{
		this->rate *= 0.5f;
	}

	void TimerController::ResetRate()
	{
		this->rate = 1.0f;
	}

	void TimerController::ReverseRate()
	{
		this->rate = -this->rate;
	}

	void TimerController::SetCurrTime(const AnimTime time)
	{
		this->tCurr = time;
	}

	AnimTime TimerController::GetCurrTime() const
	{
		return this->tCurr;
	}

	void TimerController::SetDeltaTime(const AnimTime time)
	{
		this->tDelta = time;
	}

	AnimTime TimerController::GetDeltaTime() const
	{
		return this->tDelta;
	}

	void TimerController::SetMaxTime(const AnimTime time)
	{
		this->tMax = time;
	}

	AnimTime TimerController::GetMaxTime() const
	{
		return this->tMax;
	}

	void TimerController::SetMinTime(const AnimTime time)
	{
		this->tMin = time;
	}

	AnimTime TimerController::GetMinTime() const
	{
		return this->tMin;
	}

	bool TimerController::IsEnd() const
	{
		return this->isEnd;
	}

	void TimerController::SetLoop(bool bLoop)
	{
		this->isLooping = bLoop;

		if (this->isLooping == true)
		{
			this->isEnd = false;
		}
	}

}


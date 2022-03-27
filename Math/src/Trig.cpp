#include <math.h>    // <--- ONLY location for <math.h> allowed
#include "Trig.h"

namespace Azul
{

	// Do your magic here
	float Trig::cos(const float& x)
	{
		return cosf(x);
	}
	float Trig::sin(const float& x)
	{
		return sinf(x);
	}
	float Trig::tan(const float& x)
	{
		return tanf(x);
	}
	float Trig::atan(const float& x)
	{
		return atanf(x);
	}
	float Trig::atan2(const float& x, const float& y)
	{
		return atan2f(x, y);
	}
	float Trig::acos(const float& x)
	{
		return acosf(x);
	}
	float Trig::asin(const float& x)
	{
		return asinf(x);
	}
	void Trig::cossin(float& x, float& y, const float& z)
	{
		x = cosf(z);
		y = sinf(z);
	}
	float Trig::sqrt(const float& x)
	{
		return sqrtf(x);
	}
	float Trig::rsqrt(const float& x)
	{
		return sqrtf(1 / x);
	}
}


#ifndef ENGINE_MATH_TRIG_H
#define ENGINE_MATH_TRIG_H

namespace Azul
{
	class Trig
	{
	public:

		// Do your magic here
		static float cos(const float& x);
		static float sin(const float& x);
		static float tan(const float& x);
		static float atan(const float& x);
		static float atan2(const float& x, const float& y);
		static float acos(const float& x);
		static float asin(const float& x);
		static void cossin(float& x, float& y, const float& z);
		static float sqrt(const float& x);
		static float rsqrt(const float& x);
	};
}

#endif


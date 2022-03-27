#include "MathEngine.h"
#include "MathApp.h"

//----------------------------------------------------------------------------- 
// Mutates result to be a slerp between the source and target by the
// specified factor.
// For a factor of 0.0, result == source.
// For a factor of 1.0, result == target.
//----------------------------------------------------------------------------- 

namespace Azul
{
	void QuatApp::Slerp(Quat &result, const Quat & source, const Quat & target, const float slerpFactor)
	{
		Quat src = source.getNorm();
		Quat tar = target.getNorm();

		float dot = src.dot(tar);

		if (dot < 0.0f)
		{
			tar = -tar;
			dot = -dot;
		}

		float DOT_THRESHOLD = 1 - MATH_TOLERANCE;

		if (dot > DOT_THRESHOLD)
		{
			result = src + slerpFactor * (tar - src);
			result.norm();
		}
		else
		{
			float theta_0 = Trig::acos(dot);
			float theta = theta_0 * slerpFactor;
			float sin_theta = Trig::sin(theta);
			float sin_theta_0 = Trig::sin(theta_0);

			float s0 = Trig::cos(theta) - dot * sin_theta / sin_theta_0;
			float s1 = sin_theta / sin_theta_0;

			result = s0 * src + s1 * tar;
		}

	};

	void QuatApp::SlerpArray(Quat *out, const Quat *source, const Quat *target, const float slerpFactor, const int numQuats)
	{
		for (int i = 0; i < numQuats; i++)
		{
			Slerp(out[i], source[i], target[i], slerpFactor);
		}
	};
}


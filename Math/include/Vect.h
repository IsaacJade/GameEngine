#ifndef ENGINE_MATH_VECT_H
#define ENGINE_MATH_VECT_H

// Includes to handle SIMD register types
#include <xmmintrin.h>
#include <smmintrin.h> 

#include "Constants.h"
#include "Debug.h"

// This file assumes Framework.h is included in executable for Align16

namespace Azul
{
	// forward declare
	class Matrix;
	class Quat;

	class Vect final : public Align16
	{
	public:

		Vect();
		Vect(const Vect&); //copy constructor
		//Vect& operator(const Vect& ) = default;
		Vect(float x, float y, float z, float w = 1.0f);
		~Vect() = default;

		const Vect& operator=(const Vect & rhs);
		Vect operator *= (const float t);

		Vect operator + (const Vect & t) const;
		Vect operator += (const Vect & t);
		Vect operator - (const Vect & t) const;
		Vect operator -= (const Vect & t);
		Vect operator * (const float s) const;
		friend Vect operator * (const float s, const Vect & v);
		Vect operator * (const Matrix&  m) const;
		Vect operator *= (const Matrix & m);

		Vect operator * (const Quat& q) const;
		Vect operator *= (const Quat& q);

		//Unary Operator
		Vect operator + ();
		Vect operator - ();

		bool isEqual(const Vect & b, float t = MATH_TOLERANCE) const;
		bool isZero(float t = MATH_TOLERANCE) const;

		float& operator[](const enum x_enum);
		float& operator[](const enum y_enum);
		float& operator[](const enum z_enum);
		float& operator[](const enum w_enum);

		const float operator[](const enum x_enum) const;
		const float operator[](const enum y_enum) const;
		const float operator[](const enum z_enum) const;
		const float operator[](const enum w_enum) const;

		float& x();
		float& y();
		float& z();
		float& w();

		const float& x() const;
		const float& y() const;
		const float& z() const;
		const float& w() const;

		friend static void Debug::Print(const char* pName, const Vect & r);

		void set(float x, float y, float z, float w = 1.0f);
		void set(Vect v);

		const float dot(const Vect& v) const;
		const Vect cross(const Vect& v) const;
		Vect& norm();
		Vect getNorm() const;
		const float mag() const;
		const float magSqr() const;
		const float getAngle(const Vect& v) const;

		// for printing
		friend void Debug::Print(const char *pName, const Vect &r);

	private:

		union
		{
			__m128	_mv;

			// anonymous struct
			struct
			{
				float _vx;
				float _vy;
				float _vz;
				float _vw;
			};
		};
	};
}

#endif

#ifndef ENGINE_MATH_QUAT_H
#define ENGINE_MATH_QUAT_H

#include "Matrix.h"
#include "Debug.h"

//------------------------------------------------------------------------
// 
//  This class contains functions and data structure for a 4-dimensional
//  Quaternions.  The quaternions are internally stored interms of the
//  imaginary components (x,y,z) and the real components (real).
// 
//  In the Math library, quaternions can be thought of as "rotational"
//  matrices, everything that you can represent with rotational matrices
//  you can use with quaternions.  Such as quaternion concatenation,
//  inverses, transpose, normalize, multiplying with matrices, and with
//  vectors.
// 
//------------------------------------------------------------------------
namespace Azul
{
	class Quat final : public Align16
	{
	public:
		enum class Rot1
		{
			X,
			Y,
			Z
		};

		enum class Special
		{
			Zero,
			Identity
		};

		enum class Rot
		{
			AxisAngle,
		};

		enum class Orient
		{
			LocalToWorld,
			WorldToLocal
		};

		enum class Rot3
		{
			XYZ
			// future combos... here
		};

	public:

		Quat();
		Quat(const Quat&); //copy constructor
		Quat(float qx, float qy, float qz, float qw);
		Quat(Vect v, float real);
		Quat(Matrix M);
		Quat(Special sp);
		Quat(Rot1, float);
		Quat(Rot3, float x, float y, float z);
		Quat(Rot, Vect& v, float angle);
		Quat(Orient, Vect v1, Vect v2);
		~Quat() = default;
		Quat& operator=(const Quat & rhs);

		//set
		void set(float qx, float qy, float qz, float qw);
		void set(Vect& v, float real);
		void set(Matrix M);
		void set(Special sp);
		void set(Rot1,float);
		void set(Rot3, float x, float y, float z);
		void set(Rot, Vect v, float angle);
		void set(Orient, Vect v1, Vect v2);
		void setVect(Vect&);

		//accessor
		float& operator[](x_enum);
		float& operator[](y_enum);
		float& operator[](z_enum);
		float& operator[](w_enum);

		float operator[](x_enum) const;
		float operator[](y_enum) const;
		float operator[](z_enum) const;
		float operator[](w_enum) const;

		float& qx();
		float& qy();
		float& qz();
		float& real();

		const float& qx() const;
		const float& qy() const;
		const float& qz() const;
		const float& real() const;

		void getVect(Vect&) const;

		//Calculations
		Quat operator * (const Quat& rhs) const;
		Quat operator *= (const Quat& rhs);
		Quat operator + (const Quat& t) const;
		Quat operator += (const Quat& t);
		Quat operator - (const Quat& t) const;
		Quat operator -= (const Quat& t);
		Quat operator / (const Quat& t) const;
		Quat operator /= (const Quat& t);

		Quat operator + (const float t) const;
		Quat operator += (const float t);
		Quat operator - (const float t) const;
		Quat operator -= (const float t);
		Quat operator * (const float t) const;
		Quat operator *= (const float t);
		Quat operator / (const float t) const;
		Quat operator /= (const float t);

		friend Quat operator * (float s, const Quat& v);
		friend Quat operator + (float s, const Quat& v);
		friend Quat operator - (float s, const Quat& v);
		friend Quat operator / (float s, const Quat& v);

		//friend Quat operator * (const Matrix& m, Quat& q);
		Quat operator + ();
		Quat operator - ();

		Matrix operator * (const Matrix& m) const;
		Quat operator *= (const Matrix& m);

		//Quat operator * (const Vect& m) const;
		//Quat operator *= (const Vect& m);

		const Quat multByElement(const Quat& q) const;

		//boolean
		bool isEqual(const Quat& q, float s);
		bool isNegEqual(const Quat& q, float s);
		bool isNormalized(float s);
		bool isEquivalent(const Quat& q, float s);
		bool isConjugateEqual(const Quat& q, float s);
		bool isIdentity(float s);
		bool isZero(float s);

		//Functions
		Quat getConj() const;
		void conj();
		Quat getT() const;
		void T();
		// Get Magnitude
		const float mag() const;
		float magSquared();
		float invMag();
		Quat& norm();
		// Normalize 
		Quat getNorm() const;
		Quat getInv();
		float getAngle();
		void getAxis(Vect & v);
		void inv();
		float dot(const Quat & q);
		void Lqvqc(Vect vin, Vect & vout);
		void Lqcvq(Vect vin, Vect & vout);

		// For printing
		friend void Debug::Print(const char *pName, const Quat &r);

	private:

		// anonymous union
		union
		{
			__m128	_mq;

			// anonymous struct
			struct
			{
				float _qx;
				float _qy;
				float _qz;
				float _qw;
			};
		};

	};
}

#endif 

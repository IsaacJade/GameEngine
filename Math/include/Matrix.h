#ifndef ENGINE_MATH_MATRIX_H
#define ENGINE_MATH_MATRIX_H

#include "Vect.h"
#include "Debug.h"

namespace Azul
{
	class Quat;

	class Matrix final : public Align16
	{
	public:

		enum class Special
		{
			Zero,
			Identity
		};

		enum class Rot1
		{
			X,
			Y,
			Z
		};

		enum class Trans
		{
			XYZ
		};

		enum class Scale
		{
			XYZ
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

		enum class Row
		{
			i0,
			i1,
			i2,
			i3
		};

		enum class Rot3
		{
			XYZ
			// future combos... here
		};

	public:

		Matrix();
		Matrix(const Matrix&); //copy constructor
		Matrix(const Vect& v0, const Vect& v1, const Vect& v2, const Vect& v3);
		~Matrix() = default;

		Matrix(Matrix::Special);
		Matrix(Matrix::Trans, float x, float y, float z);
		Matrix(Matrix::Trans, Vect v);
		Matrix(Matrix::Scale, float x, float y, float z);
		Matrix(Matrix::Scale, Vect v);
		Matrix(Matrix::Rot1, float);
		Matrix(Matrix::Rot3, float x, float y, float z);
		Matrix(Matrix::Rot, Vect v, float angle);
		Matrix(Matrix::Orient, Vect v1, Vect v2);
		Matrix(Quat qa);

		Matrix operator + (const Matrix & t) const;
		Matrix operator += (const Matrix & t);
		Matrix operator - (const Matrix & t) const;
		Matrix operator -= (const Matrix & t);
		Matrix operator * (const float s) const;
		Matrix operator *= (const float s);
		friend Matrix operator * (float s, const Matrix & t);

		Matrix operator * (const Matrix & rhs) const;
		Matrix operator *= (const Matrix & rhs);

		Matrix operator * (Quat& q) const;

		Matrix& operator=(const Matrix & rhs);

		//Unary Operator
		Matrix operator + ();
		Matrix operator - ();

		float det();
		void T();
		Matrix getT() const;
		void inv();
		Matrix getInv();

		float& m0();
		float& m1();
		float& m2();
		float& m3();
		float& m4();
		float& m5();
		float& m6();
		float& m7();
		float& m8();
		float& m9();
		float& m10();
		float& m11();
		float& m12();
		float& m13();
		float& m14();
		float& m15();

		const float& m0() const;
		const float& m1() const;
		const float& m2() const;
		const float& m3() const;
		const float& m4() const;
		const float& m5() const;
		const float& m6() const;
		const float& m7() const;
		const float& m8() const;
		const float& m9() const;
		const float& m10() const;
		const float& m11() const;
		const float& m12() const;
		const float& m13() const;
		const float& m14() const;
		const float& m15() const;

		float& operator[](m0_enum);
		float& operator[](m1_enum);
		float& operator[](m2_enum);
		float& operator[](m3_enum);
		float& operator[](m4_enum);
		float& operator[](m5_enum);
		float& operator[](m6_enum);
		float& operator[](m7_enum);
		float& operator[](m8_enum);
		float& operator[](m9_enum);
		float& operator[](m10_enum);
		float& operator[](m11_enum);
		float& operator[](m12_enum);
		float& operator[](m13_enum);
		float& operator[](m14_enum);
		float& operator[](m15_enum);

		float operator[](m0_enum) const;
		float operator[](m1_enum) const;
		float operator[](m2_enum) const;
		float operator[](m3_enum) const;
		float operator[](m4_enum) const;
		float operator[](m5_enum) const;
		float operator[](m6_enum) const;
		float operator[](m7_enum) const;
		float operator[](m8_enum) const;
		float operator[](m9_enum) const;
		float operator[](m10_enum) const;
		float operator[](m11_enum) const;
		float operator[](m12_enum) const;
		float operator[](m13_enum) const;
		float operator[](m14_enum) const;
		float operator[](m15_enum) const;

		void set(const Vect & v0, const Vect & v1, const Vect & v2, const Vect & v3);
		void set(Matrix::Special);
		void set(Matrix::Trans, float x, float y, float z);
		void set(Matrix::Trans, Vect v);
		void set(Matrix::Scale, float x, float y, float z);
		void set(Matrix::Scale, Vect v);
		void set(Matrix::Rot1, float);
		void set(Matrix::Row, Vect v);
		void set(Matrix::Rot3, float x, float y, float z);
		void set(Matrix::Rot, Vect v, float angle);
		void set(const Matrix::Orient, const Vect& dof, const Vect& up);
		void set(Quat q);

		Vect get(const Row type) const;

		bool isEqual(const Matrix & b, float t = MATH_TOLERANCE) const;
		bool isRotation();
		bool isIdentity(float t = MATH_TOLERANCE) const;

		friend static void Debug::Print(const char* pName, const Matrix & r);

		// For printing
		friend void Debug::Print(const char *pName, const Matrix &r);

	private:

		union
		{

			struct
			{
				Vect _rows[4];
			};


			struct
			{
				Vect _v0;
				Vect _v1;
				Vect _v2;
				Vect _v3;
			};

			struct
			{
				float _m0;
				float _m1;
				float _m2;
				float _m3;
				float _m4;
				float _m5;
				float _m6;
				float _m7;
				float _m8;
				float _m9;
				float _m10;
				float _m11;
				float _m12;
				float _m13;
				float _m14;
				float _m15;
			};
		};
	};
}

#endif
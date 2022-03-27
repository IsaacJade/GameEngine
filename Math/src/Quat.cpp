#include "MathEngine.h"
#include "Quat.h"

namespace Azul
{ 

// Do your magic here

	Quat::Quat()
		:_qx{},_qy{},_qz{},_qw(1.0f)
	{
	}

	Quat::Quat(const Quat& q)
		:_qx(q._qx),_qy(q._qy),_qz(q._qz),_qw(q._qw)
	{
	}

	Quat::Quat(float qx, float qy, float qz, float qw)
		: _qx(qx), _qy(qy), _qz(qz), _qw(qw)
	{
	}
	Azul::Quat::Quat(Vect v, float real)
		:_qx(v.x()),_qy(v.y()),_qz(v.z()),_qw(real)
	{
	}

	Quat::Quat(Matrix M)
	{
		this->set(M);
	}

	Quat::Quat(Special sp)
	{
		this->set(sp);
	}

	Quat::Quat(Rot1 r1, float f1)
	{
		this->set(r1, f1);
	}

	Quat::Quat(Rot3 r3, float x, float y, float z)
	{
		this->set(r3, x, y, z);
	}

	Quat::Quat(Rot r, Vect& v, float angle)
	{
		this->set(r, v, angle);
	}

	Quat::Quat(Orient o1, Vect v1, Vect v2)
	{
		this->set(o1, v1, v2);
	}

	Quat& Quat::operator=(const Quat& rhs)
	{
		this->_qx = rhs._qx;
		this->_qy = rhs._qy;
		this->_qz = rhs._qz;
		this->_qw = rhs._qw;
		return *this;
	}

	void Quat::set(float qx, float qy, float qz, float qw)
	{
		this->_qx = qx;
		this->_qy = qy;
		this->_qz = qz;
		this->_qw = qw;
	}

	void Quat::set(Vect& v, float real)
	{
		this->_qx = v.x();
		this->_qy = v.y();
		this->_qz = v.z();
		this->_qw = real;
	}

	void Quat::set(Matrix M)
	{
		float tr = M.m0() + M.m5() + M.m10();
		float S;
		if (tr > 0.0f)
		{
			S = 2 * sqrtf(tr + 1.0f);
			this->_qw = 0.25f * S;
			this->_qx = -(M.m9() - M.m6()) / S;
			this->_qy = -(M.m2() - M.m8()) / S;
			this->_qz = -(M.m4() - M.m1()) / S;
		}
		else if((M.m0() > M.m5()) && (M.m0() > M.m10()))
		{
			S = 2 * sqrtf(1.0f + M.m0() - M.m5() - M.m10());
			this->_qw = -(M.m9() - M.m6()) / S;
			this->_qx = 0.25f * S;
			this->_qy = (M.m1() + M.m4()) / S;
			this->_qz = (M.m2() + M.m8()) / S;
		}
		else if(M.m5() > M.m10())
		{
			S = 2 * sqrtf(1.0f + M.m5() - M.m0() - M.m10());
			this->_qw = -(M.m2() - M.m8()) / S;
			this->_qx = (M.m1() + M.m4()) / S;
			this->_qy = 0.25f * S;
			this->_qz = (M.m6() + M.m9()) / S;
		}
		else
		{
			S = 2 * sqrtf(1.0f + M.m10() - M.m0() - M.m5());
			this->_qw = -(M.m4() - M.m1()) / S;
			this->_qx = (M.m2() + M.m8()) / S;
			this->_qy = (M.m6() + M.m9()) / S;
			this->_qz = 0.25f * S;
		}
	}

	void Quat::set(Special sp)
	{
		if(sp == Special::Identity)
		{
			this->_qx = 0.0f;
			this->_qy = 0.0f;
			this->_qz = 0.0f;
			this->_qw = 1.0f;
		}else
		{
			this->_qx = 0.0f;
			this->_qy = 0.0f;
			this->_qz = 0.0f;
			this->_qw = 0.0f;
		}
	}

	void Quat::set(Rot1 r1, float f1)
	{
		if(r1 == Rot1::X)
		{
			this->_qx = Trig::sin((f1 / 2));
			this->_qy = 0.0f;
			this->_qz = 0.0f;
		}
		if(r1 == Rot1::Y)
		{
			this->_qx = 0.0f;
			this->_qy = Trig::sin((f1 / 2));
			this->_qz = 0.0f;
		}
		if(r1 == Rot1::Z)
		{
			this->_qx = 0.0f;
			this->_qy = 0.0f;
			this->_qz = Trig::sin((f1 / 2));
		}
		this->_qw = Trig::cos(f1 / 2);

	}

	void Quat::set(Rot3 r1, float x, float y, float z)
	{
		Matrix tmp((Matrix::Rot3)r1, x,y,z);
		this->set(tmp);
	}

	void Quat::set(Rot r1, Vect v, float angle)
	{
		if(r1 == Rot::AxisAngle)
		{
			float cos_a = Trig::cos(angle / 2);
			float sin_a = Trig::sin(angle / 2);

			Vect qV = v.getNorm();
			qV *= sin_a;

			this->_qx = qV[x];
			this->_qy = qV[y];
			this->_qz = qV[z];
			this->_qw = cos_a;
		}
	}

	void Quat::set(Orient o1, Vect v1, Vect v2)
	{
		Matrix tmp((Matrix::Orient)o1, v1, v2);
		this->set(tmp);
	}

	void Quat::setVect(Vect& v1)
	{
		this->_qx = v1.x();
		this->_qy = v1.y();
		this->_qz = v1.z();
		//TODO:
		this->_qw = 0.0f;
	}

	float& Quat::operator[](x_enum)
	{
		return this->_qx;
	}

	float& Quat::operator[](y_enum)
	{
		return this->_qy;
	}

	float& Quat::operator[](z_enum)
	{
		return this->_qz;
	}

	float& Quat::operator[](w_enum)
	{
		return this->_qw;
	}

	float Quat::operator[](x_enum) const
	{
		return this->_qx;
	}

	float Quat::operator[](y_enum) const
	{
		return this->_qy;
	}

	float Quat::operator[](z_enum) const
	{
		return this->_qz;
	}

	float Quat::operator[](w_enum) const
	{
		return this->_qw;
	}

	float& Quat::qx()
	{
		return this->_qx;
	}

	float& Quat::qy()
	{
		return this->_qy;
	}

	float& Quat::qz()
	{
		return this->_qz;
	}

	float& Quat::real()
	{
		return this->_qw;
	}

	const float& Quat::qx() const
	{
		return this->_qx;
	}

	const float& Quat::qy() const
	{
		return this->_qy;
	}

	const float& Quat::qz() const
	{
		return this->_qz;
	}

	const float& Quat::real() const
	{
		return this->_qw;
	}

	void Quat::getVect(Vect& v) const
	{
		v.set(this->_qx, this->_qy, this->_qz, 1.0f);
	}

	Quat Quat::operator*(const Quat& rhs) const
	{
		Vect pv, qv, tmpv;
		float pw = this->_qw, qw = rhs._qw;
		this->getVect(pv);
		rhs.getVect(qv);
		float tmps = pw * qw - pv.dot(qv);
		tmpv = qv.cross(pv) + qw * pv + pw * qv;

		return Quat(tmpv,tmps);
	}

	Quat Quat::operator*=(const Quat& rhs)
	{
		Vect pv, qv, tmpv;
		float pw = this->_qw, qw = rhs._qw;
		this->getVect(pv);
		rhs.getVect(qv);
		float tmps = pw * qw - pv.dot(qv);
		tmpv = qv.cross(pv) + qw * pv + pw * qv;
		this->set(tmpv, tmps);
		return *this;
	}

	Quat Quat::operator+(const Quat& t) const
	{
		return Quat(this->_qx + t._qx, this->_qy + t._qy, this->_qz + t._qz, this->_qw + t._qw);
	}

	Quat Quat::operator+=(const Quat& t)
	{
		this->_qx += t._qx;
		this->_qy += t._qy;
		this->_qz += t._qz;
		this->_qw += t._qw;
		return *this;
	}

	Quat Quat::operator-(const Quat& t) const
	{
		return Quat(this->_qx - t._qx, this->_qy - t._qy, this->_qz - t._qz, this->_qw - t._qw);
	}

	Quat Quat::operator-=(const Quat& t)
	{
		this->_qx -= t._qx;
		this->_qy -= t._qy;
		this->_qz -= t._qz;
		this->_qw -= t._qw;
		return *this;
	}

	Quat Quat::operator/(const Quat& t) const
	{
		return Quat(this->_qx / t._qx, this->_qy / t._qy, this->_qz / t._qz, this->_qw / t._qw);
	}

	Quat Quat::operator/=(const Quat& t)
	{
		this->_qx /= t._qx;
		this->_qy /= t._qy;
		this->_qz /= t._qz;
		this->_qw /= t._qw;
		return *this;
	}

	Quat Quat::operator+(const float t) const
	{
		return Quat(this->_qx + t, this->_qy + t, this->_qz + t, this->_qw + t);
	}

	Quat Quat::operator+=(const float t)
	{
		this->_qx += t;
		this->_qy += t;
		this->_qz += t;
		this->_qw += t;
		return *this;
	}

	Quat Quat::operator-(const float t) const
	{
		return Quat(this->_qx - t, this->_qy - t, this->_qz - t, this->_qw - t);
	}

	Quat Quat::operator-=(const float t)
	{
		this->_qx -= t;
		this->_qy -= t;
		this->_qz -= t;
		this->_qw -= t;
		return *this;
	}

	Quat Quat::operator*(const float t) const
	{
		return Quat(this->_qx * t, this->_qy * t, this->_qz * t, this->_qw * t);
	}

	Quat Quat::operator*=(const float t)
	{
		this->_qx *= t;
		this->_qy *= t;
		this->_qz *= t;
		this->_qw *= t;
		return *this;
	}

	Quat Quat::operator/(const float t) const
	{
		return Quat(this->_qx / t, this->_qy / t, this->_qz / t, this->_qw / t);
	}

	Quat Quat::operator/=(const float t)
	{
		this->_qx /= t;
		this->_qy /= t;
		this->_qz /= t;
		this->_qw /= t;
		return *this;
	}

	Quat Quat::operator+()
	{
		return Quat(*this);
	}

	Quat Quat::operator-()
	{
		return Quat(-(this->_qx), -(this->_qy), -(this->_qz), -(this->_qw));
	}

	Matrix Quat::operator*(const Matrix& m) const
	{
		return Matrix(*this) * m;
	}

	Quat Quat::operator*=(const Matrix& m)
	{
		Matrix tmp;
		tmp.set(*this);
		tmp *= m;
		this->set(tmp);
		return *this;
	}

	//Quat Quat::operator*(const Vect& m) const
	//{
	//	return Quat();
	//}

	const Quat Quat::multByElement(const Quat& q) const
	{
		return Quat(this->_qx * q._qx, this->_qy * q._qy, this->_qz * q._qz, this->_qw * q._qw);
	}

	bool Quat::isEqual(const Quat& q, float s)
	{
		return abs(this->_qx - q._qx) < s && abs(this->_qy - q._qy) < s && abs(this->_qz - q._qz) < s && abs(this->_qw - q._qw) < s;
	}

	bool Quat::isNegEqual(const Quat& q, float s)
	{
		return abs(this->_qx + q._qx) < s&& abs(this->_qy + q._qy) < s&& abs(this->_qz + q._qz) < s&& abs(this->_qw + q._qw) < s;
	}

	bool Quat::isNormalized(float s)
	{
		return abs(1.0f - this->mag()) < s;
	}

	bool Quat::isEquivalent(const Quat& q, float s)
	{
		return this->isEqual(q,s) || this->isNegEqual(q,s);
	}

	bool Quat::isConjugateEqual(const Quat& q, float s)
	{
		return abs(this->_qx + q._qx) < s && abs(this->_qy + q._qy) < s && abs(this->_qz + q._qz) < s && abs(this->_qw - q._qw) < s;
	}

	bool Quat::isIdentity(float s)
	{
		return abs(this->_qx - 0.0f) < s && abs(this->_qy - 0.0f) < s && abs(this->_qz - 0.0f) < s && abs(this->_qw - 1.0f) < s;
	}

	bool Quat::isZero(float s)
	{
		return abs(this->_qx - 0.0f) < s && abs(this->_qy - 0.0f) < s && abs(this->_qz - 0.0f) < s && abs(this->_qw - 0.0f) < s;
	}

	Quat Quat::getConj() const
	{
		return Quat(-(this->_qx), -(this->_qy),-(this->_qz),this->_qw);
	}

	void Quat::conj()
	{
		this->_qx = -this->_qx;
		this->_qy = -this->_qy;
		this->_qz = -this->_qz;
	}

	Quat Quat::getT() const
	{
		return this->getConj();
	}

	void Quat::T()
	{
		this->conj();
	}

	const float Quat::mag() const
	{
		return Trig::sqrt(
			this->_qx * this->_qx +
			this->_qy * this->_qy +
			this->_qz * this->_qz +
			this->_qw * this->_qw);
	}

	float Quat::magSquared()
	{
		return this->_qx * this->_qx + this->_qy * this->_qy + this->_qz * this->_qz + this->_qw * this->_qw;
	}

	float Quat::invMag()
	{
		return 1/this->mag();
	}

	Quat& Quat::norm()
	{
		const float n = this->mag();
		this->_qx = this->_qx / n;
		this->_qy = this->_qy / n;
		this->_qz = this->_qz / n;
		this->_qw = this->_qw / n;
		return *this;
	}

	Quat Quat::getNorm() const
	{
		return *this / this->mag();
	}

	Quat Quat::getInv()
	{
		return this->getConj() / this->magSquared();
	}

	float Quat::getAngle()
	{
		float val = 2 * Trig::acos(this->_qw);
		return val;
	}

	void Quat::getAxis(Vect& v)
	{
		v.x() = this->_qx * 2;
		v.y() = this->_qy * 2;
		v.z() = this->_qz * 2;
	}

	void Quat::inv()
	{
		*this = this->getConj() / this->magSquared();
	}

	float Quat::dot(const Quat& q)
	{
		return this->_qx * q._qx + this->_qy * q._qy + this->_qz * q._qz + this->_qw * q._qw;
	}

	void Quat::Lqvqc(Vect vin, Vect& vout)
	{
		Quat v = Quat(vin, vin.w());

		Quat tmp = this->norm() * v * this->norm().getT();

		vout.x() = tmp.qx();
		vout.y() = tmp.qy();
		vout.z() = tmp.qz();
		vout.w() = tmp.real();
	}

	void Quat::Lqcvq(Vect vin, Vect& vout)
	{
		Quat v = Quat(vin, vin.w());

		Quat tmp = this->norm().getT() * v * this->norm();

		vout.x() = tmp.qx();
		vout.y() = tmp.qy();
		vout.z() = tmp.qz();
		vout.w() = tmp.real();
	}


	Quat operator*(float s, const Quat& v)
	{
		return Quat(v._qx * s, v._qy * s, v._qz * s, v._qw * s);
	}

	Quat operator+(float s, const Quat& v)
	{
		return Quat(v._qx + s, v._qy + s, v._qz + s, v._qw + s);
	}

	Quat operator-(float s, const Quat& v)
	{
		return Quat(s - v._qx, s - v._qy, s - v._qz, s - v._qw);
	}

	Quat operator/(float s, const Quat& v)
	{
		return Quat(s / v._qx, s / v._qy, s / v._qz, s / v._qw);
	}


}


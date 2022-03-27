#include "MathEngine.h"

namespace Azul
{

    Vect::Vect()
        : _vx(0.0f), _vy(0.0f), _vz(0.0f), _vw(1.0f)
    {

    }

    Vect::Vect(const Vect& rhs)
        : _vx(rhs._vx), _vy(rhs._vy), _vz(rhs._vz), _vw(rhs._vw)
    {

    }

    Vect::Vect(float x, float y, float z, float w)
    {
        this->_vx = x;
        this->_vy = y;
        this->_vz = z;
        this->_vw = w;
    }

    Vect Vect::operator + (const Vect& t) const
    {
        return Vect(this->_vx + t._vx, this->_vy + t._vy, this->_vz + t._vz, 1.0f);
    }

    Vect Vect::operator += (const Vect& t)
    {
        this->_vx += t._vx;
        this->_vy += t._vy;
        this->_vz += t._vz;
        this->_vw = 1.0f;
        return *this;
    }

    Vect Vect::operator - (const Vect& t) const
    {
        return Vect(this->_vx - t._vx, this->_vy - t._vy, this->_vz - t._vz, 1.0f);
    }

    Vect Vect::operator -= (const Vect& t)
    {
        this->_vx -= t._vx;
        this->_vy -= t._vy;
        this->_vz -= t._vz;
        this->_vw = 1.0f;
        return *this;
    }

    Vect Vect::operator * (const float s) const
    {
        Vect tmp;

        tmp._vx = this->_vx * s;
        tmp._vy = this->_vy * s;
        tmp._vz = this->_vz * s;
        tmp._vw = 1.0f;

        return tmp;
    }

    Vect operator * (const float s, const Vect& v)
    {
        Vect tmp;

        tmp._vx = v._vx * s;
        tmp._vy = v._vy * s;
        tmp._vz = v._vz * s;
        tmp._vw = 1.0f;

        return tmp;
    }

    Vect Vect::operator * (const Matrix& m) const
    {
        Vect tmp;
        Vect v0 = m.get(Matrix::Row::i0);
        Vect v1 = m.get(Matrix::Row::i1);
        Vect v2 = m.get(Matrix::Row::i2);
        Vect v3 = m.get(Matrix::Row::i3);

        tmp._vx = this->_vx * v0._vx + this->_vy * v1._vx + this->_vz * v2._vx + this->_vw * v3._vx;
        tmp._vy = this->_vx * v0._vy + this->_vy * v1._vy + this->_vz * v2._vy + this->_vw * v3._vy;
        tmp._vz = this->_vx * v0._vz + this->_vy * v1._vz + this->_vz * v2._vz + this->_vw * v3._vz;
        tmp._vw = this->_vx * v0._vw + this->_vy * v1._vw + this->_vz * v2._vw + this->_vw * v3._vw;

        return tmp;
    }

    Vect Vect::operator *= (const Matrix& m)
    {
        Vect tmp;
        Vect v0 = m.get(Matrix::Row::i0);
        Vect v1 = m.get(Matrix::Row::i1);
        Vect v2 = m.get(Matrix::Row::i2);
        Vect v3 = m.get(Matrix::Row::i3);

        tmp._vx = this->_vx * v0._vx + this->_vy * v1._vx + this->_vz * v2._vx + this->_vw * v3._vx;
        tmp._vy = this->_vx * v0._vy + this->_vy * v1._vy + this->_vz * v2._vy + this->_vw * v3._vy;
        tmp._vz = this->_vx * v0._vz + this->_vy * v1._vz + this->_vz * v2._vz + this->_vw * v3._vz;
        tmp._vw = this->_vx * v0._vw + this->_vy * v1._vw + this->_vz * v2._vw + this->_vw * v3._vw;

        this->_vx = tmp._vx;
        this->_vy = tmp._vy;
        this->_vz = tmp._vz;
        this->_vw = tmp._vw;
        return *this;
    }

    Vect Vect::operator * (const Quat& q) const
    {
        Quat v = Quat(*this, this->_vw);

        Quat tmp = q.getNorm().getT() * v * q.getNorm();

        Vect ret;
        ret._vx = tmp.qx();
        ret._vy = tmp.qy();
        ret._vz = tmp.qz();
        ret._vw = tmp.real();

        return ret;
    }

    Vect Vect::operator *= (const Quat& q)
    {
        Quat v = Quat(*this, this->_vw);

        Quat tmp = q.getNorm().getT() * v * q.getNorm();

        this->_vx = tmp.qx();
        this->_vy = tmp.qy();
        this->_vz = tmp.qz();
        this->_vw = tmp.real();

        return *this;
    }

    bool Vect::isEqual(const Vect& b, float tolerance) const
    {
        if (Util::isNotEqual(this->_vx, b._vx, tolerance))
            return false;
        if (Util::isNotEqual(this->_vy, b._vy, tolerance))
            return false;
        if (Util::isNotEqual(this->_vz, b._vz, tolerance))
            return false;
        if (Util::isNotEqual(this->_vw, b._vw, tolerance))
            return false;
        else return true;
    }

    bool Vect::isZero(float tolerance) const
    {
        if (Util::isNonZero(this->_vx, tolerance))
            return false;
        if (Util::isNonZero(this->_vy, tolerance))
            return false;
        if (Util::isNonZero(this->_vz, tolerance))
            return false;
        if (Util::isNonZero(this->_vw - 1.0f, tolerance))
            return false;
        else return true;
    }

    float& Vect::x()
    {
        return this->_vx;
    }
    float& Vect::y()
    {
        return this->_vy;
    }
    float& Vect::z()
    {
        return this->_vz;
    }
    float& Vect::w()
    {
        return this->_vw;
    }

    const float& Vect::x() const
    {
        return this->_vx;
    }
    const float& Vect::y() const
    {
        return this->_vy;
    }
    const float& Vect::z() const
    {
        return this->_vz;
    }
    const float& Vect::w() const
    {
        return this->_vw;
    }

    float& Vect::operator[](const enum x_enum)
    {
        return this->_vx;
    }
    float& Vect::operator[](const enum y_enum)
    {
        return this->_vy;
    }
    float& Vect::operator[](const enum z_enum)
    {
        return this->_vz;
    }
    float& Vect::operator[](const enum w_enum)
    {
        return this->_vw;
    }

    const float Vect::operator[](const enum x_enum) const
    {
        return this->_vx;
    }
    const float Vect::operator[](const enum y_enum) const
    {
        return this->_vy;
    }
    const float Vect::operator[](const enum z_enum) const
    {
        return this->_vz;
    }
    const float Vect::operator[](const enum w_enum) const
    {
        return this->_vw;
    }

    const Vect& Vect::operator= (const Vect& rhs)
    {
        this->_vx = rhs._vx;
        this->_vy = rhs._vy;
        this->_vz = rhs._vz;
        this->_vw = rhs._vw;

        return *this;
    }

    Vect Vect::operator*=(const float t)
    {
        this->_vx *= t;
        this->_vy *= t;
        this->_vz *= t;
        this->_vw = 1.0f;

        return *this;
    }

    // Unary Operator
    Vect Vect::operator +()
    {
        Vect tmp;
        tmp._vx = this->_vx;
        tmp._vy = this->_vy;
        tmp._vz = this->_vz;
        tmp._vw = 1.0f;
        return tmp;
    }
    Vect Vect::operator -()
    {
        Vect tmp;
        tmp._vx = -this->_vx;
        tmp._vy = -this->_vy;
        tmp._vz = -this->_vz;
        tmp._vw = 1.0f;
        return tmp;
    }

    void Vect::set(float x, float y, float z, float w)
    {
        this->_vx = x;
        this->_vy = y;
        this->_vz = z;
        this->_vw = w;
    }

    void Vect::set(Vect v)
    {
        this->_vx = v._vx;
        this->_vy = v._vy;
        this->_vz = v._vz;
        this->_vw = v._vw;
    }

    const float Vect::dot(const Vect& v) const
    {
        float value = this->_vx * v._vx + this->_vy * v._vy + this->_vz * v._vz;
        return value;
    }

    const Vect Vect::cross(const Vect& v) const
    {
        Vect out;
        out._vx = this->_vy * v._vz - this->_vz * v._vy;
        out._vy = -this->_vx * v._vz + this->_vz * v._vx;
        out._vz = this->_vx * v._vy - this->_vy * v._vx;
        return out;
    }

    Vect& Vect::norm()
    {
        float len = this->mag();
        this->_vx = this->_vx / len;
        this->_vy = this->_vy / len;
        this->_vz = this->_vz / len;
        return *this;
    }

    Vect Vect::getNorm() const
    {
        float len = this->mag();
        Vect out;
        out._vx = this->_vx / len;
        out._vy = this->_vy / len;
        out._vz = this->_vz / len;
        return out;
    }

    const float Vect::mag() const
    {
        float mag = Trig::sqrt(this->_vx * this->_vx + this->_vy * this->_vy + this->_vz * this->_vz);
        return mag;
    }

    const float Vect::magSqr() const
    {
        float magSqr = this->_vx * this->_vx + this->_vy * this->_vy + this->_vz * this->_vz;
        return magSqr;
    }

    const float Vect::getAngle(const Vect& v) const
    {
        float cosV = dot(v) / (this->mag() * v.mag());
        return Trig::acos(cosV);
    }
  
}


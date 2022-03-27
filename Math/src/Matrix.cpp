#include "MathEngine.h"

namespace Azul
{
// Do your magic here
    Matrix::Matrix()
    {
        this->set(Matrix::Special::Zero);
    }

    Matrix::Matrix(const Vect& v0, const Vect& v1, const Vect& v2, const Vect& v3)
        :_v0(v0), _v1(v1), _v2(v2), _v3(v3)
    {

    }

    Matrix::Matrix(const Matrix& tmp)
        : _v0(tmp._v0), _v1(tmp._v1), _v2(tmp._v2), _v3(tmp._v3)
    {

    }

    Matrix::Matrix(Matrix::Special sp)
    {
        this->set(sp);
    }

    Matrix::Matrix(Matrix::Trans trans, float x, float y, float z)
    {
        this->set(trans, x, y, z);
    }

    Matrix::Matrix(Matrix::Trans trans, Vect v)
    {
        this->set(trans, v);
    }

    Matrix::Matrix(Matrix::Scale scale, float x, float y, float z)
    {
        this->set(scale, x, y, z);
    }

    Matrix::Matrix(Matrix::Scale scale, Vect v)
    {
        this->set(scale, v);
    }

    Matrix::Matrix(Matrix::Rot1 rot, float t)
    {
        this->set(rot, t);
    }

    Matrix::Matrix(Matrix::Rot3 rot, float x, float y, float z)
    {
        this->set(rot, x, y, z);
    }

    Matrix::Matrix(Matrix::Rot, Vect v, float angle)
    {
        this->set(Matrix::Rot::AxisAngle, v, angle);
    }

    Matrix::Matrix(Matrix::Orient orient, Vect v1, Vect v2)
    {
        this->set(orient, v1, v2);
    }

    Matrix::Matrix(Quat qa)
    {
        this->set(qa);
    }


    Matrix Matrix::operator*(const Matrix& rhs) const
    {
        Matrix tmp;

        tmp._m0 = this->_m0 * rhs._m0 + this->_m1 * rhs._m4 + this->_m2 * rhs._m8 + this->_m3 * rhs._m12;
        tmp._m1 = this->_m0 * rhs._m1 + this->_m1 * rhs._m5 + this->_m2 * rhs._m9 + this->_m3 * rhs._m13;
        tmp._m2 = this->_m0 * rhs._m2 + this->_m1 * rhs._m6 + this->_m2 * rhs._m10 + this->_m3 * rhs._m14;
        tmp._m3 = this->_m0 * rhs._m3 + this->_m1 * rhs._m7 + this->_m2 * rhs._m11 + this->_m3 * rhs._m15;

        tmp._m4 = this->_m4 * rhs._m0 + this->_m5 * rhs._m4 + this->_m6 * rhs._m8 + this->_m7 * rhs._m12;
        tmp._m5 = this->_m4 * rhs._m1 + this->_m5 * rhs._m5 + this->_m6 * rhs._m9 + this->_m7 * rhs._m13;
        tmp._m6 = this->_m4 * rhs._m2 + this->_m5 * rhs._m6 + this->_m6 * rhs._m10 + this->_m7 * rhs._m14;
        tmp._m7 = this->_m4 * rhs._m3 + this->_m5 * rhs._m7 + this->_m6 * rhs._m11 + this->_m7 * rhs._m15;

        tmp._m8 = this->_m8 * rhs._m0 + this->_m9 * rhs._m4 + this->_m10 * rhs._m8 + this->_m11 * rhs._m12;
        tmp._m9 = this->_m8 * rhs._m1 + this->_m9 * rhs._m5 + this->_m10 * rhs._m9 + this->_m11 * rhs._m13;
        tmp._m10 = this->_m8 * rhs._m2 + this->_m9 * rhs._m6 + this->_m10 * rhs._m10 + this->_m11 * rhs._m14;
        tmp._m11 = this->_m8 * rhs._m3 + this->_m9 * rhs._m7 + this->_m10 * rhs._m11 + this->_m11 * rhs._m15;

        tmp._m12 = this->_m12 * rhs._m0 + this->_m13 * rhs._m4 + this->_m14 * rhs._m8 + this->_m15 * rhs._m12;
        tmp._m13 = this->_m12 * rhs._m1 + this->_m13 * rhs._m5 + this->_m14 * rhs._m9 + this->_m15 * rhs._m13;
        tmp._m14 = this->_m12 * rhs._m2 + this->_m13 * rhs._m6 + this->_m14 * rhs._m10 + this->_m15 * rhs._m14;
        tmp._m15 = this->_m12 * rhs._m3 + this->_m13 * rhs._m7 + this->_m14 * rhs._m11 + this->_m15 * rhs._m15;

        return tmp;
    }

    Matrix Matrix::operator *= (const Matrix& rhs)
    {
        Matrix tmp = *this * rhs;
        this->_v0 = tmp._v0;
        this->_v1 = tmp._v1;
        this->_v2 = tmp._v2;
        this->_v3 = tmp._v3;
        return *this;
    }

    Matrix Matrix::operator*(Quat& q) const
    {
        Matrix tmp;
        tmp.set(q);
        tmp = *this * tmp;
        return tmp;
    }

    //Quat Matrix::operator*(const Quat& q)
    //{
    //    Quat tmp;
    //    tmp.set(*this);
    //    Quat res = tmp * q;
    //    return Quat(res);
    //}

    Matrix& Matrix::operator=(const Matrix& rhs)
    {
        this->_v0 = rhs._v0;
        this->_v1 = rhs._v1;
        this->_v2 = rhs._v2;
        this->_v3 = rhs._v3;

        return *this;
    }

    Matrix Matrix::operator + (const Matrix& t) const
    {
        Matrix tmp;
        tmp._v0 = this->_v0 + t._v0;
        tmp._m3 = this->_m3 + t._m3;
        tmp._v1 = this->_v1 + t._v1;
        tmp._m7 = this->_m7 + t._m7;
        tmp._v2 = this->_v2 + t._v2;
        tmp._m11 = this->_m11 + t._m11;
        tmp._v3 = this->_v3 + t._v3;
        tmp._m15 = this->_m15 + t._m15;
        return tmp;
    }
    Matrix Matrix::operator += (const Matrix& t)
    {
        Matrix tmp(*this);
        this->_v0 += t._v0;
        this->_m3 = tmp._m3 + t._m3;
        this->_v1 += t._v1;
        this->_m7 = tmp._m7 + t._m7;
        this->_v2 += t._v2;
        this->_m11 = tmp._m11 + t._m11;
        this->_v3 += t._v3;
        this->_m15 = tmp._m15 + t._m15;
        return *this;
    }

    Matrix Matrix::operator - (const Matrix& t) const
    {
        Matrix tmp;
        tmp._v0 = this->_v0 - t._v0;
        tmp._m3 = this->_m3 - t._m3;
        tmp._v1 = this->_v1 - t._v1;
        tmp._m7 = this->_m7 - t._m7;
        tmp._v2 = this->_v2 - t._v2;
        tmp._m11 = this->_m11 - t._m11;
        tmp._v3 = this->_v3 - t._v3;
        tmp._m15 = this->_m15 - t._m15;
        return tmp;
    }
    Matrix Matrix::operator -= (const Matrix& t)
    {
        Matrix tmp(*this);
        this->_v0 -= t._v0;
        this->_m3 = tmp._m3 - t._m3;
        this->_v1 -= t._v1;
        this->_m7 = tmp._m7 - t._m7;
        this->_v2 -= t._v2;
        this->_m11 = tmp._m11 - t._m11;
        this->_v3 -= t._v3;
        this->_m15 = tmp._m15 - t._m15;
        return *this;
    }

    Matrix Matrix::operator * (const float s) const
    {
        Matrix tmp;
        tmp._v0 = s * this->_v0;
        tmp._v0.w() = s * this->_m3;
        tmp._v1 = s * this->_v1;
        tmp._v1.w() = s * this->_m7;
        tmp._v2 = s * this->_v2;
        tmp._v2.w() = s * this->_m11;
        tmp._v3 = s * this->_v3;
        tmp._v3.w() = s * this->_m15;

        return tmp;
    }

    Matrix Matrix::operator *= (const float s)
    {
        Matrix tmp;
        tmp._v0 = s * this->_v0;
        tmp._v0.w() = s * this->_m3;
        tmp._v1 = s * this->_v1;
        tmp._v1.w() = s * this->_m7;
        tmp._v2 = s * this->_v2;
        tmp._v2.w() = s * this->_m11;
        tmp._v3 = s * this->_v3;
        tmp._v3.w() = s * this->_m15;

        this->_v0 = tmp._v0;
        this->_v1 = tmp._v1;
        this->_v2 = tmp._v2;
        this->_v3 = tmp._v3;
        return *this;
    }

    Matrix operator * (float s, const Matrix& t)
    {
        Matrix tmp;
        tmp._v0 = s * t._v0;
        tmp._v0.w() = s * t._m3;
        tmp._v1 = s * t._v1;
        tmp._v1.w() = s * t._m7;
        tmp._v2 = s * t._v2;
        tmp._v2.w() = s * t._m11;
        tmp._v3 = s * t._v3;
        tmp._v3.w() = s * t._m15;

        return tmp;
    }

    // Unary Operator
    Matrix Matrix::operator +()
    {
        Matrix tmp;
        tmp._v0 = this->_v0;
        tmp._v1 = this->_v1;
        tmp._v2 = this->_v2;
        tmp._v3 = this->_v3;
        return tmp;
    }
    Matrix Matrix::operator -()
    {
        Matrix tmp;
        tmp._v0 = -this->_v0;
        tmp._v0.w() = -this->_m3;
        tmp._v1 = -this->_v1;
        tmp._v1.w() = -this->_m7;
        tmp._v2 = -this->_v2;
        tmp._v2.w() = -this->_m11;
        tmp._v3 = -this->_v3;
        tmp._v3.w() = -this->_m15;
        return tmp;
    }

    void Matrix::set(const Vect& v0, const Vect& v1, const Vect& v2, const Vect& v3)
    {
        this->_v0 = v0;
        this->_v1 = v1;
        this->_v2 = v2;
        this->_v3 = v3;
    }

    void Matrix::set(Matrix::Special sp)
    {
        if (sp == Matrix::Special::Identity)
        {
            this->_v0 = Vect(1.0f, 0.0f, 0.0f, 0.0f);
            this->_v1 = Vect(0.0f, 1.0f, 0.0f, 0.0f);
            this->_v2 = Vect(0.0f, 0.0f, 1.0f, 0.0f);
            this->_v3 = Vect(0.0f, 0.0f, 0.0f, 1.0f);
        }
        else
        {
            Vect tmp = Vect(0.0f, 0.0f, 0.0f, 0.0f);
            this->_v0 = tmp;
            this->_v1 = tmp;
            this->_v2 = tmp;
            this->_v3 = tmp;
        }
    }
    void Matrix::set(Matrix::Trans, float x, float y, float z)
    {
        this->set(Matrix::Special::Identity);
        this->_v3 = Vect(x, y, z);
    }

    void Matrix::set(Matrix::Trans, Vect v)
    {
        this->set(Matrix::Special::Identity);
        this->_v3 = v;
    }
    void Matrix::set(Matrix::Scale, float x, float y, float z)
    {
        this->_v0 = Vect(x, 0.0f, 0.0f, 0.0f);
        this->_v1 = Vect(0.0f, y, 0.0f, 0.0f);
        this->_v2 = Vect(0.0f, 0.0f, z, 0.0f);
        this->_v3 = Vect(0.0f, 0.0f, 0.0f, 1.0f);
    }
    void Matrix::set(Matrix::Scale, Vect v)
    {
        this->set(Matrix::Special::Identity);
        this->_m0 = v[x];
        this->_m5 = v[y];
        this->_m10 = v[z];
    }

    void Matrix::set(Matrix::Rot1 rot, float val)
    {
        if (rot == Matrix::Rot1::X)
        {
            this->_v0 = Vect(1.0f, 0.0f, 0.0f, 0.0f);
            this->_v1 = Vect(0.0f, Trig::cos(val), Trig::sin(val), 0.0f);
            this->_v2 = Vect(0.0f, -Trig::sin(val), Trig::cos(val), 0.0f);
            this->_v3 = Vect(0.0f, 0.0f, 0.0f, 1.0f);
        }
        else if (rot == Matrix::Rot1::Y)
        {
            this->_v0 = Vect(Trig::cos(val), 0.0f, -Trig::sin(val), 0.0f);
            this->_v1 = Vect(0.0f, 1.0f, 0.0f, 0.0f);
            this->_v2 = Vect(Trig::sin(val), 0.0f, Trig::cos(val), 0.0f);
            this->_v3 = Vect(0.0f, 0.0f, 0.0f, 1.0f);
        }
        else
        {
            this->_v0 = Vect(Trig::cos(val), Trig::sin(val), 0.0f, 0.0f);
            this->_v1 = Vect(-Trig::sin(val), Trig::cos(val), 0.0f, 0.0f);
            this->_v2 = Vect(0.0f, 0.0f, 1.0f, 0.0f);
            this->_v3 = Vect(0.0f, 0.0f, 0.0f, 1.0f);
        }
    }

    void Matrix::set(Matrix::Row i, Vect v)
    {
        if (i == Matrix::Row::i0)
            this->_v0 = v;
        else if (i == Matrix::Row::i1)
            this->_v1 = v;
        else if (i == Matrix::Row::i2)
            this->_v2 = v;
        else
            this->_v3 = v;
    }

    void Matrix::set(Matrix::Rot3, float x, float y, float z)
    {
        this->_m0 = Trig::cos(y) * Trig::cos(z);
        this->_m1 = Trig::cos(y) * Trig::sin(z);
        this->_m2 = -Trig::sin(y);
        this->_m3 = 0;
        this->_m4 = Trig::sin(x) * Trig::sin(y) * Trig::cos(z) - Trig::cos(x) * Trig::sin(z);
        this->_m5 = Trig::sin(x) * Trig::sin(y) * Trig::sin(z) + Trig::cos(x) * Trig::cos(z);
        this->_m6 = Trig::sin(x) * Trig::cos(y);
        this->_m7 = 0;
        this->_m8 = Trig::cos(x) * Trig::sin(y) * Trig::cos(z) + Trig::sin(x) * Trig::sin(z);
        this->_m9 = Trig::cos(x) * Trig::sin(y) * Trig::sin(z) - Trig::sin(x) * Trig::cos(z);
        this->_m10 = Trig::cos(x) * Trig::cos(y);
        this->_m11 = 0;
        this->_m12 = 0;
        this->_m13 = 0;
        this->_m14 = 0;
        this->_m15 = 1.0f;
    }

    void Matrix::set(Matrix::Rot, Vect v, float angle)
    {
        const float angle_a = 0.5f * angle;
        float cos_a;
        float sin_a;

        cos_a = Trig::cos(angle_a);
        sin_a = Trig::sin(angle_a);

        Vect qV = v.getNorm();

        qV *= sin_a;

        Vect Q;
        Q[x] = qV[x];
        Q[y] = qV[y];
        Q[z] = qV[z];
        Q[w] = cos_a;

        // this function has been transposed
        float x2, y2, z2;
        float xx, xy, xz;
        float yy, yz, zz;
        float wx, wy, wz;

        // ADD test to make sure that quat is normalized

        x2 = Q[x] + Q[x];
        y2 = Q[y] + Q[y];
        z2 = Q[z] + Q[z];

        xx = Q[x] * x2;
        xy = Q[x] * y2;
        xz = Q[x] * z2;

        yy = Q[y] * y2;
        yz = Q[y] * z2;
        zz = Q[z] * z2;

        wx = Q[w] * x2;
        wy = Q[w] * y2;
        wz = Q[w] * z2;

        this->_m0 = 1.0f - (yy + zz);
        this->_m1 = xy + wz;
        this->_m2 = xz - wy;
        this->_m3 = 0.0f;

        this->_m4 = xy - wz;
        this->_m5 = 1.0f - (xx + zz);
        this->_m6 = yz + wx;
        this->_m7 = 0.0f;

        this->_m8 = xz + wy;
        this->_m9 = yz - wx;
        this->_m10 = 1.0f - (xx + yy);
        this->_m11 = 0.0f;

        this->_v3.set(0.0f, 0.0f, 0.0f, 1.0f);
    }

    void Matrix::set(const Matrix::Orient orient, const Vect& dof, const Vect& up)
    {
        if (orient == Matrix::Orient::LocalToWorld)
        {
            this->_v0 = up.cross(dof).getNorm();
            this->_m3 = 0.0f;
            this->_v1 = dof.cross(up).cross(dof).getNorm();
            this->_m7 = 0.0f;
            this->_v2 = dof.getNorm();
            this->_m11 = 0.0f;
            this->_v3 = Vect();
        }
        else
        {
            this->set(Matrix::Orient::LocalToWorld, dof, up);
            this->T();
        }
    }

    void Matrix::set(Quat q)
    {
        const float qx = q.qx(), qy = q.qy(), qz = q.qz(), qw = q.real();
        this->_m0 = 1 - 2 * (qy * qy + qz * qz);
        this->_m1 = 2 * (qx * qy + qw * qz);
        this->_m2 = 2 * (qx * qz - qw * qy);
        this->_m3 = 0;
        this->_m4 = 2 * (qx * qy - qw * qz);
        this->_m5 = 1 - 2 * (qx * qx + qz * qz);
        this->_m6 = 2 * (qy * qz + qw * qx);
        this->_m7 = 0;
        this->_m8 = 2 * (qx * qz + qw * qy);
        this->_m9 = 2 * (qy * qz - qw * qx);
        this->_m10 = 1 - 2 * (qx * qx + qy * qy);
        this->_m11 = 0;
        this->_m12 = 0;
        this->_m13 = 0;
        this->_m14 = 0;
        this->_m15 = 1.0f;
    }

    Vect Matrix::get(const Row type) const
    {
        if (type == Matrix::Row::i0)
            return this->_v0;
        else if (type == Matrix::Row::i1)
            return this->_v1;
        else if (type == Matrix::Row::i2)
            return this->_v2;
        else
            return this->_v3;
    }

    float Matrix::det()
    {
        float val;
        val = _m0 * (_m5 * (_m10 * _m15 - _m11 * _m14)
            - _m6 * (_m9 * _m15 - _m11 * _m13)
            + _m7 * (_m9 * _m14 - _m10 * _m13))
            - _m1 * (_m4 * (_m10 * _m15 - _m11 * _m14)
                - _m6 * (_m8 * _m15 - _m11 * _m12)
                + _m7 * (_m8 * _m14 - _m10 * _m12))
            + _m2 * (_m4 * (_m9 * _m15 - _m11 * _m13)
                - _m5 * (_m8 * _m15 - _m11 * _m12)
                + _m7 * (_m8 * _m13 - _m9 * _m12))
            - _m3 * (_m4 * (_m9 * _m14 - _m10 * _m13)
                - _m5 * (_m8 * _m14 - _m10 * _m12)
                + _m6 * (_m8 * _m13 - _m9 * _m12));
        return val;
    }

    void Matrix::T()
    {
        Matrix tmp;
        tmp._v0 = Vect(_m0, _m4, _m8, _m12);
        tmp._v1 = Vect(_m1, _m5, _m9, _m13);
        tmp._v2 = Vect(_m2, _m6, _m10, _m14);
        tmp._v3 = Vect(_m3, _m7, _m11, _m15);

        *this = tmp;
    }

    Matrix Matrix::getT() const
    {
        Matrix tmp;
        tmp._v0 = Vect(_m0, _m4, _m8, _m12);
        tmp._v1 = Vect(_m1, _m5, _m9, _m13);
        tmp._v2 = Vect(_m2, _m6, _m10, _m14);
        tmp._v3 = Vect(_m3, _m7, _m11, _m15);

        return tmp;
    }

    void Matrix::inv()
    {
        this->_v0.norm();
        this->_v1.norm();
        this->_v2.norm();

        Matrix tmp;
        tmp._m0 = _m6 * _m11 * _m13 - _m7 * _m10 * _m13 + _m7 * _m9 * _m14 - _m5 * _m11 * _m14 - _m6 * _m9 * _m15 + _m5 * _m10 * _m15;
        tmp._m1 = _m3 * _m10 * _m13 - _m2 * _m11 * _m13 - _m3 * _m9 * _m14 + _m1 * _m11 * _m14 + _m2 * _m9 * _m15 - _m1 * _m10 * _m15;
        tmp._m2 = _m2 * _m7 * _m13 - _m3 * _m6 * _m13 + _m3 * _m5 * _m14 - _m1 * _m7 * _m14 - _m2 * _m5 * _m15 + _m1 * _m6 * _m15;
        tmp._m3 = _m3 * _m6 * _m9 - _m2 * _m7 * _m9 - _m3 * _m5 * _m10 + _m1 * _m7 * _m10 + _m2 * _m5 * _m11 - _m1 * _m6 * _m11;
        tmp._m4 = _m7 * _m10 * _m12 - _m6 * _m11 * _m12 - _m7 * _m8 * _m14 + _m4 * _m11 * _m14 + _m6 * _m8 * _m15 - _m4 * _m10 * _m15;
        tmp._m5 = _m2 * _m11 * _m12 - _m3 * _m10 * _m12 + _m3 * _m8 * _m14 - _m0 * _m11 * _m14 - _m2 * _m8 * _m15 + _m0 * _m10 * _m15;
        tmp._m6 = _m3 * _m6 * _m12 - _m2 * _m7 * _m12 - _m3 * _m4 * _m14 + _m0 * _m7 * _m14 + _m2 * _m4 * _m15 - _m0 * _m6 * _m15;
        tmp._m7 = _m2 * _m7 * _m8 - _m3 * _m6 * _m8 + _m3 * _m4 * _m10 - _m0 * _m7 * _m10 - _m2 * _m4 * _m11 + _m0 * _m6 * _m11;
        tmp._m8 = _m5 * _m11 * _m12 - _m7 * _m9 * _m12 + _m7 * _m8 * _m13 - _m4 * _m11 * _m13 - _m5 * _m8 * _m15 + _m4 * _m9 * _m15;
        tmp._m9 = _m3 * _m9 * _m12 - _m1 * _m11 * _m12 - _m3 * _m8 * _m13 + _m0 * _m11 * _m13 + _m1 * _m8 * _m15 - _m0 * _m9 * _m15;
        tmp._m10 = _m1 * _m7 * _m12 - _m3 * _m5 * _m12 + _m3 * _m4 * _m13 - _m0 * _m7 * _m13 - _m1 * _m4 * _m15 + _m0 * _m5 * _m15;
        tmp._m11 = _m3 * _m5 * _m8 - _m1 * _m7 * _m8 - _m3 * _m4 * _m9 + _m0 * _m7 * _m9 + _m1 * _m8 * _m11 - _m0 * _m5 * _m11;
        tmp._m12 = _m6 * _m9 * _m12 - _m5 * _m10 * _m12 - _m6 * _m8 * _m13 + _m4 * _m10 * _m13 + _m5 * _m8 * _m14 - _m4 * _m9 * _m14;
        tmp._m13 = _m1 * _m10 * _m12 - _m2 * _m9 * _m12 + _m2 * _m8 * _m13 - _m0 * _m10 * _m13 - _m1 * _m8 * _m14 + _m0 * _m9 * _m14;
        tmp._m14 = _m2 * _m5 * _m12 - _m1 * _m6 * _m12 - _m2 * _m4 * _m13 + _m0 * _m6 * _m13 + _m1 * _m4 * _m14 - _m0 * _m5 * _m14;
        tmp._m15 = _m1 * _m6 * _m8 - _m2 * _m5 * _m8 + _m2 * _m4 * _m9 - _m0 * _m6 * _m9 - _m1 * _m4 * _m10 + _m0 * _m5 * _m10;

        tmp *= (1 / this->det());

        *this = tmp;
    }

    Matrix Matrix::getInv()
    {
        Matrix tmp;

        tmp._m0 = _m6 * _m11 * _m13 - _m7 * _m10 * _m13 + _m7 * _m9 * _m14 - _m5 * _m11 * _m14 - _m6 * _m9 * _m15 + _m5 * _m10 * _m15;
        tmp._m1 = _m3 * _m10 * _m13 - _m2 * _m11 * _m13 - _m3 * _m9 * _m14 + _m1 * _m11 * _m14 + _m2 * _m9 * _m15 - _m1 * _m10 * _m15;
        tmp._m2 = _m2 * _m7 * _m13 - _m3 * _m6 * _m13 + _m3 * _m5 * _m14 - _m1 * _m7 * _m14 - _m2 * _m5 * _m15 + _m1 * _m6 * _m15;
        tmp._m3 = _m3 * _m6 * _m9 - _m2 * _m7 * _m9 - _m3 * _m5 * _m10 + _m1 * _m7 * _m10 + _m2 * _m5 * _m11 - _m1 * _m6 * _m11;
        tmp._m4 = _m7 * _m10 * _m12 - _m6 * _m11 * _m12 - _m7 * _m8 * _m14 + _m4 * _m11 * _m14 + _m6 * _m8 * _m15 - _m4 * _m10 * _m15;
        tmp._m5 = _m2 * _m11 * _m12 - _m3 * _m10 * _m12 + _m3 * _m8 * _m14 - _m0 * _m11 * _m14 - _m2 * _m8 * _m15 + _m0 * _m10 * _m15;
        tmp._m6 = _m3 * _m6 * _m12 - _m2 * _m7 * _m12 - _m3 * _m4 * _m14 + _m0 * _m7 * _m14 + _m2 * _m4 * _m15 - _m0 * _m6 * _m15;
        tmp._m7 = _m2 * _m7 * _m8 - _m3 * _m6 * _m8 + _m3 * _m4 * _m10 - _m0 * _m7 * _m10 - _m2 * _m4 * _m11 + _m0 * _m6 * _m11;
        tmp._m8 = _m5 * _m11 * _m12 - _m7 * _m9 * _m12 + _m7 * _m8 * _m13 - _m4 * _m11 * _m13 - _m5 * _m8 * _m15 + _m4 * _m9 * _m15;
        tmp._m9 = _m3 * _m9 * _m12 - _m1 * _m11 * _m12 - _m3 * _m8 * _m13 + _m0 * _m11 * _m13 + _m1 * _m8 * _m15 - _m0 * _m9 * _m15;
        tmp._m10 = _m1 * _m7 * _m12 - _m3 * _m5 * _m12 + _m3 * _m4 * _m13 - _m0 * _m7 * _m13 - _m1 * _m4 * _m15 + _m0 * _m5 * _m15;
        tmp._m11 = _m3 * _m5 * _m8 - _m1 * _m7 * _m8 - _m3 * _m4 * _m9 + _m0 * _m7 * _m9 + _m1 * _m8 * _m11 - _m0 * _m5 * _m11;
        tmp._m12 = _m6 * _m9 * _m12 - _m5 * _m10 * _m12 - _m6 * _m8 * _m13 + _m4 * _m10 * _m13 + _m5 * _m8 * _m14 - _m4 * _m9 * _m14;
        tmp._m13 = _m1 * _m10 * _m12 - _m2 * _m9 * _m12 + _m2 * _m8 * _m13 - _m0 * _m10 * _m13 - _m1 * _m8 * _m14 + _m0 * _m9 * _m14;
        tmp._m14 = _m2 * _m5 * _m12 - _m1 * _m6 * _m12 - _m2 * _m4 * _m13 + _m0 * _m6 * _m13 + _m1 * _m4 * _m14 - _m0 * _m5 * _m14;
        tmp._m15 = _m1 * _m6 * _m8 - _m2 * _m5 * _m8 + _m2 * _m4 * _m9 - _m0 * _m6 * _m9 - _m1 * _m4 * _m10 + _m0 * _m5 * _m10;

        tmp *= (1 / this->det());
        return tmp;
    }


    float& Matrix::operator[](m0_enum)
    {
        return this->_m0;
    }
    float& Matrix::operator[](m1_enum)
    {
        return this->_m1;
    }
    float& Matrix::operator[](m2_enum)
    {
        return this->_m2;
    }
    float& Matrix::operator[](m3_enum)
    {
        return this->_m3;
    }
    float& Matrix::operator[](m4_enum)
    {
        return this->_m4;
    }
    float& Matrix::operator[](m5_enum)
    {
        return this->_m5;
    }
    float& Matrix::operator[](m6_enum)
    {
        return this->_m6;
    }
    float& Matrix::operator[](m7_enum)
    {
        return this->_m7;
    }
    float& Matrix::operator[](m8_enum)
    {
        return this->_m8;
    }
    float& Matrix::operator[](m9_enum)
    {
        return this->_m9;
    }
    float& Matrix::operator[](m10_enum)
    {
        return this->_m10;
    }
    float& Matrix::operator[](m11_enum)
    {
        return this->_m11;
    }
    float& Matrix::operator[](m12_enum)
    {
        return this->_m12;
    }
    float& Matrix::operator[](m13_enum)
    {
        return this->_m13;
    }
    float& Matrix::operator[](m14_enum)
    {
        return this->_m14;
    }
    float& Matrix::operator[](m15_enum)
    {
        return this->_m15;
    }

    float Matrix::operator[](m0_enum) const
    {
        return this->_m0;
    }
    float Matrix::operator[](m1_enum) const
    {
        return this->_m1;
    }
    float Matrix::operator[](m2_enum) const
    {
        return this->_m2;
    }
    float Matrix::operator[](m3_enum) const
    {
        return this->_m3;
    }
    float Matrix::operator[](m4_enum) const
    {
        return this->_m4;
    }
    float Matrix::operator[](m5_enum) const
    {
        return this->_m5;
    }
    float Matrix::operator[](m6_enum) const
    {
        return this->_m6;
    }
    float Matrix::operator[](m7_enum) const
    {
        return this->_m7;
    }
    float Matrix::operator[](m8_enum) const
    {
        return this->_m8;
    }
    float Matrix::operator[](m9_enum) const
    {
        return this->_m9;
    }
    float Matrix::operator[](m10_enum) const
    {
        return this->_m10;
    }
    float Matrix::operator[](m11_enum) const
    {
        return this->_m11;
    }
    float Matrix::operator[](m12_enum) const
    {
        return this->_m12;
    }
    float Matrix::operator[](m13_enum) const
    {
        return this->_m13;
    }
    float Matrix::operator[](m14_enum) const
    {
        return this->_m14;
    }
    float Matrix::operator[](m15_enum) const
    {
        return this->_m15;
    }

    float& Matrix::m0()
    {
        return this->_m0;
    }
    float& Matrix::m1()
    {
        return this->_m1;
    }
    float& Matrix::m2()
    {
        return this->_m2;
    }
    float& Matrix::m3()
    {
        return this->_m3;
    }
    float& Matrix::m4()
    {
        return this->_m4;
    }
    float& Matrix::m5()
    {
        return this->_m5;
    }
    float& Matrix::m6()
    {
        return this->_m6;
    }
    float& Matrix::m7()
    {
        return this->_m7;
    }
    float& Matrix::m8()
    {
        return this->_m8;
    }
    float& Matrix::m9()
    {
        return this->_m9;
    }
    float& Matrix::m10()
    {
        return this->_m10;
    }
    float& Matrix::m11()
    {
        return this->_m11;
    }
    float& Matrix::m12()
    {
        return this->_m12;
    }
    float& Matrix::m13()
    {
        return this->_m13;
    }
    float& Matrix::m14()
    {
        return this->_m14;
    }
    float& Matrix::m15()
    {
        return this->_m15;
    }

    const float& Matrix::m0() const
    {
        return this->_m0;
    }
    const float& Matrix::m1() const
    {
        return this->_m1;
    }
    const float& Matrix::m2() const
    {
        return this->_m2;
    }
    const float& Matrix::m3() const
    {
        return this->_m3;
    }
    const float& Matrix::m4() const
    {
        return this->_m4;
    }
    const float& Matrix::m5() const
    {
        return this->_m5;
    }
    const float& Matrix::m6() const
    {
        return this->_m6;
    }
    const float& Matrix::m7() const
    {
        return this->_m7;
    }
    const float& Matrix::m8() const
    {
        return this->_m8;
    }
    const float& Matrix::m9() const
    {
        return this->_m9;
    }
    const float& Matrix::m10() const
    {
        return this->_m10;
    }
    const float& Matrix::m11() const
    {
        return this->_m11;
    }
    const float& Matrix::m12() const
    {
        return this->_m12;
    }
    const float& Matrix::m13() const
    {
        return this->_m13;
    }
    const float& Matrix::m14() const
    {
        return this->_m14;
    }
    const float& Matrix::m15() const
    {
        return this->_m15;
    }

    bool Matrix::isEqual(const Matrix& b, float tolerance) const
    {
        if (this->_v0.isEqual(b._v0, tolerance) == false)
            return false;
        if (this->_v1.isEqual(b._v1, tolerance) == false)
            return false;
        if (this->_v2.isEqual(b._v2, tolerance) == false)
            return false;
        if (this->_v3.isEqual(b._v3, tolerance) == false)
            return false;
        else return true;
    }

    bool Matrix::isRotation()
    {
        if (this->det() == 1)
            return true;
        else
            return false;
    }

    bool Matrix::isIdentity(float tolerance) const
    {
        Matrix tmp = Matrix(Special::Identity);
        if (this->isEqual(tmp, tolerance))
            return true;
        else return false;
    }
}


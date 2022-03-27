#include "Game.h"
#include "MathEngine.h"
#include "GameObjectBasic.h"
#include "GraphicsObject.h"
#include "Mesh.h"
#include "Anim.h"

namespace Azul
{
	GameObjectBasic::GameObjectBasic(GraphicsObject *pGraphicsObject)
		: GameObjectRigid(pGraphicsObject)
	{
		assert(pGraphicsObject);
		this->poTrans = new Vect(0.0f, 0.0f, 0.0f);
		this->poScale = new Vect(1.0f, 1.0f, 1.0f);
		this->poQuat = new Quat(0.0f, 0.0f, 0.0f, 1.0f);

		assert(this->poTrans);
		assert(this->poScale);
		assert(this->poQuat);

		this->delta_x = 0.0f;
		this->delta_y = 0.0f;
		this->delta_z = 0.0f;

		this->cur_rot_x = 0.0f;
		this->cur_rot_y = 0.0f;
		this->cur_rot_z = 0.0f;
	}

	GameObjectBasic::~GameObjectBasic()
	{
		delete this->poTrans;
		delete this->poScale;
		delete this->poQuat;
	}

	void GameObjectBasic::privUpdate(AnimTime currentTime)
	{
		AZUL_UNUSED_VAR(currentTime);

		Matrix T(Matrix::Trans::XYZ, *this->poTrans);
		Matrix S(Matrix::Scale::XYZ, *this->poScale);
		Quat   Q(*this->poQuat);

		cur_rot_x += delta_x;
		cur_rot_y += delta_y;
		cur_rot_z += delta_z;

		Matrix Rx(Matrix::Rot1::X, cur_rot_x);
		Matrix Ry(Matrix::Rot1::Y, cur_rot_y);
		Matrix Rz(Matrix::Rot1::Z, cur_rot_z);

		// world matrix
		*this->poWorld = S * Q * Rx * Ry * Rz * T;
	}

	void GameObjectBasic::Update(AnimTime currentTime)
	{
		// Goal: update the world matrix
		this->privUpdate(currentTime);

		// update the bounding volume based on world matrix
		this->baseUpdateBoundingSphere();

		this->poGraphicsObject->SetWorld(*this->poWorld);
	}

	void GameObjectBasic::SetQuat(float qx, float qy, float qz, float qw)
	{
		this->poQuat->set(qx, qy, qz, qw);
	}

	void GameObjectBasic::SetScale(float sx, float sy, float sz)
	{
		this->poScale->set(sx, sy, sz);
	}

	void GameObjectBasic::SetTrans(float x, float y, float z)
	{
		this->poTrans->set(x, y, z);
	}

	void GameObjectBasic::SetScale(Vect &r)
	{
		*this->poScale = r;
	}

	void GameObjectBasic::SetQuat(Quat &r)
	{
		*this->poQuat = r;
	}

	void GameObjectBasic::SetTrans(Vect &r)
	{
		*this->poTrans = r;
	}

}


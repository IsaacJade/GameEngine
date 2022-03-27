#include "Game.h"
#include "MathEngine.h"
#include "GameObjectAnimSkeleton.h"
#include "GameObject.h"
#include "GraphicsObject.h"
#include "Mesh.h"
#include "Anim.h"

namespace Azul
{

	GameObjectAnimSkeleton::GameObjectAnimSkeleton(GraphicsObject *pGraphicsObject, SSBO *_pBoneResult)
		: GameObjectAnim(pGraphicsObject)
	{
		assert(pGraphicsObject);
		this->poTrans = new Vect(0.0f, 0.0f, 0.0f);
		this->poScale = new Vect(1.0f, 1.0f, 1.0f);
		this->poQuat = new Quat(0.0f, 0.0f, 0.0f, 1.0f);
		this->poLocal = new Matrix(Matrix::Special::Identity);
		this->poBoneOrientation = new Matrix(Matrix::Special::Identity);
		this->pSSBOBoneResult = _pBoneResult;
		assert(_pBoneResult);
		assert(poBoneOrientation);
		assert(this->poTrans);
		assert(this->poScale);
		assert(this->poQuat);
		assert(this->poLocal);
	}

	GameObjectAnimSkeleton::~GameObjectAnimSkeleton()
	{
		delete this->poTrans;
		delete this->poScale;
		delete this->poQuat;
		delete this->poLocal;
		delete this->poBoneOrientation;
	}

	void GameObjectAnimSkeleton::privUpdate(AnimTime currentTime)
	{
		AZUL_UNUSED_VAR(currentTime);

		//Trace::out("index: %d \n", index);

		Matrix T;
		Matrix S;
		Quat   Q;
		Bone *pTmp = (Bone *)pSSBOBoneResult->Map(SSBO::Access::READ_ONLY);
		// Get the parent matrix... if root, set to identity
		GameObjectAnimSkeleton *pParentObject = (GameObjectAnimSkeleton *)this->GetParent();
		Matrix matParent(Matrix::Special::Identity);
		if(pParentObject)
		{
			matParent = *pParentObject->poWorld;

			// REMEMBER this is for Animation and hierachy, 
			//          you need to handle models differently
			// Get the result bone array, from there make the matrix
			T.set(Matrix::Trans::XYZ, pTmp[index].T);
			S.set(Matrix::Scale::XYZ, pTmp[index].S);
			Q = pTmp[index].Q;
		}
		else
		{
			T.set(Matrix::Trans::XYZ, 0, 0, 0);
			S.set(Matrix::Scale::XYZ, 1, 1, 1);
			Q.set(Quat::Special::Identity);
		}

		// world matrix
		*this->poLocal = S * Q * T;
		*this->poWorld = *poLocal * matParent;
		pSSBOBoneResult->Unmap();

	}

	void GameObjectAnimSkeleton::Update(AnimTime currentTime)
	{
		// Goal: update the world matrix
		this->privUpdate(currentTime);

	}

	void GameObjectAnimSkeleton::SetQuat(float qx, float qy, float qz, float qw)
	{
		this->poQuat->set(qx, qy, qz, qw);
	}

	void GameObjectAnimSkeleton::SetScale(float sx, float sy, float sz)
	{
		this->poScale->set(sx, sy, sz);
	}

	void GameObjectAnimSkeleton::SetTrans(float x, float y, float z)
	{
		this->poTrans->set(x, y, z);
	}

	void GameObjectAnimSkeleton::SetIndex(int i)
	{
		this->index = i;
	}

	void GameObjectAnimSkeleton::SetScale(Vect &r)
	{
		*this->poScale = r;
	}

	void GameObjectAnimSkeleton::SetQuat(Quat &r)
	{
		*this->poQuat = r;
	}

	void GameObjectAnimSkeleton::SetTrans(Vect &r)
	{
		*this->poTrans = r;
	}

	void GameObjectAnimSkeleton::SetBoneOrientation(const Matrix &tmp)
	{
		*this->poBoneOrientation = tmp;
	}

	Matrix GameObjectAnimSkeleton::GetBoneOrientation(void) const
	{
		// return a copy...
		return Matrix(*this->poBoneOrientation);
	}
}


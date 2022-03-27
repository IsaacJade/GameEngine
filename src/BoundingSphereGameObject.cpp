#include "BoundingSphereGameObject.h"
#include "GameObject.h"
#include "CameraMan.h"
#include "GraphicsObject_WireframeConstantColor.h"


namespace Azul
{
	BoundingSphereGameObject::BoundingSphereGameObject(GraphicsObject *pGraphicsObject)
		: GameObject(pGraphicsObject)
	{
		this->pRefGameObj = nullptr;
		this->poScale = new Vect();
		this->poTrans = new Vect();
		this->render = true;
		assert(pGraphicsObject);
		assert(this->poScale);
		assert(this->poTrans);
	}

	BoundingSphereGameObject::~BoundingSphereGameObject()
	{
		delete this->poScale;
		delete this->poTrans;
	}

	void BoundingSphereGameObject::SetBoundingSphereReference(GameObject *pGameObj)
	{
		this->pRefGameObj = pGameObj;
	}

	void BoundingSphereGameObject::privUpdate(AnimTime currentTime)
	{
		AZUL_UNUSED_VAR(currentTime);

		// Goal: update the world matrix

		Matrix Scale(Matrix::Scale::XYZ, *this->poScale);
		Matrix TransA(Matrix::Trans::XYZ, *this->poTrans);

		// world matrix
		*this->poWorld = Scale * TransA;


		// Flip the color based on camera_0
		Camera *pCam = CameraMan::Find(Camera::Name::CAMERA_0);
		Sphere *pCurrSphere = this->poGraphicsObject->poCurrSphere;

		// Architecture issue... this doesn't feel good.
		GraphicsObject_WireframeConstantColor *pGObj = (GraphicsObject_WireframeConstantColor *)this->poGraphicsObject;
		if(pCam->CullTest(*pCurrSphere) == Camera::CullResult::CULL_OUTSIDE)
		{
			pGObj->poWireColor->set(1.0f, 0.0f, 0.0f, 1.0f);
		}
		else
		{
			pGObj->poWireColor->set(0.0f, 1.0f, 0.0f, 1.0f);
		}


	}

	void BoundingSphereGameObject::privUpdateBoundingSphereReference(AnimTime currentTime)
	{
		// incase the reference object wasn't updated first
		// update it now.

		this->pRefGameObj->Update(currentTime);

		// set the center and scale of bound box based on ref game object's world coord
		Sphere *pRefCurrSphere = this->pRefGameObj->GetGraphicsObject()->poCurrSphere;
		this->poScale->set(pRefCurrSphere->rad, pRefCurrSphere->rad, pRefCurrSphere->rad);
		this->poTrans->set(pRefCurrSphere->cntr);

		Sphere *pCurrSphere = this->GetGraphicsObject()->poCurrSphere;
		*pCurrSphere = *pRefCurrSphere;
	}

	void BoundingSphereGameObject::Update(AnimTime currentTime)
	{
		// Set Translation & Scale from reference
		this->privUpdateBoundingSphereReference(currentTime);

		// Goal: update the world matrix
		this->privUpdate(currentTime);

		// push to graphics object
		this->poGraphicsObject->SetWorld(*this->poWorld);
	}

	void BoundingSphereGameObject::Draw()
	{
		if(render)
		{
			GraphicsObject* pGraphicsObj = this->GetGraphicsObject();
			assert(pGraphicsObj);

			pGraphicsObj->Render();
		}
	}

}



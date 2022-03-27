#ifndef CAMERA_MANAGER_H
#define CAMERA_MANAGER_H

#include "Camera.h"
#include "CameraNode.h"

namespace Azul
{
	// Singleton
	class CameraMan
	{
	public:
		static void Add(Camera::Name name, Camera *pCamera);
		static Camera *Find(Camera::Name name);

		// w1(1) - Camera Type
		//static void SetCurrent(Camera::Name name);
		//static Camera *GetCurrent();
		static void SetCurrent(Camera::Name name, Camera::Type type);
		static Camera *GetCurrent(Camera::Type type);

		static void Create();
		static void Destroy();

	private:  // methods

		static CameraMan *privGetInstance();
		CameraMan();
		void privAddToFront(CameraLink *node, CameraLink *&head);
		void privRemove(CameraLink *pNode, CameraLink *&poHead);

	private:  // add

		CameraLink *poActive;

		// w1(1) - Camera Type
		//Camera *currCamera;		
		Camera *pCamOrthographic;
		Camera *pCamPerspective;


	};

}

#endif


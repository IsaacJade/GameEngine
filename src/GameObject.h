#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "MathEngine.h"
#include "ShaderObject.h"
#include "GraphicsObject.h"
#include "PCSNode.h"
#include "AnimTime.h"

namespace Azul
{

	class GameObject : public PCSNode
	{
	public:
		GameObject(GraphicsObject *graphicsObject);

		// Big four
		GameObject() = delete;
		GameObject(const GameObject &) = delete;
		GameObject &operator=(GameObject &) = delete;
		virtual ~GameObject();

		virtual void Draw();
		virtual void Update(AnimTime currTime) = 0;

		GraphicsObject *GetGraphicsObject();
		Matrix *GetWorld();

		void SetWorld(Matrix *_pWorld);
		void DrawEnable();
		void DrawDisable();

	protected:
		void baseUpdateBoundingSphere();

		Matrix *poWorld;
		Sphere *pSphere;
		GraphicsObject *poGraphicsObject;
		bool mDrawEnable;
	};
}

#endif

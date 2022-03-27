#ifndef SIMPLE_GAME_OBJECT_RIGID_H
#define SIMPLE_GAME_OBJECT_RIGID_H

#include "GameObject.h"
#include "MathEngine.h"
#include "ShaderObject.h"
#include "Mesh.h"
#include "GraphicsObject.h"
#include "PCSNode.h"
#include "AnimTime.h"

namespace Azul
{
	class GameObjectRigid : public GameObject
	{
	public:
		GameObjectRigid(GraphicsObject *pGraphicsObject);

		// Big four
		GameObjectRigid() = delete;
		GameObjectRigid(const GameObjectRigid &) = delete;
		GameObjectRigid &operator=(GameObjectRigid &) = delete;
		virtual ~GameObjectRigid() = default;

		virtual void Update(AnimTime currTime);

	private:  

	};
}

#endif


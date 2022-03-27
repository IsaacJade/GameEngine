#ifndef SIMPLE_GAME_OBJECT_ANIM_H
#define SIMPLE_GAME_OBJECT_ANIM_H

#include "GameObject.h"
#include "MathEngine.h"
#include "ShaderObject.h"
#include "Mesh.h"
#include "GraphicsObject.h"
#include "PCSNode.h"
#include "AnimTime.h"

namespace Azul
{
	class GameObjectAnim : public GameObject
	{
	public:
		GameObjectAnim(GraphicsObject *pGraphicsObject);

		// Big four
		GameObjectAnim() = delete;
		GameObjectAnim(const GameObjectAnim &) = delete;
		GameObjectAnim &operator=(GameObjectAnim &) = delete;
		virtual ~GameObjectAnim() = default;

		virtual void Update(AnimTime currTime);
		virtual void SetIndex(int i) = 0;

	public:
		int index;

	};
}

#endif


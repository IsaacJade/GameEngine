#ifndef GAME_OBJECT_ANIM_SKIN_H
#define GAME_OBJECT_ANIM_SKIN_H

#include "GameObjectAnim.h"
#include "MathEngine.h"
#include "ShaderObject.h"
#include "Mesh.h"
#include "GraphicsObject.h"
#include "PCSNode.h"
#include "AnimTime.h"
#include "Bone.h"

namespace Azul
{
	class Skeleton;

	class GameObjectAnimSkin : public GameObjectAnim
	{
	public:
		GameObjectAnimSkin(GraphicsObject* graphicsObject, Skeleton* pSkel, SSBO* pSSBO);

		// Big four
		GameObjectAnimSkin() = delete;
		GameObjectAnimSkin(const GameObjectAnimSkin&) = delete;
		GameObjectAnimSkin& operator=(GameObjectAnimSkin&) = delete;
		virtual ~GameObjectAnimSkin();

		virtual void Update(AnimTime currTime);

		virtual void SetIndex(int i) override;

	private:

		void privUpdateBoneWorldArray();

	public:
		SSBO* pSSBOBoneWorld;
		SSBO* pSSBOBonelocal;
		Matrix* poBoneWorld;
		Skeleton* p_skeleton;
	};
}

#endif


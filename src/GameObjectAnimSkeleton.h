#ifndef GAME_OBJECT_ANIM_SKELETON_H
#define GAME_OBJECT_ANIM_SKELETON_H

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
	class SSBO;

	class GameObjectAnimSkeleton : public GameObjectAnim
	{
	public:
		GameObjectAnimSkeleton(GraphicsObject *graphicsObject, SSBO *pBoneResult);

		// Big four
		GameObjectAnimSkeleton() = delete;
		GameObjectAnimSkeleton(const GameObjectAnimSkeleton &) = delete;
		GameObjectAnimSkeleton &operator=(GameObjectAnimSkeleton &) = delete;
		virtual ~GameObjectAnimSkeleton();

		virtual void Update(AnimTime currTime);

		void SetScale(float sx, float sy, float sz);
		void SetQuat(float qx, float qy, float qz, float qw);
		void SetTrans(float x, float y, float z);

		void SetScale(Vect &r);
		void SetQuat(Quat &r);
		void SetTrans(Vect &r);

		virtual void SetIndex(int i) override;

		Matrix GetBoneOrientation(void) const;
		void SetBoneOrientation(const Matrix &);

	private:
		void privUpdate(AnimTime currTime);

	public:   // add accessors later
		Vect *poScale;
		Quat *poQuat;
		Vect *poTrans;
		Matrix *poLocal;
		//int index;
		SSBO *pSSBOBoneResult;
		Matrix *poBoneOrientation;
	};
}

#endif


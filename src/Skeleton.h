#ifndef SKELETON_H
#define SKELETON_H

#include "GameObjectAnim.h"
#include "Bone.h"

namespace Azul
{
	class SSBO;

	class Skeleton
	{
	public:
		struct Data
		{
			int  index;
			int  parentIndex;
			char name[64];
		};


		Skeleton(unsigned int numBones, Mesh* pmesh);
		Skeleton(const Skeleton &) = delete;
		Skeleton &operator = (const Skeleton &) = delete;
		~Skeleton();
		void DisableDraw();
		GameObjectAnim *GetFirstBone();
		GameObjectAnim* FindBoneByIndex(int index);
		void SetWithTrans(SSBO* pSSBOBone, Vect trans, Quat quat, Vect scale, Texture::Name name);

		int      numBones;
		Data** _Skeltable;
		SSBO* pBoneHierarchy;
		int		width;
	private:
		Mesh* pMesh;
		GameObjectAnim *pFirstBone;

	};
}

#endif


#ifndef GAME_OBJECT_MAN_H
#define GAME_OBJECT_MAN_H

#include "GameObject.h"
#include "PCSTree.h"
#include "AnimTime.h"

namespace Azul
{

	// Singleton
	class GameObjectMan
	{
	public:
		static void Add(GameObject* pObj, GameObject *pParent);
		static void Draw(void);
		static void Update(AnimTime currentTime);
		static GameObject *GetRoot(void);
		static PCSTree *GetPCSTree();
		static void TurnBoundingSphere();
		static void Clean();

		static void Create();
		static void Destroy();

		~GameObjectMan();
		GameObjectMan(const GameObjectMan &) = delete;
		GameObjectMan &operator=(const GameObjectMan &) = delete;

	private:
		GameObjectMan();

		static GameObjectMan* privGetInstance();

		// data
		PCSTree* poRootTree;
	};

}

#endif


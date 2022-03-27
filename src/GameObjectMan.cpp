#include "MeshNull.h"
#include "GraphicsObject_Null.h"

#include "GameObject.h"
#include "GameObjectRigid.h"
#include "GameObjectMan.h"

#include "BoundingSphereGameObject.h"
#include "PCSTreeForwardIterator.h"

#include "MeshNodeMan.h"
#include "ShaderMan.h"

namespace Azul
{
	void GameObjectMan::Add(GameObject *pObj, GameObject *pParent)
	{
		assert(pObj);
		assert(pParent);

		// Get singleton
		GameObjectMan *pGOM = GameObjectMan::privGetInstance();

		// insert object to root
		pGOM->poRootTree->Insert(pObj, pParent);
	}

	PCSTree *GameObjectMan::GetPCSTree()
	{
		// Get singleton
		GameObjectMan *pGOM = GameObjectMan::privGetInstance();
		assert(pGOM);

		return pGOM->poRootTree;
	}

	GameObject *GameObjectMan::GetRoot()
	{
		// Get singleton
		GameObjectMan *pGOM = GameObjectMan::privGetInstance();
		assert(pGOM);

		GameObject *pGameObj = (GameObject *)pGOM->poRootTree->GetRoot();
		assert(pGameObj);

		return pGameObj;
	}

	void GameObjectMan::Create()
	{
		// Get singleton
		GameObjectMan *pGOM = GameObjectMan::privGetInstance();
		assert(pGOM);
		AZUL_UNUSED_VAR(pGOM);
	}

	void GameObjectMan::Destroy()
	{
		// Get singleton
		GameObjectMan* pGOM = GameObjectMan::privGetInstance();
		assert(pGOM);

		PCSTree* pTree = pGOM->poRootTree;
		PCSNode* pNode = nullptr;

		PCSTreeForwardIterator pForIter(pTree->GetRoot());
		pNode = pForIter.First();
		PCSNode* pTmp = nullptr;
		while (!pForIter.IsDone())
		{
			pTmp = pForIter.CurrentItem();

			pNode = pForIter.Next();
			delete pTmp;

		}
	}

	void GameObjectMan::Update(AnimTime currentTime)
	{
		GameObjectMan* pGOM = GameObjectMan::privGetInstance();
		assert(pGOM);

		PCSNode* pRootNode = pGOM->poRootTree->GetRoot();
		assert(pRootNode);

		PCSTreeForwardIterator pForwardIter(pRootNode);
		PCSNode* pNode = pForwardIter.First();

		GameObject* pGameObj = nullptr;

		while (!pForwardIter.IsDone())
		{
			assert(pNode);
			// Update the game object
			pGameObj = (GameObject*)pNode;

			pGameObj->Update(currentTime);
			

			pNode = pForwardIter.Next();
		}
	}

	void GameObjectMan::TurnBoundingSphere()
	{
		GameObjectMan* pGOM = GameObjectMan::privGetInstance();
		assert(pGOM);

		PCSNode* pRootNode = pGOM->poRootTree->GetRoot();
		assert(pRootNode);

		PCSTreeForwardIterator pForwardIter(pRootNode);
		PCSNode* pNode = pForwardIter.First();

		GameObject* pGameObj = nullptr;

		while (!pForwardIter.IsDone())
		{
			assert(pNode);
			// Update the game object
			pGameObj = (GameObject*)pNode;

			char     pName[21];
			pGameObj->GetName(pName, 21);
			if(strcmp("BoundingSphere_GREEN",pName) == 0)
			{
				auto* pSphere = (BoundingSphereGameObject*)pGameObj;
				pSphere->render = !pSphere->render;
			}

			pNode = pForwardIter.Next();
		}
	}

	void GameObjectMan::Clean()
	{
	}

	void GameObjectMan::Draw()
	{
		GameObjectMan* pGOM = GameObjectMan::privGetInstance();
		assert(pGOM);

		PCSNode* pRootNode = pGOM->poRootTree->GetRoot();
		assert(pRootNode);

		PCSTreeForwardIterator pForwardIter(pRootNode);
		PCSNode* pNode = pForwardIter.First();

		GameObject* pGameObj = nullptr;

		while (!pForwardIter.IsDone())
		{
			assert(pNode);
			// Update the game object
			pGameObj = (GameObject*)pNode;
			pGameObj->Draw();

			pNode = pForwardIter.Next();
		}
	}

	GameObjectMan::GameObjectMan()
	{
		// Create the root node (null object)
		MeshNull* pMesh = new MeshNull(nullptr);
		//TODO: Check this is corret or not
		MeshNodeMan::Add("null", pMesh);

		ShaderObject* pShader = ShaderMan::Add(ShaderObject::Name::NULL_SHADER, "nullRender", ShaderObject::Type::UNITINTIALIZED);
		GraphicsObject_Null* pGraphicsObject = new GraphicsObject_Null(pMesh, pShader);
		GameObjectRigid *pGameRoot = new GameObjectRigid(pGraphicsObject);
		pGameRoot->SetName("GameObject_Root");

		// Create the tree
		this->poRootTree = new PCSTree();
		assert(this->poRootTree);

		// Attach the root node
		this->poRootTree->Insert(pGameRoot, this->poRootTree->GetRoot());
	}

	GameObjectMan::~GameObjectMan()
	{
		
		delete this->poRootTree;
	}

	GameObjectMan* GameObjectMan::privGetInstance(void)
	{
		// This is where its actually stored (BSS section)
		static GameObjectMan gom;
		return &gom;
	}

}


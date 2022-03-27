
#include "PCSTreeForwardIterator.h"

#include "GraphicsObject_Null.h"
#include "GraphicsObject_TextureLight.h"
#include "GraphicsObject_FlatTexture.h"
#include "GraphicsObject_SkinTexture.h"
#include "GameObjectMan.h"
#include "GameObjectBasic.h"
#include "GameObjectRigid.h"
#include "GameObjectAnimSkeleton.h"
#include "GameObjectAnimSkin.h"
#include "ShaderMan.h"
#include "Skeleton.h"

#include "GraphicsObject_SkinTextureLight.h"
#include "MeshNodeMan.h"
#include "ModelNodeMan.h"
#include "SSBO.h"


namespace Azul
{
	Skeleton::Skeleton(unsigned int numBones, Mesh* pmesh)
		:numBones(numBones),
	_Skeltable(nullptr),
	pMesh(pmesh),
	pFirstBone(nullptr)
	
	{
		_Skeltable = new Skeleton::Data * [numBones];
		for (unsigned int i = 0; i < numBones; ++i)
		{
			_Skeltable[i] = new Skeleton::Data;
		}
	}
	Skeleton::~Skeleton()
	{
		for (int i = 0; i < numBones; ++i)
		{
			delete _Skeltable[i];
		}
		delete[] _Skeltable;
		delete pBoneHierarchy;
	}

	void Skeleton::DisableDraw()
	{
		GameObjectAnim* pObj = this->GetFirstBone();

		// TODO - add test bed for an interator of a tree with only one node
			PCSTreeForwardIterator pIter(pObj);
			PCSNode* pNode = pIter.First();
			GameObjectAnim* pGameObj = nullptr;

			// walks the anim node does the pose for everything that
			while (pNode != nullptr)
			{
				assert(pNode);
				// Update the game object
				pGameObj = (GameObjectAnim*)pNode;
				pGameObj->DrawDisable();
				pNode = pIter.Next();
			}
		
	}

	GameObjectAnim *Skeleton::GetFirstBone()
	{
		assert(pFirstBone);
		return this->pFirstBone;
	}

	void Skeleton::SetWithTrans(SSBO* pSSBOBone, Vect trans, Quat quat, Vect scale, Texture::Name name)
	{
		// Load Shader 
		ShaderObject* pShaderObject_texture = ShaderMan::Find(ShaderObject::Name::TEXTURE_SIMPLE);
		assert(pShaderObject_texture);

		ShaderObject* pShaderObject_SkinTexture = ShaderMan::Find(ShaderObject::Name::SKIN_TEXTURE_LIGHT);
		assert(pShaderObject_SkinTexture);
		assert(this->_Skeltable);


		assert(pMesh);

		// GraphicsObject for a specific instance
		GraphicsObject* pGraphicsObj;

		//---------------------------------------
		// ChickenBot
		//---------------------------------------

		// Add A Dummy pivot object
		Mesh* pMeshNull = MeshNodeMan::Find("null");
		assert(pMeshNull);

		ShaderObject* pShaderNull = ShaderMan::Find(ShaderObject::Name::NULL_SHADER);
		assert(pShaderNull);

		pGraphicsObj = new GraphicsObject_Null(pMeshNull, pShaderNull);
		GameObjectBasic* pPivot = new GameObjectBasic(pGraphicsObj);
		pPivot->SetName("Pivot");
		pPivot->DrawDisable();

		pPivot->SetQuat(quat);
		pPivot->SetScale(scale.x(), scale.y(), scale.z());
		pPivot->SetTrans(trans.x(), trans.y(), trans.z());
		pPivot->delta_x = 0.003f;

		GameObjectMan::Add(pPivot, GameObjectMan::GetRoot());

		Vect color(1.50f, 1.50f, 1.50f, 1.0f);
		Vect pos(1, 1, 1);
		// Animation
		GameObjectAnim* pGameObj;
		// Skin Mesh
		GameObjectAnimSkin* pGameSkin;
		GraphicsObject_SkinTextureLight* pGraphicsSkin;

		pGraphicsSkin = new GraphicsObject_SkinTextureLight(pMesh, pShaderObject_SkinTexture, name, color, pos);
		pGameSkin = new GameObjectAnimSkin(pGraphicsSkin, this, pSSBOBone);

		// Glue the bone array together - Hack
		pGraphicsSkin->SetBoneWorld(pGameSkin->poBoneWorld, this->numBones);

		GameObjectMan::Add(pGameSkin, pPivot);
		pGameSkin->SetName("ChickenSkin");

		// Root animation is treated differently
		for (int i = 0; i < 1; i++)
		{
			pGraphicsObj = new GraphicsObject_Null(pMeshNull, pShaderNull);
			pGameObj = new GameObjectAnimSkeleton(pGraphicsObj, pSSBOBone);
			pGameObj->SetIndex(this->_Skeltable[i]->index);
			pGameObj->SetName(this->_Skeltable[i]->name);

			GameObjectMan::Add(pGameObj, pPivot);
			this->pFirstBone = pGameObj;
		}

		for (int i = 1; i < this->numBones; i++)
		{
			pGraphicsObj = new GraphicsObject_Null(pMeshNull, pShaderNull);
			pGameObj = new GameObjectAnimSkeleton(pGraphicsObj, pSSBOBone);
			pGameObj->SetIndex(this->_Skeltable[i]->index);
			pGameObj->SetName(this->_Skeltable[i]->name);

			GameObjectAnim* pParent = this->FindBoneByIndex(this->_Skeltable[i]->parentIndex);
			assert(pParent);
			GameObjectMan::Add(pGameObj, pParent);
		}
	}

	GameObjectAnim* Skeleton::FindBoneByIndex(int index)
	{
		GameObjectAnim* pFound = nullptr;

		GameObjectAnim* pObj = this->GetFirstBone();

		if (pObj->index == index)
		{
			pFound = pObj;
		}
		else
		{
			PCSTreeForwardIterator pIter(pObj);
			PCSNode* pNode = pIter.First();
			GameObjectAnim* pGameObj = nullptr;

			// walks the anim node does the pose for everything that
			while (pNode != nullptr)
			{
				assert(pNode);
				// Update the game object
				pGameObj = (GameObjectAnim*)pNode;
				if (pGameObj->index == index)
				{
					pFound = pGameObj;
					break;
				}
				pNode = pIter.Next();
			}
		}

		return pFound;
	}


}


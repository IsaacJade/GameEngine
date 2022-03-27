#include "Game.h"
#include "MathEngine.h"
#include "GameObjectAnimSkin.h"
#include "GraphicsObject.h"
#include "Mesh.h"
#include "Anim.h"
#include "AnimController.h"
#include "SSBO.h"
#include "ShaderMan.h"


namespace Azul
{
	GameObjectAnimSkin::GameObjectAnimSkin(GraphicsObject* pGraphicsObject, Skeleton* pSkel, SSBO* pssbo)
		: GameObjectAnim(pGraphicsObject),
	p_skeleton(pSkel)
	{
		assert(pGraphicsObject);
		this->poBoneWorld = new Matrix[pSkel->numBones]();
		this->pSSBOBoneWorld = new SSBO();
		this->pSSBOBoneWorld->Set(pSkel->numBones, sizeof(Matrix), poBoneWorld);
		assert(this->poBoneWorld);
		this->pSSBOBonelocal = pssbo;
	}

	GameObjectAnimSkin::~GameObjectAnimSkin()
	{
		delete this->pSSBOBoneWorld;
		delete[] this->poBoneWorld;
	}

	void GameObjectAnimSkin::privUpdateBoneWorldArray()
	{
		// Update the world array
		// Since its already been updated... thankyou hack man
		// we can just add the world matrix into our array

		for (int i = 0; i < p_skeleton->numBones; i++)
		{
			GameObjectAnim* pGameObject = p_skeleton->FindBoneByIndex(i);
			this->poBoneWorld[i] = *pGameObject->GetWorld();
		}
	}

	void GameObjectAnimSkin::Update(AnimTime currentTime)
	{
		this->privUpdateBoneWorldArray();
		AZUL_UNUSED_VAR(currentTime);
		// Lock and load the shader...
		ShaderObject* pComputeShader = ShaderMan::Find(ShaderObject::Name::COMPUTE_WORLD);

		pComputeShader->SetActive();

		this->pSSBOBonelocal->Bind(0);
		p_skeleton->pBoneHierarchy->Bind(1);
		pSSBOBoneWorld->Bind(2);

		glUniform1i(pComputeShader->GetLocation("boneCount"), p_skeleton->numBones);
		glUniform1i(pComputeShader->GetLocation("hierarchyDepth"), p_skeleton->width);

		// Dispatch
		pComputeShader->Dispatch(1, 1, 1);
		glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);

	}


	void GameObjectAnimSkin::SetIndex(int i)
	{
		AZUL_UNUSED_VAR(i);
		assert(false);
	}
}


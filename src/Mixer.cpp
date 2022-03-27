
#include "Mixer.h"
#include "MathApp.h"
#include "SSBO.h"
#include "ShaderMan.h"

namespace Azul
{
	void Mixer::Blend(SSBO *pResult,
		 SSBO*pA,
		 SSBO*pB,
		const float tS,
		int numBones)
	{
		// Lock and load the shader...
		ShaderObject *pComputeShader = ShaderMan::Find(ShaderObject::Name::COMPUTE_MIXER);

		pComputeShader->SetActive();

		pA->Bind(0);
		pB->Bind(1);
		pResult->Bind(2);

		glUniform1f(pComputeShader->GetLocation("ts"), tS);
		glUniform1i(pComputeShader->GetLocation("boneCount"), numBones);

		// Dispatch
		pComputeShader->Dispatch((unsigned int)(numBones / 8), 1, 1);

		// Block Waiting for stages to complete
		glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);

	}


}


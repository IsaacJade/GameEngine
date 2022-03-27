#include "GameObjectFont.h"

#include "GlyphMan.h"
#include "MathEngine.h"
#include "GraphicsObject.h"

namespace Azul
{
	GameObjectFont::GameObjectFont(GraphicsObject_Font* pGraphicsObject, const char* pMes)
		: GameObject(pGraphicsObject)
	{
		assert(pGraphicsObject != 0);

		this->angle = 0.0f;
		this->posX = pGraphicsObject->origPosX;
		this->posY = pGraphicsObject->origPosY;
		this->scaleX = 1.0f;
		this->scaleY = 1.0f;
		this->pMessage = my_string(pMes);
	}

	GameObjectFont::~GameObjectFont()
	{
	}

	void GameObjectFont::updateMessage(const char* pMes)
	{
		this->pMessage = my_string(pMes);
	}


	void GameObjectFont::Update(AnimTime currentTime)
	{
		AZUL_UNUSED_VAR(currentTime);

		// Goal: update the world matrix
		Matrix Scale(Matrix::Scale::XYZ, this->scaleX, this->scaleY, 1.0f);
		Matrix Rot(Matrix::Rot1::Z, this->angle);
		Matrix Trans(Matrix::Trans::XYZ, this->posX, this->posY, 0.0f);

		*this->poWorld = Scale * Rot * Trans;

		// push to graphics object
		this->poGraphicsObject->SetWorld(*this->poWorld);
	}

	void GameObjectFont::Draw()
	{
		GraphicsObject* pGraphicsObj = this->GetGraphicsObject();
		GraphicsObject_Font* p_font = (GraphicsObject_Font*)pGraphicsObj;
		assert(pGraphicsObj);

		if (this->mDrawEnable)
		{
			float xTmp = this->posX;
			float yTmp = this->posY;

			float xEnd = this->posX;

			for (unsigned int i = 0; i < this->pMessage.length(); i++)
			{
				int key = int(pMessage[i]);

				Glyph* pGlyph = GlyphMan::Find(key);
				assert(pGlyph);

				xTmp = xEnd + (pGlyph->pSubRect.width * this->scaleX / 2 );
				Matrix Scale(Matrix::Scale::XYZ, this->scaleX, this->scaleY, 1.0f);
				Matrix Rot(Matrix::Rot1::Z, this->angle);
				Matrix Trans(Matrix::Trans::XYZ, xTmp, yTmp, 0.0f);

				*this->poWorld = Scale * Rot * Trans;

				// push to graphics object
				this->poGraphicsObject->SetWorld(*this->poWorld);
				p_font->updateGlyph(pGlyph);

				pGraphicsObj->Render();

				// move the starting to the next character
				xEnd = pGlyph->pSubRect.width * this->scaleX / 2 + xTmp;
			}
		}
	}

}
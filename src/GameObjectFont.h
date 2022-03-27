#pragma once
#include "MathEngine.h"
#include "GameObject.h"
#include "GraphicsObject_Font.h"
#include "my_string.h"
namespace Azul
{
	class GameObjectFont : public GameObject
	{
	public:

		GameObjectFont(GraphicsObject_Font* graphicsObject, const char* pMes);

		// Big four
		GameObjectFont() = delete;
		GameObjectFont(const GameObjectFont&) = delete;
		GameObjectFont& operator=(GameObjectFont&) = delete;
		virtual ~GameObjectFont() override;
		void updateMessage(const char* pMes);

		virtual void Update(AnimTime currentTime) override;
		virtual void Draw() override;

	public:
		float scaleX;
		float scaleY;
		float posX;
		float posY;
		float angle;
		my_string pMessage;
	};
}

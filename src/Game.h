//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef GAME_H
#define GAME_H

#include "sb7.h"
#include "Engine.h"
#include "AnimTimer.h"

namespace Azul
{
	class Game : public Engine
	{
	public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

	public:
	// constructor
	Game(const char *windowName, const int Width, const int Height);

		Game() = delete;
		Game(const Game &) = delete;
		Game &operator=(const Game &) = delete;
		virtual ~Game();

	private:
	virtual void Initialize() override;
	virtual void LoadContent() override;
	virtual void Update(float currentTime) override;
	virtual void Draw() override;
	virtual void UnLoadContent() override;
	virtual void ClearBufferFunc() override;

	public:

	// Nice and Clean
		AnimTimer	intervalTimer;
		AnimTimer	globalTimer;
	};
}

#endif

// --- End of File ---


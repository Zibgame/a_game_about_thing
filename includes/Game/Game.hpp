#pragma once

#include "raylib.h"
#include "Player.hpp"

class Game
{
	public:
		Game(int height, int width);
		~Game();

		LaunchGame();
		
	private:
		
		int		_WinWidth;
		int		_WinHeight;
		
		Player	_Player;
		
		InitGame();
		InitWindow();
		InitTexture();
}
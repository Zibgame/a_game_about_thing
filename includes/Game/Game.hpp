#pragma once

#include "raylib.h"
#include "Player.hpp"

class Game
{
	public:
		Game(int height, int width);
		~Game();

		bool	LaunchGame();
		
	private:
		
		int		_WinWidth;
		int		_WinHeight;
		
		Player	_Player;
		
		bool	InitGame();
		bool	MainLoop();
		bool	InitTexture();
		bool	GameInitWindow();
};
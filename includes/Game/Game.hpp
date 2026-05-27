#pragma once

#include <iostream>
#include "raylib.h"
#include "Player.hpp"
#include "Map.hpp"


class Game
{
	public:
		Game(int height, int width);
		Game(int height, int width, int seed);
		~Game();

		bool	LaunchGame();
		
	private:
		
		int		_WinWidth;
		int		_WinHeight;
		int		_fps;
		
		Map		_Map;
		Player	_Player;
		
		bool	InitGame();
		bool	MainLoop();
		bool	InitTexture();
		bool	GameInitWindow();
};
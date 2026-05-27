#include "Game.hpp"
#include <iostream>

Game::Game(int height, int width)
{
    _WinHeight = height;
    _WinWidth = width;
}

Game::~Game(void)
{
    
}

Game::InitGame(void)
{
    InitTexture();
    InitWindow();
}

Game::InitWindow(void)
{
    std::cout << "Window init\n"; 
}

Game::InitTexture(void)
{
    std::cout << "Texture init\n";
}

Game::LaunchGame(void)
{
    std::cout << "Launching Game\n";
}
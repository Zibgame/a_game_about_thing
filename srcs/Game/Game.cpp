#include "Game.hpp"
#include <iostream>

Game::Game(int height, int width) : _WinWidth(width), _WinHeight(height), _Player(width / 2, height / 2)
{
}

Game::~Game(void)
{
    
}

bool Game::InitGame(void)
{
    InitTexture();
    GameInitWindow();
    return true;
}

bool Game::GameInitWindow(void)
{
    std::cout << "Window init\n";
    InitWindow(_WinWidth, _WinHeight, "A game about thing");
    return true;
}

bool Game::InitTexture(void)
{
    std::cout << "Texture init\n";
    return true;
}

bool Game::LaunchGame(void)
{
    std::cout << "Launching Game\n";

    // InitTexture();
    GameInitWindow();
    MainLoop();
    return true;
}

bool Game::MainLoop(void)
{
    while (true)
    {
        if (WindowShouldClose())
            break ;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        _Player.draw();
        EndDrawing();
    }
    return true;
}
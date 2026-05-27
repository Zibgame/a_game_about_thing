#include "Game.hpp"
#include <iostream>

Game::Game(int width, int height) : _WinWidth(width), _WinHeight(height), _Player(width / 2, height / 2) , _fps(244)
{
    SetTargetFPS(_fps);
    GameInitWindow();
    _Player.loadTexture();
}

Game::~Game(void)
{
    
}

bool Game::InitGame(void)
{
    InitTexture();
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
    MainLoop();
    return true;
}

bool Game::MainLoop(void)
{
    while (true)
    {
        if (IsKeyDown(KEY_ESCAPE))
            break ;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        _Player.Update();
        _Player.draw();
        EndDrawing();
    }
    return true;
}
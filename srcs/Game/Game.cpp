#include "Game.hpp"

Game::Game(int width, int height) : _WinWidth(width), _WinHeight(height), _Map(15141, 6), _Player(width / 2, height / 2) , _fps(244)
{
    SetTargetFPS(_fps);
    GameInitWindow();
    _Player.loadTexture();
    _Map.InitTexture();
    _Map.CreateMap();
}

Game::Game(int height, int width, int seed) : _WinWidth(width), _WinHeight(height), _Map(seed, 4), _Player(width / 2, height / 2) , _fps(244)
{
    SetTargetFPS(_fps);
    GameInitWindow();
    _Player.loadTexture();
    _Map.CreateMap();
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
        _Map.DrawMap();
        EndDrawing();
    }
    return true;
}
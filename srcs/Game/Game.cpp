#include "Game.hpp"

Game::Game(int width, int height) : _WinWidth(width), _WinHeight(height), _Map(15141, 5), _Player(200, 200) , _fps(244)
{
    SetTargetFPS(_fps);
    GameInitWindow();
    _Player.loadTexture();
    _Map.InitTexture();
    _Map.CreateMap(_Player.getTileX(), _Player.getTileY());
}

Game::Game(int height, int width, int seed) : _WinWidth(width), _WinHeight(height), _Map(seed, 5), _Player(width / 2, height / 2) , _fps(244)
{
    SetTargetFPS(_fps);
    GameInitWindow();
    _Player.loadTexture();
    _Map.CreateMap(_Player.getTileX(), _Player.getTileY());
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
    _Player.Move(0, 0);
    while (true)
    {
        if (IsKeyDown(KEY_ESCAPE))
        break ;
        BeginDrawing();
        BeginMode2D(_Player.getCamera());
        ClearBackground(RAYWHITE);
        _Player.Update();
        if (_Player.getChunkX() != _Player.getTileX() / 16 || _Player.getChunkY() != _Player.getTileY() / 16)
        {
            int ChunkDiffX = _Player.getTileX() / 16 - _Player.getChunkX();
            int ChunkDiffY = _Player.getTileY() / 16 - _Player.getChunkY();

            _Player.setChunkX(_Player.getChunkX() + ChunkDiffX);
            _Player.setChunkY(_Player.getChunkY() + ChunkDiffY);
            _Map.Update(
                ChunkDiffX,
                ChunkDiffY,
                _Player.getTileX(),
                _Player.getTileY()
            );
        }
        _Map.DrawMap();
        _Player.draw();
        EndMode2D();
        EndDrawing();
    }
    return true;
}

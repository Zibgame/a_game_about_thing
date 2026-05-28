#pragma once

#include "raylib.h"
#include "camera.hpp"
#include <iostream>

#define SPEED 500.0

class Player
{
    public:
        Player(float x, float y);
        int         getTileX(void) const;
        int         getTileY(void) const;
        int         getChunkX(void) const;
        int         getChunkY(void) const;
        void        setChunkX(int x);
        void        setChunkY(int y);
        void	    draw() const;
        void	    loadTexture();
        void	    Move(float x, float y);
        void        Update(void);
        Camera2D    getCamera(void);
        ~Player();

    private:
        int     _ChunkX;
        int     _ChunkY;

        int     _TileX;
        int     _TileY;

        float  _x;
        float  _y;

        float  _scale;

        camera      _Camera;
        Texture2D   _texture;
};
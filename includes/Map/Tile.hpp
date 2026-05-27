#pragma once

#include "raylib.h"

class Tile
{
    public:
        Tile(char biome, short obstacle);
        ~Tile();

        inline void    DrawTile(int x, int y) const;
        
    private:
        
        char        _Biome;
        short       _Obstacle; // id(tree, mineral, building, convoyer, ...)
        
        double      _Scale;
        Texture2D   _Texture;

        void    InitTexture();
};
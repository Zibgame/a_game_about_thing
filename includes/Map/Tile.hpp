#pragma once

#include "raylib.h"

class Tile
{
    public:
        Tile(char biome, short obstacle, short textureId);
        ~Tile();
        
        short       TextureId;
        double      Scale;
    private:
        
        char        _Biome;
        short       _Obstacle; // id(tree, mineral, building, convoyer, ...)
        
};
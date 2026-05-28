#pragma once

#include <vector>
#include "Tile.hpp"

#define CHUNK_SIZE 16

class Chunk
{
    public:
        Chunk();
        ~Chunk();
        
        Tile    *GetTile(int x, int y);
        void    SetTile(int x, int y, Tile *newTile);
        void    SetTile(int x, int y, char biome, short obstacle);
        void    DrawChunk(int x, int y, std::vector<Texture2D> &_GroundTextures);
        
    private:
        
        std::vector<Tile *>   _TileMap;

};
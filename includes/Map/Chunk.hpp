#pragma once

#include <vector>
#include "Tile.hpp"

#define CHUNK_SIZE 16

class Chunk
{
    public:
        Chunk(int x, int y);
        ~Chunk();
        
        Tile    *GetTile(int x, int y);
        void    SetTile(int x, int y, Tile *newTile);
        void    SetTile(int x, int y, char biome, short obstacle);
        void    DrawChunk(std::vector<Texture2D> &_GroundTextures);
        
        Chunk   &operator=( Chunk &other );
    private:
        
        int _ChunkX;
        int _ChunkY;
        std::vector<Tile *>   _TileMap;

};
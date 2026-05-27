#include "Chunk.hpp"
#include <string>

Chunk::Chunk(void)
{
    
}

Chunk::~Chunk(void)
{

}
        
Tile    Chunk::GetTile(int x, int y)
{
    int index = y * CHUNK_SIZE + x;

    if (index >= _TileMap.size() || index < 0)
        throw   std::string("IndexError\n");
    return (_TileMap.at(index));
}

void    Chunk::SetTile(int x, int y, Tile newTile)
{
    int index = y * CHUNK_SIZE + x;

    if (index > _TileMap.size() || index < 0)
        throw   std::string("IndexError\n");
    else if (index == _TileMap.size())
        _TileMap.push_back(newTile);
    else
        _TileMap.insert(_TileMap.begin()+index, newTile);
}

void    Chunk::SetTile(int x, int y, char biome, short obstacle)
{
    int index = y * CHUNK_SIZE + x;

    if (index > _TileMap.size() || index < 0)
        throw   std::string("IndexError\n");
    
    Tile newTile(biome, obstacle);
    if (index == _TileMap.size())
        _TileMap.push_back(newTile);
    else
        _TileMap.insert(_TileMap.begin()+index, newTile);
}

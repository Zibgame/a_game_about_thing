#include "Chunk.hpp"
#include <string>
#include <iostream>

Chunk::Chunk(void)
{

}

Chunk::~Chunk(void)
{
    for (int i = 0; i < _TileMap.size(); i++)
    {
        delete _TileMap[i];
    }
}
        
Tile    *Chunk::GetTile(int x, int y)
{
    int index = y * CHUNK_SIZE + x;

    if (index >= _TileMap.size() || index < 0)
        throw   std::string("IndexError\n");
    return (_TileMap.at(index));
}

void    Chunk::SetTile(int x, int y, Tile *newTile)
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
    
    Tile *newTile = new Tile(biome, obstacle, (int)(biome / 5));
    if (index == _TileMap.size())
        _TileMap.push_back(newTile);
    else
        _TileMap.insert(_TileMap.begin()+index, newTile);
}

void    Chunk::DrawChunk(int startX, int startY, std::vector<Texture2D> &_GroundTextures)
{
    for (int y = 0; y < CHUNK_SIZE; y++)
    {
        for (int x = 0; x < CHUNK_SIZE; x++)
        {
            int Id = _TileMap[y * CHUNK_SIZE + x]->TextureId;
            int Scale = _TileMap[y * CHUNK_SIZE + x]->Scale;

            if (!_GroundTextures[Id].id)
                return ;
            Rectangle	src;
            Rectangle	dest;
            Vector2		origin;

            src.x = 0;
            src.y = 0;
            src.width = _GroundTextures[Id].width;
            src.height = _GroundTextures[Id].height;

            dest.x = x * 16;
            dest.y = y * 16;
            dest.width = _GroundTextures[Id].width * Scale;
            dest.height = _GroundTextures[Id].height * Scale;

            origin.x = dest.width / 2;
            origin.y = dest.height / 2;

            DrawTexturePro(
                _GroundTextures[Id],
                src,
                dest,
                origin,
                0.0f,
                WHITE
            );
        }
    }
}

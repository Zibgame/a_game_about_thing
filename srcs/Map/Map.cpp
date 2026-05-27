#include "Map.hpp"

Map::Map(int seed, int renderDistance) : _Seed(seed), _RenderDistance(renderDistance)
{
    _NoiseGenerator.SetNoiseType(FastNoiseLite::NoiseType_Cellular);
    _NoiseGenerator.SetCellularReturnType(FastNoiseLite::CellularReturnType_CellValue);
}

Map::~Map()
{

}

void    Map::CreateMap(void)
{
    int lineSize = CHUNK_SIZE * _RenderDistance;
    std::vector<float> noiseData(lineSize * lineSize);

    for (int y = 0; y < CHUNK_SIZE; y++)
    {
        for (int x = 0; x < CHUNK_SIZE; x++)
        {
            noiseData[x + y * CHUNK_SIZE] = _NoiseGenerator.GetNoise((float)x, (float)y);
            // std::cout << noiseData[x];
            // if (x + 1 != lineSize)
            //     std::cout << ", ";
        }
        // std::cout << std::endl;
    }
    CreateChunk(noiseData);
}
void    Map::DrawMap(void) const
{
     for (int y = 0; y < _RenderDistance; y++)
    {
        for (int x = 0; x < _RenderDistance; x++)
        {
            noiseData[x + y * CHUNK_SIZE] = _NoiseGenerator.GetNoise((float)x, (float)y);
            // std::cout << noiseData[x];
            // if (x + 1 != lineSize)
            //     std::cout << ", ";
        }
        // std::cout << std::endl;
    }
}

void   Map::CreateChunk(const std::vector<float> &TileValues)
{
    Chunk   newChunk;

    for (int y = 0; y < CHUNK_SIZE; y++)
    {
        for (int x = 0; x < CHUNK_SIZE; x++)
        {
            Tile    newTile((char)((TileValues[y * CHUNK_SIZE + x] + 1) * 20), 0);

            newChunk.SetTile(x, y, newTile);
        }
    }
    _Map.push_back(newChunk);
}

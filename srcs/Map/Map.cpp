#include "Map.hpp"

Map::Map(int seed, int renderDistance) : _Seed(seed), _RenderDistance(renderDistance)
{
    _NoiseGenerator.SetSeed(_Seed);
    _NoiseGenerator.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    // _NoiseGenerator.SetNoiseType(FastNoiseLite::NoiseType_Cellular);
    _NoiseGenerator.SetCellularReturnType(FastNoiseLite::CellularReturnType_CellValue);
}

Map::~Map()
{
    for (int i = 0; i < _GroundTextures.size(); i++)
    {
        UnloadTexture(_GroundTextures[i]);
    }
}

// j'ai peur de cette fonction
void    Map::CreateMap(void)
{
    for (int j = 0; j < _RenderDistance; j++)
    {
        for (int i = 0; i < _RenderDistance; i++)
        {
            int lineSize = CHUNK_SIZE * _RenderDistance;
            std::vector<float> noiseData(lineSize * lineSize);
        
            for (int y = 0; y < CHUNK_SIZE; y++)
            {
                for (int x = 0; x < CHUNK_SIZE; x++)
                {
                    noiseData[x + y * CHUNK_SIZE] = _NoiseGenerator.GetNoise((float)(x + 16 * i), (float)(y + 16 * j));
                }
            }
            CreateChunk(noiseData);

        }
    }

}
void    Map::DrawMap(void)
{
    // _Map[0]->DrawChunk(0, 0, _GroundTextures);
    
    for (int y = 0; y < _RenderDistance; y++)
    {
        for (int x = 0; x < _RenderDistance; x++)
        {
            _Map[y * _RenderDistance + x]->DrawChunk(x * CHUNK_SIZE * 8, y * CHUNK_SIZE * 8, _GroundTextures);
        }
    }
}

void   Map::CreateChunk(const std::vector<float> &TileValues)
{
    Chunk   *newChunk = new Chunk();

    for (int y = 0; y < CHUNK_SIZE; y++)
    {
        for (int x = 0; x < CHUNK_SIZE; x++)
        {
            Tile    *newTile = new Tile((char)((TileValues[y * CHUNK_SIZE + x] + 1) * 20), 0, (short)(((TileValues[y * CHUNK_SIZE + x] / 2 + 0.5) * 4)));

            newChunk->SetTile(x, y, newTile);
        }
    }
    _Map.push_back(newChunk);
}

void	Map::InitTexture(void)
{
    _GroundTextures.push_back(LoadTexture("assets/Ground/Grass.png"));
    _GroundTextures.push_back(LoadTexture("assets/Ground/Dirt.png"));
    _GroundTextures.push_back(LoadTexture("assets/Ground/Sand.png"));
    _GroundTextures.push_back(LoadTexture("assets/Ground/Water.png"));
}
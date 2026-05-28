#include "Map.hpp"

Map::Map(int seed, int renderDistance) : _Seed(seed), _RenderDistance(renderDistance)
{
    _NoiseGenerator.SetSeed(_Seed);
    _NoiseGenerator.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
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
void    Map::CreateMap(int playerSpawnTileX, int playerSpawnTileY)
{
    int ChunkPosX, ChunkPosY;
    
    ChunkPosX = playerSpawnTileX / 16 - 2;
    ChunkPosY = playerSpawnTileY / 16 - 2;
    for (int j = ChunkPosY; j < ChunkPosY + _RenderDistance; j++)
    {
        for (int i = ChunkPosX; i < ChunkPosX + _RenderDistance; i++)
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
            CreateChunk(i, j, noiseData);
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
            _Map[y * _RenderDistance + x]->DrawChunk(_GroundTextures);
        }
    }
}

void   Map::CreateChunk(int x, int y, const std::vector<float> &TileValues)
{
    Chunk   *newChunk = new Chunk(x, y);

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

void    Map:: Update(int ChunkDiffX, int ChunkDiffY, int playerActualTileX, int playerActualTileY)
{
    if (ChunkDiffX == -1)
        NewRowLeft(playerActualTileX, playerActualTileY);
    else if (ChunkDiffX == 1)
        NewRowRight(playerActualTileX, playerActualTileY);
    if (ChunkDiffY == 1)
        NewLineBottom(playerActualTileX, playerActualTileY);
    else if (ChunkDiffY == -1)
        NewLineTop(playerActualTileX, playerActualTileY);

}

void    Map::NewRowLeft(int playerActualTileX, int playerActualTileY)
{
    int ChunkPosX, ChunkPosY;
    
    ChunkPosX = playerActualTileX / 16 - 2;
    ChunkPosY = playerActualTileY / 16 - 2;
    for (int j = ChunkPosY; j < ChunkPosY + _RenderDistance; j++)
    {
        int lineSize = CHUNK_SIZE * _RenderDistance;
        std::vector<float> noiseData(lineSize * lineSize);
        
        for (int y = 0; y < CHUNK_SIZE; y++)
        {
            for (int x = 0; x < CHUNK_SIZE; x++)
            {
                noiseData[x + y * CHUNK_SIZE] = _NoiseGenerator.GetNoise((float)(x + 16 * ChunkPosX), (float)(y + 16 * j));
            }
        }
        Chunk   *newChunk = new Chunk(ChunkPosX, j);
        
        for (int y = 0; y < CHUNK_SIZE; y++)
        {
            for (int x = 0; x < CHUNK_SIZE; x++)
            {
                Tile    *newTile = new Tile((char)((noiseData[y * CHUNK_SIZE + x] + 1) * 20), 0, (short)(((noiseData[y * CHUNK_SIZE + x] / 2 + 0.5) * 4)));
                
                newChunk->SetTile(x, y, newTile);
            }
        }
        _Map.erase(_Map.begin()+(j - ChunkPosY) * _RenderDistance + _RenderDistance - 1);
        _Map.insert(_Map.begin()+(j - ChunkPosY) * _RenderDistance, newChunk);
    }
}

void    Map::NewRowRight(int playerActualTileX, int playerActualTileY)
{
    int ChunkPosX, ChunkPosY;
    
    ChunkPosX = playerActualTileX / 16 + 2;
    ChunkPosY = playerActualTileY / 16 - 2;
    for (int j = ChunkPosY; j < ChunkPosY + _RenderDistance; j++)
    {
        int lineSize = CHUNK_SIZE * _RenderDistance;
        std::vector<float> noiseData(lineSize * lineSize);
    
        for (int y = 0; y < CHUNK_SIZE; y++)
        {
            for (int x = 0; x < CHUNK_SIZE; x++)
            {
                noiseData[x + y * CHUNK_SIZE] = _NoiseGenerator.GetNoise((float)(x + 16 * ChunkPosX), (float)(y + 16 * j));
            }
        }
        Chunk   *newChunk = new Chunk(ChunkPosX, j);

        for (int y = 0; y < CHUNK_SIZE; y++)
        {
            for (int x = 0; x < CHUNK_SIZE; x++)
            {
                Tile    *newTile = new Tile((char)((noiseData[y * CHUNK_SIZE + x] + 1) * 20), 0, (short)(((noiseData[y * CHUNK_SIZE + x] / 2 + 0.5) * 4)));

                newChunk->SetTile(x, y, newTile);
            }
        }
        _Map.erase(_Map.begin()+(j - ChunkPosY) * _RenderDistance);
        _Map.insert(_Map.begin()+(j - ChunkPosY) * _RenderDistance + _RenderDistance - 1, newChunk);
    }
}

void    Map::NewLineTop(int playerActualTileX, int playerActualTileY)
{
    int ChunkPosX, ChunkPosY;
    
    ChunkPosX = playerActualTileX / 16 - 2;
    ChunkPosY = playerActualTileY / 16 - 2;
    for (int i = ChunkPosX; i < ChunkPosX + _RenderDistance; i++)
    {
        int lineSize = CHUNK_SIZE * _RenderDistance;
        std::vector<float> noiseData(lineSize * lineSize);
    
        for (int y = 0; y < CHUNK_SIZE; y++)
        {
            for (int x = 0; x < CHUNK_SIZE; x++)
            {
                noiseData[x + y * CHUNK_SIZE] = _NoiseGenerator.GetNoise((float)(x + 16 * i), (float)(y + 16 * ChunkPosY));
            }
        }
        Chunk   *newChunk = new Chunk(i, ChunkPosY);

        for (int y = 0; y < CHUNK_SIZE; y++)
        {
            for (int x = 0; x < CHUNK_SIZE; x++)
            {
                Tile    *newTile = new Tile((char)((noiseData[y * CHUNK_SIZE + x] + 1) * 20), 0, (short)(((noiseData[y * CHUNK_SIZE + x] / 2 + 0.5) * 4)));

                newChunk->SetTile(x, y, newTile);
            }
        }
        _Map.erase(_Map.begin()+(i - ChunkPosX) + (_RenderDistance - 1) * _RenderDistance);
        _Map.insert(_Map.begin()+(i - ChunkPosX), newChunk);
    }
}
void    Map::NewLineBottom(int playerActualTileX, int playerActualTileY)
{
    int ChunkPosX, ChunkPosY;
    
    ChunkPosX = playerActualTileX / 16 - 2;
    ChunkPosY = playerActualTileY / 16 + 2;
    for (int i = 0; i < 5; i++)
        _Map.erase(_Map.begin());
    for (int i = ChunkPosX; i < ChunkPosX + _RenderDistance; i++)
    {
        int lineSize = CHUNK_SIZE * _RenderDistance;
        std::vector<float> noiseData(lineSize * lineSize);
    
        for (int y = 0; y < CHUNK_SIZE; y++)
        {
            for (int x = 0; x < CHUNK_SIZE; x++)
            {
                noiseData[x + y * CHUNK_SIZE] = _NoiseGenerator.GetNoise((float)(x + 16 * i), (float)(y + 16 * ChunkPosY));
            }
        }
        Chunk   *newChunk = new Chunk(i, ChunkPosY);

        for (int y = 0; y < CHUNK_SIZE; y++)
        {
            for (int x = 0; x < CHUNK_SIZE; x++)
            {
                Tile    *newTile = new Tile((char)((noiseData[y * CHUNK_SIZE + x] + 1) * 20), 0, (short)(((noiseData[y * CHUNK_SIZE + x] / 2 + 0.5) * 4)));

                newChunk->SetTile(x, y, newTile);
            }
        }
        // _Map.erase(_Map.begin()+(i - ChunkPosX));
        _Map.push_back(newChunk);
    }
}
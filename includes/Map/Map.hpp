#pragma once

#include <cmath>
#include <vector>
#include <iostream>
#include "FastNoiseLite.h"
#include "Chunk.hpp"

class Map
{
    public:
		enum GroundTexture
		{
			Grass,
			Dirt,
			Sand,
			Water
		};

        Map(int seed, int renderDistance);
        ~Map();

        void    CreateMap(int playerSpawnTileX, int playerSpawnTileY);
        void    DrawMap();
        void    Update(int ChunkDiffX, int ChunkDiffY, int playerActualTileX, int playerActualTileY);
        void	InitTexture();

    private:

        int _OffsetX;
        int _OffsetY;

        int _RenderDistance;
        int _Seed;

        FastNoiseLite       _NoiseGenerator;
        std::vector<Chunk *>  _Map;

        std::vector<Texture2D>   _GroundTextures;

        void    CreateChunk(int x, int y, const std::vector<float> &TileValues);
        void    NewRowLeft(int playerActualTileX, int playerActualTileY);
        void    NewRowRight(int playerActualTileX, int playerActualTileY);
        void    NewLineTop(int playerActualTileX, int playerActualTileY);
        void    NewLineBottom(int playerActualTileX, int playerActualTileY);

};
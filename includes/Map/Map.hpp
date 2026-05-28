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
        void	InitTexture();

        void    NewRowLeft(int playerSpawnTileX, int playerSpawnTileY);
        void    NewRowRight();
        void    NewLineTop();
        void    NewLineBottom();

    private:

        int _OffsetX;
        int _OffsetY;

        int _RenderDistance; // max 6?
        int _Seed;

        FastNoiseLite       _NoiseGenerator;
        std::vector<Chunk *>  _Map;

        std::vector<Texture2D>   _GroundTextures;

        void   CreateChunk(int x, int y, const std::vector<float> &TileValues);

};
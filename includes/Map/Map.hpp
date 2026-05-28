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

        void    CreateMap();
        void    DrawMap();
        void	InitTexture();

    private:

        int _OffsetX;
        int _OffsetY;

        int _RenderDistance; // max 6?
        int _Seed;

        FastNoiseLite       _NoiseGenerator;
        std::vector<Chunk *>  _Map;

        std::vector<Texture2D>   _GroundTextures;

        void   CreateChunk(const std::vector<float> &TileValues);

};
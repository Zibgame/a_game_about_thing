#pragma once

#include <cmath>
#include <vector>
#include <iostream>
#include "FastNoiseLite.h"
#include "Chunk.hpp"

class Map
{
    public:
        Map(int seed, int renderDistance);
        ~Map();

        void    CreateMap();
        void    DrawMap() const;

    private:

        int _OffsetX;
        int _OffsetY;

        int _RenderDistance; // max 6?
        int _Seed;

        FastNoiseLite       _NoiseGenerator;
        std::vector<Chunk>  _Map;

        void   CreateChunk(const std::vector<float> &TileValues);

};
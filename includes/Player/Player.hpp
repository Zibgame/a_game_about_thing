#pragma once

#include "raylib.h"

class Player
{
    public:
        Player(double x, double y);
        ~Player();

    private:
        double _x;
        double _y;

        Texture2D _texture;
};
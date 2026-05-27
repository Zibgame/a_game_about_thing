#pragma once

#include "raylib.h"

class Player
{
    public:
        Player(double x, double y);
        void	draw() const;
        ~Player();

    private:
        double _x;
        double _y;

        int _scale = 1;

        Texture2D _texture;
};
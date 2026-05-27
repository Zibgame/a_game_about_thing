#pragma once

#include "raylib.h"

class Player
{
    public:
        Player(double x, double y);
        void	draw() const;
        void	loadTexture();
        ~Player();

    private:
        double _x;
        double _y;

        double _scale = 0.01;

        Texture2D _texture;
};
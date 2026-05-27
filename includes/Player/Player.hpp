#pragma once

#include "raylib.h"
#include <iostream>

#define SPEED 500.0

class Player
{
    public:
        Player(double x, double y);
        void	draw() const;
        void	loadTexture();
        void	Move(double x, double y);
        void    Update(void);
        ~Player();

    private:
        double _x;
        double _y;

        double _scale;

        Texture2D _texture;
};
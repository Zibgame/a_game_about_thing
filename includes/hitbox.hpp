#pragma once

#include "raylib.h"

class hitbox
{
    private:
        Rectangle _rect;

    public:
        hitbox();
        hitbox(float x, float y, float width, float height);

        void set_position(float x, float y);

        Rectangle get_rect() const;

        void draw() const;

        bool collide(const hitbox &other) const;

        bool collide(Rectangle rect) const;

        ~hitbox();
};
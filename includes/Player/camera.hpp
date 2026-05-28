#pragma once

#include "raylib.h"

class camera
{
    public:
        camera(Vector2 target);
        void update(Vector2 target);
        Camera2D get_camera();
        Vector2 get_target();
        ~camera();

    private:
        Camera2D _camera;
};
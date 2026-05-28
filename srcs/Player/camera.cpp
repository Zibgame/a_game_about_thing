#include "camera.hpp"

camera::camera(Vector2 target)
{
    this->_camera.target = target;

    this->_camera.offset = {
        GetScreenWidth() / 2.0f,
        GetScreenHeight() / 2.0f,
    };

    this->_camera.rotation = 0.0f;
    this->_camera.zoom = 1.0f;
}

Camera2D camera::get_camera()
{
    return (this->_camera);
}

Vector2 camera::get_target()
{
    return (this->_camera.target);
}

void camera::update(Vector2 target)
{
    this->_camera.offset = {
        GetScreenWidth() / 2.0f,
        GetScreenHeight() / 2.0f, 
    };
    this->_camera.target = target;
}

camera::~camera()
{
}
#include "hitbox.hpp"

hitbox::hitbox(float x, float y, float width, float height)
{
    this->_rect.x = x;
    this->_rect.y = y;
    this->_rect.width = width;
    this->_rect.height = height;
}

hitbox::hitbox()
{
    _rect.x = 0;
    _rect.y = 0;
    _rect.width = 0;
    _rect.height = 0;
}

void hitbox::set_position(float x, float y)
{
    this->_rect.x = x;
    this->_rect.y = y;
}

Rectangle hitbox::get_rect() const
{
    return (this->_rect);
}

void hitbox::draw() const
{
    DrawRectangleLinesEx(this->_rect, 1, RED);
}

bool hitbox::collide(const hitbox &other) const
{
    return (CheckCollisionRecs(this->_rect, other.get_rect()));
}


hitbox::~hitbox()
{

}
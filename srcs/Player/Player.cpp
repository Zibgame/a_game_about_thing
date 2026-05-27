#include "Player.hpp"

Player::Player(double x, double y)
{
	_x = x;
	_y = y;
	_scale = 1;
	_texture = LoadTexture("assets/Player/player.png");
}

void	Player::draw() const
{
	Rectangle	src;
	Rectangle	dest;
	Vector2		origin;

	src.x = 0;
	src.y = 0;
	src.width = _texture.width;
	src.height = _texture.height;

	dest.x = _x;
	dest.y = _y;
	dest.width = _texture.width * _scale;
	dest.height = _texture.height * _scale;

	origin.x = dest.width / 2;
	origin.y = dest.height / 2;

	DrawTexturePro(
		_texture,
		src,
		dest,
		origin,
		0.0f,
		WHITE
	);
}

Player::~Player()
{
	UnloadTexture(_texture);
}

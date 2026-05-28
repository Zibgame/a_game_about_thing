#include "Player.hpp"

Player::Player(float x, float y) : _x(x), _y(y), _scale(1.0f), _Camera(Vector2{0, 0})
{
	_texture = LoadTexture("assets/Player/player.png");
}

void	Player::loadTexture()
{
	_texture = LoadTexture("assets/Player/player.png");
}

void	Player::draw() const
{
	if (!_texture.id)
		return ;
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

void	Player::Move(float x, float y)
{
	_x += x;
	_y += y;
	_Camera.update(Vector2{_x, _y});
}

Camera2D    Player::getCamera(void)
{
	return (_Camera.get_camera());
}

Player::~Player()
{
	if (_texture.id)
		UnloadTexture(_texture);
}

void    Player::Update(void)
{
	double	delta;

	delta = GetFrameTime();

	if (IsKeyDown(KEY_D))
		Move(SPEED * delta, 0);
	if (IsKeyDown(KEY_A))
		Move(-SPEED * delta, 0);
	if (IsKeyDown(KEY_W))
		Move(0, -SPEED * delta);
	if (IsKeyDown(KEY_S))
		Move(0, SPEED * delta);
}
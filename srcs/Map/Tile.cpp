#include "Tile.hpp"

Tile::Tile(char biome, short obstacle) : _Biome(biome), _Obstacle(obstacle), _Scale(0.05)
{
    InitTexture();
}

Tile::~Tile()
{
    if (_Texture.id)
		UnloadTexture(_Texture);
}

inline void    Tile::DrawTile(int x, int y) const
{
	if (!_Texture.id)
		return ;
	Rectangle	src;
	Rectangle	dest;
	Vector2		origin;

	src.x = 0;
	src.y = 0;
	src.width = _Texture.width;
	src.height = _Texture.height;

	dest.x = x;
	dest.y = y;
	dest.width = _Texture.width * _Scale;
	dest.height = _Texture.height * _Scale;

	origin.x = dest.width / 2;
	origin.y = dest.height / 2;

	DrawTexturePro(
		_Texture,
		src,
		dest,
		origin,
		0.0f,
		WHITE
	);
}

void    Tile::InitTexture()
{
    _Texture = LoadTexture("assets/Player/player.png");
}
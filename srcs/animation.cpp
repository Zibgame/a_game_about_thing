#include "animation.hpp"

animation::animation(
    const char  *texture_path,
    int         frame_count,
    int         frame_w,
    int         frame_h,
    float       fps,
    bool        loop
)
    : _frame_count(frame_count),
      _current_frame(0),
      _fps(fps),
      _frame_w(frame_w),
      _frame_h(frame_h),
      _timer(0.0f),
      _loop(loop),
      _finished(false)
{
    _texture = LoadTexture(texture_path);
}

void animation::update()
{
    // Si play-once et déjà terminée, on ne bouge plus
    if (_finished)
        return;

    _timer += GetFrameTime();

    if (_timer >= 1.0f / _fps)
    {
        _timer = 0.0f;

        if (_loop)
        {
            _current_frame = (_current_frame + 1) % _frame_count;
        }
        else
        {
            // Avance jusqu'à la dernière frame et s'arrête
            if (_current_frame < _frame_count - 1)
                _current_frame++;
            else
                _finished = true;
        }
    }
}

void animation::reset()
{
    _current_frame  = 0;
    _timer          = 0.0f;
    _finished       = false;
}

bool animation::is_finished() const
{
    return _finished;
}

Rectangle animation::get_frame_rect() const
{
    return Rectangle{
        (float)(_current_frame * _frame_w),
        0.0f,
        (float)_frame_w,
        (float)_frame_h
    };
}

Texture2D animation::get_texture() const
{
    return _texture;
}

animation::~animation()
{
    UnloadTexture(_texture);
}
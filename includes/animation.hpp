#pragma once

#include "raylib.h"

class animation
{
    public:
        animation(
            const char  *texture_path,
            int         frame_count,
            int         frame_w,
            int         frame_h,
            float       fps,
            bool        loop = true
        );
        ~animation();

        void        update();
        void        reset();
        bool        is_finished() const;
        Texture2D   get_texture() const;
        Rectangle   get_frame_rect() const;

    private:
        Texture2D   _texture;
        int         _frame_count;
        int         _current_frame;
        float       _fps;
        int         _frame_w;
        int         _frame_h;
        float       _timer;
        bool        _loop;
        bool        _finished;
};
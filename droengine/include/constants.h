#ifndef ENGINE_CONSTANTS_H
#define ENGINE_CONSTANTS_H

#include "core/vector2d.h"

namespace Engine {
    // CORE
    extern const unsigned int MAX_FPS;
    extern const float DELTA_TIME;

    extern const int    WINDOW_HEIGHT;
    extern const int    WINDOW_WIDTH;

    // CAMERA MOVEMENT
    extern const Vector2D<int> WINDOW_CENTER;
    extern const float         CAMERA_FOLLOW_DIST;

    // SPRITE COMPONENT
    extern const int    SPRITE_SIZE_PX;
    extern const int    PIXEL_PER_UNIT;
    extern const size_t SPRITE_LAYERS;

    // ANIMATOR COMPONENT
    extern const int TICKS_PER_FRAME;
}

#endif // ENGINE_CONSTANTS_H
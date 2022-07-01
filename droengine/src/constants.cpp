#include "../include/constants.h"

namespace Engine {
    // CORE
    extern const unsigned int MAX_FPS    { 30 };
    extern const float        DELTA_TIME { 1.0f / MAX_FPS };

    extern const int WINDOW_WIDTH  { 1280 };
    extern const int WINDOW_HEIGHT { 720  };

    // CAMERA MOVEMENT
    extern const Vector2D<int> WINDOW_CENTER { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
    extern const float         CAMERA_FOLLOW_DIST { 50.0f };
    
    // SPRITE COMPONENT
    extern const int    SPRITE_SIZE_PX { 64 };
    extern const int    PIXEL_PER_UNIT { 4 };
    extern const size_t SPRITE_LAYERS  { 5 };

    // ANIMATOR COMPONENT
    extern const int TICKS_PER_FRAME { MAX_FPS / 10 };
}
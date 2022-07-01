#include "../../include/core/framerate.h"
#include "../../include/constants.h"

#include <SDL2/SDL.h>

#include <iostream>

namespace Engine
{
    void stabilize_framerate()
    {
        static const Uint32 tick_ms       { 1000 / MAX_FPS };
        static       Uint32 previous_time { 0 };

        Uint32 delta = SDL_GetTicks() - previous_time;

        if (delta < tick_ms)
        {
            SDL_Delay(tick_ms - delta);
        }

        previous_time = SDL_GetTicks();
    }
}
#include "../../include/core/input.h"

namespace Engine {
    Vector2D<float> get_user_direction() {
        Vector2D<float> dir { 0, 0 };

        Uint8 const *keys = SDL_GetKeyboardState(nullptr);

        if (keys[SDL_SCANCODE_W])
            dir.y -= 1;
        if(keys[SDL_SCANCODE_S])
            dir.y += 1;
        if(keys[SDL_SCANCODE_A])
            dir.x -= 1;
        if(keys[SDL_SCANCODE_D])
            dir.x += 1;
        
        return dir;
    }
}
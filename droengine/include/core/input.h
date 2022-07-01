#ifndef ENGINE_INPUT_H
#define ENGINE_INPUT_H

#include "vector2d.h"

#include <SDL2/SDL.h>

namespace Engine {
    /**
     * @brief Get the player's movement vector by reading WASD-input.
     * 
     * @return Vector2D<float> Movement vector of the player.
     */
    Vector2D<float> get_user_direction();
}

#endif // ENGINE_INPUT_H
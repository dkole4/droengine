#ifndef GAME_H
#define GAME_H

#include "../../droengine/include/core/window.h"

#include <SDL2/SDL.h>
#include <iostream>

using namespace Engine;

namespace Game
{
    class GameState 
    {
    public:
        GameState();
        ~GameState();

        /**
         * @brief Updates current scene of the game.
         * 
         */
        void update();
    private:
        Window main_window {};
    };
} // namespace Game


#endif // GAME_H
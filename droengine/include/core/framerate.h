#ifndef ENGINE_FRAMERATE_H
#define ENGINE_FRAMERATE_H

namespace Engine
{
    /**
     * @brief Stabilizes the framerate of the game
     * by using delays between game ticks.
     * 
     */
    void stabilize_framerate();
}

#endif // ENGINE_FRAMERATE_H
#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H

#include "../components/sprite.h"
#include "../core/vector2d.h"

#include <SDL2/SDL.h>
#include <iostream>


namespace Engine
{
    using namespace Components;

    /**
     * @brief Class representing a game window.
     * 
     */
    class Window
    {
    public:
        Window();
        ~Window();

        Window(Window&&) = delete;
        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;

        /**
         * @brief Initializes a window using its height and width.
         * 
         * @param w Width of the window.
         * @param h Height of the window.
         * @return int 0 if initialization was successful, 1 otherwise.
         */
        int  init_window(const int w, const int h);

        /**
         * @brief Clears the window surface.
         * 
         */
        void clear();

        /**
         * @brief Updates the window surface with sprites
         * that were drawn to it this tick.
         * 
         */
        void update_surface();

        /**
         * @brief Draws a GameObject on the screen using its Sprite component.
         * 
         * @param sprite Sprite component of a GameObject.
         * @param camera_offset Current camera offset of the scene.
         */
        void draw(
            const Sprite&        sprite,
            const Vector2D<int>& camera_offset
        );

        /**
         * @brief Draws a TileLine of a TiledTexture object.
         * 
         * @param sprite Sprite component of a TiledTexture.
         * @param tile_line Line of tile positions to draw.
         * @param camera_offset Current camera offset of the scene.
         */
        void draw_tile_line(
            const Sprite&        sprite,
            const TileLine&      tile_line,
            const Vector2D<int>& camera_offset
        );
        
        SDL_Event      event;     // Current window event.
    private:
        int width_  { 0 };
        int height_ { 0 };

        SDL_Window  *window;      
        SDL_Surface *surface;
    };
} // namespace Engine

#endif // ENGINE_WINDOW_H
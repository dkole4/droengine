#ifndef ENGINE_IMAGE_LOADER_H
#define ENGINE_IMAGE_LOADER_H

#include <memory>

#include <SDL2/SDL_surface.h>

namespace Engine 
{
    namespace Util
    {
        /**
         * @brief Loads a BMP file as a SDL_Surface.
         * 
         * @param path Path to the file.
         * @return std::shared_ptr<SDL_Surface> Pointer to loaded surface.
         */
        std::shared_ptr<SDL_Surface> load_bmp(char const *path);

        /**
         * @brief Loads a PNG file as a SDL_Surface.
         * 
         * @param path Path to the file.
         * @return std::shared_ptr<SDL_Surface> Pointer to loaded surface.
         */
        std::shared_ptr<SDL_Surface> load_png(char const *path);
    }
}

#endif // ENGINE_IMAGE_LOADER_H
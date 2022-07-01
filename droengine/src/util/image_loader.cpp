#include "../../include/util/image_loader.h"

namespace Engine
{
    namespace Util
    {
        std::shared_ptr<SDL_Surface> load_bmp(char const *path)
        {
            SDL_Surface *image_surface = SDL_LoadBMP(path);

            if (!image_surface)
                return nullptr;
            
            return { image_surface, SDL_FreeSurface };
        }
    }
}
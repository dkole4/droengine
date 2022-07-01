#include "../../include/core/window.h"
#include "../../include/prefabs/tiled_texture.h"

namespace Engine
{
    Window::Window():
        event(),
        window(nullptr),
        surface(nullptr)
    {}

    Window::~Window()
    {
        if (surface)
            SDL_FreeSurface(surface);
        if (window)
            SDL_DestroyWindow(window);
    }

    int Window::init_window(const int w, const int h)
    {
        window = SDL_CreateWindow(
            "DroEngine",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            w, h,
            0
        );
        
        width_ = w;
        height_ = h;

        if (!window)
        {
            std::cout << "Failed to create window\n";
            std::cout << "SDL2 Error: " << SDL_GetError() << '\n';
            return -1;
        }

        surface = SDL_GetWindowSurface(window);

        if (!surface)
        {
            std::cout << "Failed to get the surface from the window\n";
            std::cout << "SDL2 Error: " << SDL_GetError() << '\n';
            return -1;
        }

        return 0;
    }

    void Window::clear()
    {
        SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0, 0, 0));
    }

    void Window::update_surface()
    {
        SDL_UpdateWindowSurface(window);
    }

    void Window::draw(
        const Sprite&        sprite,
        const Vector2D<int>& camera_offset
    ) {
        auto dest_rect { sprite.dest_rect };
        dest_rect.x -= camera_offset.x;
        dest_rect.y -= camera_offset.y;

        if (0 <= dest_rect.x && dest_rect.x < width_ &&
            0 <= dest_rect.y && dest_rect.y < height_)
        {
            SDL_BlitSurface(sprite.image.get(), &sprite.src_rect, surface, &dest_rect);
        }
    }

    void Window::draw_tile_line(
        const Sprite&        sprite,
        const TileLine&      tile_line,
        const Vector2D<int>& camera_offset
    ) {
        SDL_Rect dest_rect;
        dest_rect.w = SPRITE_SIZE_PX;
        dest_rect.h = SPRITE_SIZE_PX;

        auto src_rect   { &sprite.src_rect };
        auto sprite_img { sprite.image.get() };

        dest_rect.x = tile_line.start.x - camera_offset.x;
        dest_rect.y = tile_line.start.y - camera_offset.y;

        for (int i = 0; i < tile_line.length; ++i)
        {
            if (0 <= dest_rect.x && dest_rect.x < width_ &&
                0 <= dest_rect.y && dest_rect.y < height_)
            {
                SDL_BlitSurface(sprite_img, src_rect, surface, &dest_rect);
            }
            dest_rect.x += SPRITE_SIZE_PX;
        }
    }
} // namespace Engine
#ifndef ENGINE_SPRITE_H
#define ENGINE_SPRITE_H

#include "../core/vector2d.h"
#include "../core/box_rect.h"
#include "animator.h"

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>

#include <memory>

namespace Engine {
    namespace Components {
        enum class SpriteType
        {
            SINGLE_SPRITE,
            SPRITESHEET
        };

        /**
         * @brief Class representing the positions of objects
         * in a line of tiles, used mostly in the TiledTexture prefab.
         * 
         */
        class TileLine
        {
        public:
            Vector2D<int> start;
            int           length;
        };

        /**
         * @brief Sprite component for GameObjects.
         * 
         */
        class Sprite
        {
        public:
            Sprite(
                const char *img_path,
                SpriteType  sprite_type,
                size_t      render_layer = 1
            );
            ~Sprite() = default;

            /**
             * @brief Initializes the SDL_Rects of the
             * component based on the type of Sprite.
             * 
             */
            void init_rect();

            /**
             * @brief Adjusts SDL_Rects of the component based
             * on the current position of the GameObject.
             * 
             * @param obj_pos Current position of the
             * GameObject the component is attached to.
             */
            void adjust_rect(const Vector2D<float>& obj_pos);

            /**
             * @brief Adjusts src_rect using GameObject's animator component.
             * 
             * @param animator Animator component of the GameObject
             * the component is attached to.
             */
            void use_animation_rect(Animator& animator);

            /**
             * @brief Get the destination rectangle of the Sprite as a BoxRect.
             * 
             * @return BoxRect Destination rectangle.
             */
            BoxRect get_dest_box_rect() const;

            SpriteType                   sprite_type;

            // GameObject's sprite or spritesheet.
            std::shared_ptr<SDL_Surface> image;

            // Source rect, represents the rect on the sprite/spritesheet
            // to blit on the window surface this tick.
            SDL_Rect                     src_rect;

            // Destination rect, represents the rect in the game world space
            // that GameObject's sprite would be located at.
            SDL_Rect                     dest_rect;

            // Render layer of the sprite, used to determine whether to show
            // the sprite before other sprites with higher render layer.
            // Current allowed layers are 0-4.
            size_t                       render_layer;
        };

    }
}

#endif // ENGINE_SPRITE_H
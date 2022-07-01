#include "../../include/components/sprite.h"
#include "../../include/util/image_loader.h"
#include "../../include/constants.h"

#include <iostream>

namespace Engine {
    namespace Components {

        Sprite::Sprite(
            const char *img_path,
            SpriteType  sprite_type,
            size_t      render_layer
        ):
            sprite_type(sprite_type),
            image(nullptr),
            src_rect(),
            dest_rect(),
            render_layer(render_layer)
        {
            if (img_path)
            {
                image = Util::load_bmp(img_path);
                if (!image)
                {
                    std::cerr << "FAILED TO LOAD SPRITE: " << img_path << '\n';
                }
                else
                {
                    std::cout << "LOADED SPRITE: " << img_path << '\n';
                    init_rect();
                } 
            }
        }

        void Sprite::init_rect()
        {
            if (sprite_type == SpriteType::SINGLE_SPRITE)
            {
                src_rect = {0, 0, image->w, image->h};
            }
            else
            {
                src_rect = {0, 0, SPRITE_SIZE_PX, SPRITE_SIZE_PX};
            }
            dest_rect = src_rect;
        }

        void Sprite::adjust_rect(const Vector2D<float>& obj_pos)
        {
            // Setting the position of the sprite according to the object's
            // position and making the sprite attached to engine unit grid.
            dest_rect.x = static_cast<int>(obj_pos.x);
            dest_rect.x -= dest_rect.x % PIXEL_PER_UNIT;

            dest_rect.y = static_cast<int>(obj_pos.y);
            dest_rect.y -= dest_rect.y % PIXEL_PER_UNIT;

            // {
            //     int hidden_width = static_cast<int>(-obj_pos.x);
            //     hidden_width -= hidden_width % PIXEL_PER_UNIT;

            //     dest_rect.w = sprite_dim.w - hidden_width;
            //     src_rect.x = hidden_width;
            //     src_rect.w = dest_rect.w;
            // }
        }

        void Sprite::use_animation_rect(Animator& animator)
        {
            src_rect = animator.get_next_frame();
        }

        BoxRect Sprite::get_dest_box_rect() const
        {
            return {
                Vector2D<float>(dest_rect.x, dest_rect.y),
                Vector2D<float>(dest_rect.x + dest_rect.w, dest_rect.y + dest_rect.h)
            };
        }
    }
}
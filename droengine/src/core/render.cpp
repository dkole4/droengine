#include "../../include/core/render.h"

#include "../../include/constants.h"
#include "../../include/core/box_rect.h"
#include "../../include/core/gameobject.h"
#include "../../include/prefabs/tiled_texture.h"

namespace Engine
{
    using namespace Prefabs;

    RenderOrder get_render_order(
        Scene& scene,
        const Vector2D<int>& camera_offset
    ) {
        RenderOrder render_order {};
        init_render_order_vector(render_order);     

        // Current screen rect in game world space.
        const BoxRect screen_rect { 
            camera_offset, 
            camera_offset + Vector2D<int>(WINDOW_WIDTH, WINDOW_HEIGHT)
        };

        int y_ind {};
        for (size_t i = 0; i < scene.get_object_count(); ++i)
        {
            auto& obj { scene.get_scene_object(i) };
            
            if (obj->get_gameobject_type() == GameObjectType::TiledTexture)
            {
                auto  tile = std::dynamic_pointer_cast<TiledTexture>(obj);
                const auto& tile_area { tile->get_covered_area() };
                if (tile_area.is_overlapped(screen_rect))
                {
                    y_ind = tile->position.y - camera_offset.y;
                    if (y_ind < 0) y_ind = 0;
                }
            }
            else 
            {
                const auto& dest_box_rect { obj->sprite.get_dest_box_rect() };
                if (screen_rect.is_overlapped(dest_box_rect))
                {
                    y_ind = dest_box_rect.top - camera_offset.y;
                    if (y_ind < 0) y_ind = 0;
                }
            }

            if (y_ind >= 0)
            {
                render_order
                    [ obj->sprite.render_layer ]
                    [ static_cast<size_t>(y_ind) ]
                        .push_back(i);
            }
        }

        return render_order;
    }

    void init_render_order_vector(RenderOrder& render_order)
    {
        for (size_t i = 0; i < SPRITE_LAYERS; ++i)
        {
            render_order.push_back({});
            for (int j = 0; j < WINDOW_HEIGHT; ++j)
            {
                render_order[i].push_back({});
            }
        }
    }
}
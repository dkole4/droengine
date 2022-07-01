#include "../../include/prefabs/tiled_texture.h"

namespace Engine
{
    namespace Prefabs
    {
        TiledTexture::TiledTexture(
            Sprite                sprite,
            std::vector<TileLine> tile_lines,
            BoxCollider           collider,
            Rigidbody             rigidbody
        ):
            GameObject(
                {0, 0},
                sprite,
                collider,
                rigidbody,
                GameObjectType::TiledTexture
            ),
            tile_lines_(tile_lines),
            covered_area_({0, 0})
        {
            // Initialize covered area using
            // stored tile lines and their positions.
            for (size_t i = 0; i < tile_lines_.size(); ++i)
            {
                auto& line { tile_lines_[i] };
                if (i == 0)
                {
                    covered_area_ = { 
                        line.start, 
                        line.start + Vector2D<int>(line.length * SPRITE_SIZE_PX,
                                                   SPRITE_SIZE_PX)
                    };
                }
                else
                {
                    covered_area_.adjust_rect(
                        line.start, 
                        line.start + Vector2D<int>(line.length * SPRITE_SIZE_PX,
                                                   SPRITE_SIZE_PX)
                    );
                }
            }
        }

        const std::vector<TileLine>& TiledTexture::get_tile_lines()
        {
            return tile_lines_;
        }

        const BoxRect& TiledTexture::get_covered_area()
        {
            return covered_area_;
        }

        void TiledTexture::draw(
            Window& window,
            const Vector2D<int>& camera_offset
        ) {
            BoxRect screen_rect { {0, 0}, {WINDOW_WIDTH, WINDOW_HEIGHT} };
            screen_rect.update_rect(camera_offset);

            BoxRect line_rect { {0, 0} };
            for (auto& line : tile_lines_)
            {
                line_rect = {
                    line.start, 
                    line.start + Vector2D<int>(line.length * SPRITE_SIZE_PX,
                                               SPRITE_SIZE_PX)
                };

                // Draw only those line that can at least
                // partially appear on the screen.
                if (screen_rect.is_overlapped(line_rect) ||
                    line_rect.is_overlapped(screen_rect))
                {
                    window.draw_tile_line(sprite, line, camera_offset);
                }
            }
        }
    } // namespace Prefabs
} // namespace Engine
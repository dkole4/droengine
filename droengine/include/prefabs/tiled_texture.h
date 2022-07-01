#ifndef ENGINE_TILED_TEXTURE_H
#define ENGINE_TILED_TEXTURE_H

#include "../core/box_rect.h"
#include "../core/vector2d.h"
#include "../core/window.h"
#include "../core/gameobject.h"
#include "../components/sprite.h"
#include "../components/collider.h"
#include "../components/rigidbody.h"

#include <vector>

namespace Engine
{
    using namespace Components;

    namespace Prefabs
    {
        /**
         * @brief Class that represents a collection of tiles.
         * 
         */
        class TiledTexture : public GameObject
        {
        public:
            // Disable object's collider and set it's
            // rigidbody type as static by default.
            TiledTexture(
                Sprite                sprite,
                std::vector<TileLine> tile_lines,
                BoxCollider           collider    = {false},
                Rigidbody             rigidbody   = {true}
            );
            ~TiledTexture() = default;

            /**
             * @brief Draws tiles to the screen.
             * 
             * @param window Game window to draw to.
             * @param camera_offset Current camera offset of the scene.
             */
            void draw(
                Window&              window,
                const Vector2D<int>& camera_offset
            );

            /**
             * @brief Get the tile lines of TiledTexture.
             * 
             * @return const std::vector<TileLine>& Vector of
             * TiledTexture's tile lines.
             */
            const std::vector<TileLine>& get_tile_lines();

            /**
             * @brief Get the area covered by the TiledTexture.
             * 
             * @return const BoxRect& Area covered.
             */
            const BoxRect&               get_covered_area();
        private:
            std::vector<TileLine> tile_lines_;
            BoxRect               covered_area_;
        };
    } // namespace Prefabs
} // namespace Engine

#endif // ENGINE_TILED_TEXTURE_H
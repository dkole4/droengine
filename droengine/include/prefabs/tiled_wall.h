#ifndef ENGINE_TILED_WALL_H
#define ENGINE_TILED_WALL_H

#include "tiled_texture.h"

namespace Engine
{
    namespace Prefabs
    {
        /**
         * @brief Class representing a line of tiles that unlike
         * TiledTexture has an active collider component.
         * 
         */
        class TiledWall : public TiledTexture
        {
        public:
            TiledWall(
                Sprite            sprite,
                TileLine          tile_line,
                BoxCollider       collider,
                Rigidbody         rigidbody = {true}
            );
            ~TiledWall() = default;
        };
    } // namespace Prefabs
} // namespace Engine

#endif // ENGINE_TILED_WALL_H
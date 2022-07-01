#include "../../include/prefabs/tiled_wall.h"

namespace Engine
{
    namespace Prefabs
    {
        TiledWall::TiledWall(
            Sprite            sprite,
            TileLine          tile_line,
            BoxCollider       collider,
            Rigidbody         rigidbody
        ): TiledTexture(
            sprite,
            { tile_line },
            collider,
            rigidbody
        ) {}
    }
}
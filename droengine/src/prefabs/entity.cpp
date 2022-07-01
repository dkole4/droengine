#include "../../include/core/input.h"
#include "../../include/constants.h"
#include "../../include/prefabs/entity.h"

#include <iostream>

namespace Engine
{
    namespace Prefabs
    {
        Entity::Entity(
            Vector2D<float>  world_position,
            Sprite           sprite,
            BoxCollider      collider,
            Rigidbody        rigidbody
        ):
            GameObject(
                world_position,
                sprite,
                collider,
                rigidbody,
                GameObjectType::Entity
            ),
            animator()
        {
            collider.update_rect(world_position);
        }

        Entity::~Entity() {}

        void Entity::set_movement_velocity(const Vector2D<float>& mov_vector)
        {
            rigidbody.set_movement_velocity(
                mov_vector * DELTA_TIME * movement_speed);
        }

        void Entity::update()
        {
            GameObject::update();
            sprite.use_animation_rect(animator);
        }
    } // namespace Prefabs
    
}
#ifndef ENGINE_ENTITY_H
#define ENGINE_ENTITY_H

#include "../components/sprite.h"
#include "../components/animator.h"
#include "../core/vector2d.h"
#include "../core/gameobject.h"

#include <SDL2/SDL_rect.h>

namespace Engine
{
    using namespace Components;

    namespace Prefabs
    {
        /**
         * @brief Class that represents a game entity.
         * 
         */
        class Entity : public GameObject
        {
        public:
            Entity(
                Vector2D<float>   world_position,
                Sprite            sprite,
                BoxCollider       collider,
                Rigidbody         rigidbody
            );
            virtual ~Entity();

            /**
             * @brief Updates the Entity.
             * 
             */
            void update();
            
            /**
             * @brief Set the movement velocity of the entity.
             * 
             * @param mov_vector New movement vector.
             */
            void     set_movement_velocity(const Vector2D<float>& mov_vector);
        protected:
            float    movement_speed { 300 };
            Animator animator;
        };
    } // namespace Prefabs
} // namespace Engine

#endif // ENGINE_ENTITY_H
#ifndef ENGINE_COLLIDER_H
#define ENGINE_COLLIDER_H

#include "../constants.h"
#include "../core/vector2d.h"
#include "../core/box_rect.h"

namespace Engine
{
    namespace Components
    {
        /**
         * @brief Basic collider component for GameObjects.
         * 
         */
        class BoxCollider
        {
        public:
            BoxCollider(
                bool enabled         = true,
                bool trigger         = false,
                Vector2D<int> size   = { SPRITE_SIZE_PX, SPRITE_SIZE_PX },
                Vector2D<int> offset = {0, 0});
            ~BoxCollider() = default;

            /**
             * @brief Updates current position of component's BoxRect.
             * 
             * @param cur_position Current position of the GameObject
             * the component is attached to.
             */
            void   update_rect(const Vector2D<float>& cur_position);

            /**
             * @brief Checks if this collider is in collision
             * with another collider.
             * 
             * @param other Collider to use in the check.
             * @return true If colliders are collided.
             * @return false If colliders are not collided.
             */
            bool   is_collided(const BoxCollider& other);

            /**
             * @brief Checks if this collider will be in collision
             * with another collider in the next frame.
             * 
             * @param obj_vel Velocity of the object
             * this collider is attached to.
             * @param other Collider to use in the check.
             * @param other_vel Velocity of the object
             * the other collider is attached to.
             * @return true If colliders will be collided next frame.
             * @return false If colliders won't be collided next frame.
             */
            bool   is_collided_next_frame(
                Vector2D<float> obj_vel,
                const BoxCollider& other,
                Vector2D<float> other_vel
            );

            /**
             * @brief Get collider's enabled status.
             * 
             * @return true If collider is enabled.
             * @return false If collider is disabled.
             */
            bool   is_enabled() const;

            /**
             * @brief Get the center of this collider.
             * 
             * @return Vector2D<float> Center of this collider's BoxRect.
             */
            Vector2D<float> get_center();

            /**
             * @brief Get the BoxRect of this collider. 
             * 
             * @return const BoxRect& This collider's BoxRect.
             */
            const BoxRect& get_rect();

        private:
            bool enabled  { true };   // Is collider enabled.
            bool trigger  { false };  // Is collider a trigger.
            
            BoxRect collider_rect;     // The area of the collider.
            
            // Offset of the collider relative to the object it's attached to.
            Vector2D<int> rect_offset; 
        };
    }
}

#endif // ENGINE_COLLIDER_H
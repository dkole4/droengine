#include "../../include/components/collider.h"

namespace Engine
{
    namespace Components
    {
        BoxCollider::BoxCollider(
            bool          enabled,
            bool          trigger,
            Vector2D<int> size,
            Vector2D<int> offset
        ):
            enabled(enabled),
            trigger(trigger),
            collider_rect(size),
            rect_offset(offset)
        { }

        void BoxCollider::update_rect(const Vector2D<float>& cur_position)
        {
            collider_rect.update_rect(cur_position + rect_offset);
        }

        bool BoxCollider::is_collided_next_frame(
            Vector2D<float> obj_vel,
            const BoxCollider& other,
            Vector2D<float> other_vel
        ) {
            // Skip checking if any of the Colliders is disabled.
            if (!enabled || !other.is_enabled()) return false;

            BoxRect obj_updated   { collider_rect.get_updated(obj_vel) };
            BoxRect other_updated { other.collider_rect.get_updated(other_vel) };
            return obj_updated.is_overlapped(other_updated);
        }

        bool BoxCollider::is_collided(const BoxCollider& other)
        {
            // Skip checking if any of the Colliders is disabled.
            if (!enabled || !other.is_enabled()) return false;

            return collider_rect.is_overlapped(other.collider_rect);
        }

        bool BoxCollider::is_enabled() const
        {
            return enabled;
        }

        Vector2D<float> BoxCollider::get_center()
        {
            return {
                (collider_rect.left + collider_rect.right) / 2.0f,
                (collider_rect.top + collider_rect.bottom) / 2.0f
            };
        }
        const BoxRect& BoxCollider::get_rect()
        {
            return collider_rect;
        }
    }
}
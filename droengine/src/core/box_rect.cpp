#include "../../include/core/box_rect.h"

namespace Engine
{
    BoxRect::BoxRect(Vector2D<int> size):
        box_size(size),
        top   (0),
        left  (0),
        right (size.x),
        bottom(size.y)
    {}

    BoxRect::BoxRect(Vector2D<float> min_point, Vector2D<float> max_point):
        box_size(max_point - min_point),
        top   (min_point.y),
        left  (min_point.x),
        right (max_point.x),
        bottom(max_point.y)
    {}

    BoxRect::BoxRect(float top, float left, float bottom, float right):
        box_size(right - left, bottom - top),
        top   (top),
        left  (left),
        right (right),
        bottom(bottom)
    {}

    void BoxRect::update_rect(const Vector2D<float>& position)
    {
        top    = position.y;
        left   = position.x;
        bottom = position.y + box_size.y;
        right  = position.x + box_size.x;
    }

    BoxRect BoxRect::get_updated(const Vector2D<float>& velocity) const
    {
        BoxRect updated { box_size };
        updated.top    = top    + velocity.y;
        updated.left   = left   + velocity.x;
        updated.bottom = bottom + velocity.y;
        updated.right  = right  + velocity.x;
        return updated;
    }

    void BoxRect::adjust_rect(
        const Vector2D<float>& min_point,
        const Vector2D<float>& max_point
    ) {
        if (top    > min_point.y) top    = min_point.y;
        if (left   > min_point.x) left   = min_point.x;
        if (right  < max_point.x) right  = max_point.x;
        if (bottom < max_point.x) bottom = max_point.y;
    }

    bool BoxRect::is_overlapped(const BoxRect& other) const
    {
        return std::max(left, other.left) < std::min(right, other.right)
            && std::max(top, other.top)   < std::min(bottom, other.bottom);
    }

    std::string BoxRect::to_string() const
    {
        return "(" + std::to_string(left) + ","
                   + std::to_string(top) + ")"
                   + " -> " + std::to_string(right)
                   + "," + std::to_string(bottom)
                   + ")";
    }
} // namespace Engine

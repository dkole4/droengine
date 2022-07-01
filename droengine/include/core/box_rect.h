#ifndef ENGINE_BOX_RECT_H
#define ENGINE_BOX_RECT_H

#include "vector2d.h"

#include <string>

namespace Engine
{
    bool is_clamped(float mid, float A, float B);

    /**
     * @brief Class representing a rectangle.
     * 
     */
    class BoxRect
    {
    public:
        BoxRect(Vector2D<int> size);
        BoxRect(Vector2D<float> min_point, Vector2D<float> max_point);
        BoxRect(float top, float left, float bottom, float right);
        ~BoxRect() = default;
        
        Vector2D<int> box_size;  // The size of the BoxRect.

        float top;
        float left;
        float right;
        float bottom;

        /**
         * @brief Moves BoxRect's points using its new position.
         * 
         * @param position Position to move BoxRect to.
         */
        void    update_rect(const Vector2D<float>& position);

        /**
         * @brief Broadens BoxRect's area by using min and max points.
         * 
         * @param min_point Min point to adjust left and top points with.
         * @param max_point Max point to adjust right and bottom points with.
         */
        void    adjust_rect(
            const Vector2D<float>& min_point,
            const Vector2D<float>& max_point
        );

        /**
         * @brief Get the updated BoxRect by applying
         * velocity to its current position.
         * 
         * @param velocity Velocity of a GameObject.
         * @return BoxRect BoxRect with same dimensions in the next position.
         */
        BoxRect get_updated(const Vector2D<float>& velocity) const;

        /**
         * @brief Checks if two BoxRects are overlapping.
         * 
         * @param other Other BoxRect to use in checking.
         * @return true If BoxRects are overlapped.
         * @return false If BoxRects are not overlapped.
         */
        bool    is_overlapped(const BoxRect& other) const;

        /**
         * @brief Returns a string representation of a BoxRect.
         * 
         * @return std::string String representation of a BoxRect.
         */
        std::string to_string() const;
    };
} // namespace Engine

#endif // ENGINE_BOX_RECT_H
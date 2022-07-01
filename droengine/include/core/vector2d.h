#ifndef ENGINE_VECTOR2D_H
#define ENGINE_VECTOR2D_H

#include <cmath>
#include <string>

namespace Engine
{
    /**
     * @brief Checks if two coordinates are equal.
     * 
     * @tparam T Coordinate type.
     * @param a First coordinate.
     * @param b Second coordinate.
     * @param epsilon Epsilon to use in comparison.
     * @return true If difference of coordinates is smaller than epsilon.
     * @return false If epsilon is smaller than coordinate difference.
     */
    template <typename T>
    bool are_coordinates_equal(T a, T b, double epsilon = 0.0001)
    {
        return abs(a - b) < epsilon;
    }

    /**
     * @brief Class representing a two-dimensional vector.
     * 
     * @tparam T Coordinate type.
     */
    template <typename T>
    class Vector2D 
    {
    public:
        T x {};
        T y {};

        Vector2D(): x(), y() {}
        ~Vector2D() = default;

        Vector2D(T new_x, T new_y): x(new_x), y(new_y) {}

        template <typename U>
        Vector2D(U new_x, U new_y) {
            x = static_cast<T>(new_x);
            y = static_cast<T>(new_y);
        }

        template <typename U>
        Vector2D(
            const Vector2D<U>& other
        ) : Vector2D(other.x, other.y) {}

        bool is_zero() const
        {
            return x == 0 && y == 0;
        }

        template <typename U>
        U get_distance(const Vector2D<T>& other) const
        {
            return static_cast<U>(
                std::sqrt(
                    std::pow(static_cast<U>(x) - static_cast<U>(other.x), 2)
                    + std::pow(static_cast<U>(y) - static_cast<U>(other.y), 2)
                )
            );
        }

        T dot(const Vector2D<T>& other) const
        {
            return x * other.x + y * other.y;
        }

        T length() const
        {
            return get_distance<T>({ 0, 0 });
        }

        Vector2D<T> normalized() const {
            T vector_length { length() };
            return {
                x / vector_length,
                y / vector_length
            };
        }
    
        T angle_to_vector(const Vector2D<T>& other) const
        {
            if (other.is_zero()) return 0;

            T angle = dot(other) / (length() * other.length());
            if (angle >  1) angle =  1;
            if (angle < -1) angle = -1;
            
            return (180 / M_PI) * std::acos(angle);
        }

        bool directed_same_way(const Vector2D<T>& other) const
        {
            return angle_to_vector(other) <= 45;
        }

        std::string to_string() const
        {
            return std::to_string(x) + ", " + std::to_string(y);
        }

        Vector2D<T> operator+(const Vector2D<T>& other) const
        {
            return { x + other.x, y + other.y };
        }

        Vector2D<T>& operator+=(const Vector2D<T>& other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }

        Vector2D<T> operator-(const Vector2D<T>& other) const
        {
            return { x - other.x, y - other.y };
        }

        Vector2D<T>& operator-=(const Vector2D<T>& other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        Vector2D<T> operator*(const T factor) const
        {
            return { x * factor, y * factor };
        }

        Vector2D<T>& operator*=(const T factor)
        {
            x *= factor;
            y *= factor;
            return *this;
        }

        Vector2D<T> operator/(const T factor) const
        {
            return { 
                static_cast<T>( x / factor ),
                static_cast<T>( y / factor )
            };
        }

        bool operator==(const Vector2D<T>& other) const
        {
            return (
                are_coordinates_equal(x, other.x) &&
                are_coordinates_equal(y, other.y)
            );
        }
    };
}

#endif // ENGINE_VECTOR2D_H
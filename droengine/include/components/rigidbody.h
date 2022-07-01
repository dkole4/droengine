#ifndef ENGINE_RIGIDBODY_H
#define ENGINE_RIGIDBODY_H

#include "../core/vector2d.h"

namespace Engine
{
    namespace Components
    {
        /**
         * @brief Physics component for GameObjects.
         * 
         */
        class Rigidbody
        {
        public:
            Rigidbody(
                bool  is_static_obj = false,
                float mass          = 1.0,
                float friction      = 0.05
            );
            ~Rigidbody() = default;

            /**
             * @brief Update the object's velocity by subtracting friction.
             * 
             */
            void update_velocity();

            /**
             * @brief Increase velocity by given vector.
             * 
             * @param new_vel Vector to add to current velocity.
             */
            void add_velocity(Vector2D<float> new_vel);
            
            /**
             * @brief Set the velocity vector.
             * 
             * @param new_vel New object's velocity.
             */
            void set_velocity(Vector2D<float> new_vel);

            /**
             * @brief Set the movement velocity vector.
             * 
             * @param new_vel New object's movement velocity.
             */
            void set_movement_velocity(Vector2D<float> new_vel);

            /**
             * @brief Returns this tick's movement restriction value.
             * 
             * @return true If object's movement is restricted this tick.
             * @return false If object's movement is not restricted.
             */
            bool is_movement_restricted();

            /**
             * @brief Restricts object from applying movement velocity
             * to its position the next tick.
             * 
             */
            void restrict_movement();

            /**
             * @brief Allows object to apply its movement velocity
             * to its position the next tick.
             * 
             */
            void allow_movement();

            /**
             * @brief Get the general velocity of the object,
             * including its movement velocity.
             * 
             * @return Vector2D<float> General velocity vector.
             */
            Vector2D<float> get_general_velocity();

            /**
             * @brief Handle a collision with another GameObject.
             * 
             * @param other_vel The velocity of the other GameObject.
             * @param other_mass The mass of the other GameObject.
             */
            void handle_collision(Vector2D<float> other_vel, float other_mass);

            /**
             * @brief Get the length of velocity vector,
             * not including movement velocity.
             * 
             * @return float Length of velocity vector.
             */
            float get_velocity_length();
            
            // Velocity vector, does not include movement velocity.
            Vector2D<float> velocity;
            float           mass      { 1 };     // GameObject's mass.
            float           friction  { 0.05 };  // GameObject's friction.
            bool            is_static { false }; // Is GameObject static?
        private:
            bool restrict_movement_this_tick { false };

            Vector2D<float> movement_velocity;
        };
    }
}

#endif // ENGINE_RIGIDBODY_H
#include "../../include/components/rigidbody.h"

namespace Engine
{
    namespace Components
    {
        Rigidbody::Rigidbody(
            bool   is_static_obj,
            float mass,
            float friction
        ):
            velocity(0.0f, 0.0f),
            mass(mass),
            friction(friction),
            is_static(is_static_obj),
            movement_velocity(0.0f, 0.0f)
        {}

        void Rigidbody::update_velocity()
        {
            // Apply friction to the GameObject's velocity if it's > 0.0001,
            // otherwise set it to zero vector.
            if (get_velocity_length() > 0.0001f)
            {
                velocity *= (1 - friction);
            }
            else
            {
                velocity.x = 0.0f;
                velocity.y = 0.0f;
            }
        }

        float Rigidbody::get_velocity_length()
        {
            return velocity.get_distance<float>({ 0.0f, 0.0f });
        }

        void Rigidbody::add_velocity(Vector2D<float> new_vel)
        {
            if (!is_static)
            {
                velocity += new_vel;
            }
        }

        void Rigidbody::set_velocity(Vector2D<float> new_vel)
        {
            if (!is_static)
            {
                velocity = new_vel;
            }
        }

        void Rigidbody::set_movement_velocity(Vector2D<float> new_vel)
        {
            if (!is_static)
            {
                movement_velocity = new_vel;
            }
        }

        bool Rigidbody::is_movement_restricted()
        {
            return restrict_movement_this_tick;
        }

        void Rigidbody::restrict_movement()
        {
            restrict_movement_this_tick = true;
        }

        void Rigidbody::allow_movement()
        {
            restrict_movement_this_tick = false;
        }

        Vector2D<float> Rigidbody::get_general_velocity()
        {
            return velocity + movement_velocity;
        }

        void Rigidbody::handle_collision(
            Vector2D<float> other_vel, 
            float other_mass
        ) {
            auto obj_vel { get_general_velocity() };

            // Subject to change, current way of handling
            // velocities is flawed and doesn't feel natural.
            if (obj_vel.directed_same_way(other_vel) &&
                obj_vel.length() > other_vel.length())
            {
                set_velocity(
                    obj_vel * (mass - other_mass) 
                    / (other_mass + mass)
                );
            }
            else
            {
                set_velocity(
                    (obj_vel * (mass - other_mass) 
                        + (other_vel * 2.0 * other_mass))
                    / (other_mass + mass)
                );
            }
            restrict_movement();
        }
    }
}
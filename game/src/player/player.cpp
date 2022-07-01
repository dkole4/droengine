#include "../../include/player/player.h"

#include "../../../droengine/include/core/input.h"

#include <iostream>

namespace Game
{
    Player::Player(
        Vector2D<float>         world_position,
        Components::Sprite      sprite,
        Components::BoxCollider collider,
        Components::Rigidbody   rigidbody
    ):
        Prefabs::Entity(
            world_position,
            sprite,
            collider,
            rigidbody
        )
    {
        animator.add_animation(
            "idle", { {0,  0} }
        );
        animator.add_animation(
            "run_down",
            { {0,  0}, {1,  0}, {2,  0}, {3,  0} }
        );
        animator.add_animation(
            "run_right",
            { {0,  1}, {1,  1}, {2,  1}, {3,  1} }
        );
        animator.add_animation(
            "run_left",
            { {0,  2}, {1,  2}, {2,  2}, {3,  2} }
        );
        animator.add_animation(
            "run_up",
            { {0,  3}, {1,  3}, {2,  3}, {3,  3} }
        );
    }

    Player::~Player() {}

    void Player::update()
    {
        Entity::update();

        // Reading movement vector from user's input and changing
        // movement velocity and current animation based on it.
        Vector2D<float> cur_dir { get_user_direction() };
        set_movement_velocity(cur_dir);
        update_animation_(cur_dir);
    }

    void Player::update_animation_(const Vector2D<float>& mov_vector)
    {
        std::string anim_id { "idle" };
        if (mov_vector.x > 0.0f)
        {
            anim_id = "run_right";
        }
        else if (mov_vector.x < 0.0f)
        {
            anim_id = "run_left";
        }
        else if (mov_vector.y > 0.0f)
        {
            anim_id = "run_down";
        }
        else if (mov_vector.y < 0.0f)
        {
            anim_id = "run_up";
        }

        animator.set_cur_animation(anim_id);
    }
} // namespace Game

#ifndef PLAYER_H
#define PLAYER_H

#include "../../../droengine/include/prefabs/entity.h"

using namespace Engine;

namespace Game
{
    /**
     * @brief Class representing a player GameObject.
     * 
     */
    class Player : public Prefabs::Entity
    {
    public:
        Player(
            Vector2D<float>         world_position,
            Components::Sprite      sprite,
            Components::BoxCollider collider,
            Components::Rigidbody   rigidbody
        );
        ~Player();

        /**
         * @brief Updates the player GameObject.
         * 
         */
        void update();
    private:
        /**
         * @brief Updates current animation based on player's movement.
         * 
         * @param mov_vector Movement vector of player.
         */
        void update_animation_(const Vector2D<float>& mov_vector);
    };
} // namespace Game


#endif // PLAYER_H
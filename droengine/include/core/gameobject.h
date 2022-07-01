#ifndef ENGINE_GAMEOBJECT_H
#define ENGINE_GAMEOBJECT_H

#include "vector2d.h"
#include "window.h"
#include "../components/sprite.h"
#include "../components/collider.h"
#include "../components/rigidbody.h"
#include "../constants.h"

#include <SDL2/SDL_rect.h>

namespace Engine
{
    using namespace Components;

    enum class GameObjectType
    {
        GameObject,
        Entity,
        TiledTexture
    };

    /**
     * @brief Class representing any GameObject on a scene.
     * 
     */
    class GameObject
    {
    public:
        GameObject(
            Vector2D<float>   world_position,
            Sprite            sprite,
            BoxCollider       collider        = {},
            Rigidbody         rigidbody       = {},
            GameObjectType    gameobject_type = GameObjectType::GameObject
        );
        virtual ~GameObject();

        /**
         * @brief Performs an update of the GameObject.
         * 
         */
        virtual void update();

        /**
         * @brief Performs a movement cycle of the GameObject by adding
         * its velocities to its current position.
         * 
         */
        virtual void do_movement_cycle();

        /**
         * @brief Moves the GameObject using given direction vector.
         * 
         * @param dir Direction to move the GameObject to.
         */
        virtual void move(Vector2D<float> dir);

        /**
         * @brief Draws the GameObject to the window's surface.
         * 
         * @param window Window to draw the GameObject to.
         * @param camera_offset Current camera offset of the scene.
         */
        virtual void draw(
            Window&              window,
            const Vector2D<int>& camera_offset
        );
        
        /**
         * @brief Get the type of the GameObject.
         * 
         * @return GameObjectType GameObject's type.
         */
        virtual GameObjectType get_gameobject_type();
        
        Sprite           sprite;
        BoxCollider      collider;
        Rigidbody        rigidbody;
        Vector2D<float>  position;
    private:
        GameObjectType   gameobject_type_;
    };
}

#endif // ENGINE_GAMEOBJECT_H
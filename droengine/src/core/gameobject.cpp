#include "../../include/core/gameobject.h"

namespace Engine
{
    GameObject::GameObject(
        Vector2D<float>  world_position,
        Sprite           sprite,
        BoxCollider      collider,
        Rigidbody        rigidbody,
        GameObjectType   gameobject_type 
    ):
        sprite(sprite),
        collider(collider),
        rigidbody(rigidbody),
        position(world_position),
        gameobject_type_(gameobject_type)
    { }

    GameObject::~GameObject() {}

    void GameObject::move(Vector2D<float> dir)
    {
        position += dir;
    }

    void GameObject::do_movement_cycle()
    {
        // Apply only non-movement velocity if movement is restricted
        // for this tick, general velocity otherwise.
        if (rigidbody.is_movement_restricted())
        {
            position += rigidbody.velocity;
            rigidbody.allow_movement();
        }
        else 
        {
            position += rigidbody.get_general_velocity();
        }
    }

    void GameObject::draw(
        Window& window,
        const Vector2D<int>& camera_offset
    ) {
        window.draw(sprite, camera_offset);
    }
    
    void GameObject::update() 
    {
        // Update Sprite rects and Collider BoxRect
        // using GameObject's current position.
        sprite.adjust_rect(position);
        collider.update_rect(position);

        // Update the velocity of the GameObject.        
        rigidbody.update_velocity();
    }

    GameObjectType GameObject::get_gameobject_type()
    {
        return gameobject_type_;
    }
}
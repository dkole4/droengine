#include "../../include/core/physics.h"

#include <unordered_set>
#include <iostream>

// Adding hashing function for std::pair<size_t, size_t> to store
// pairs in handle_collisions function.
namespace std {
    template <> 
    struct hash<std::pair<size_t, size_t>> {
        inline size_t operator()(const std::pair<size_t, size_t> &v) const {
            std::hash<size_t> size_t_hasher;
            return size_t_hasher(v.first) ^ size_t_hasher(v.second);
        }
    };
}

namespace Engine
{
    void PhysicsHandler::handle_collisions(Scene& scene)
    {
        // Pairs of GameObject indeces that were already handled.
        std::unordered_set<std::pair<size_t, size_t>> handled_pairs;

        auto& scene_objects { scene.get_scene_objects() };
        for (size_t i = 0; i < scene_objects.size(); ++i)
        {
            auto& object { scene_objects[i] };

            // Skip checking if object is static or has a disabled collider.
            if (!object->collider.is_enabled() || object->rigidbody.is_static)
                continue;

            Vector2D<float> vel_obj { object->rigidbody.get_general_velocity() };
            Vector2D<float> vel_other { };
            for (size_t j = 0; j < scene_objects.size(); ++j)
            {
                if (i != j && 
                    handled_pairs.find({ i, j }) == handled_pairs.end())
                {
                    auto& other { scene_objects[j] };

                    // Resolve the collision if GameObject
                    // would've collided next frame.
                    vel_other = other->rigidbody.get_general_velocity();
                    if (object->collider.is_collided_next_frame(
                            vel_obj, other->collider, vel_other))
                    {
                        other->rigidbody.handle_collision(
                            vel_obj, object->rigidbody.mass);
                        object->rigidbody.handle_collision(
                            vel_other, other->rigidbody.mass);
                    }

                    handled_pairs.insert({ j, i });
                }
            }
        }

        // Moving all the object after resolving collisions.
        move_objects(scene);
    }

    void PhysicsHandler::move_objects(Scene& scene)
    {
        for (auto& obj : scene.get_scene_objects())
        {
            obj->do_movement_cycle();
        }
    }
}
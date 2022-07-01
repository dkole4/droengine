#ifndef ENGINE_PHYSICS_H
#define ENGINE_PHYSICS_H

#include "scene.h"

namespace Engine
{
    class Scene;

    /**
     * @brief Class used for handling game physics.
     * 
     */
    class PhysicsHandler
    {
    public:
        /**
         * @brief Checks and handles GameObject collisions.
         * 
         * @param scene Scene with GameObject to use in
         * checking and resolving collisions.
         */
        static void handle_collisions(Scene& scene);

        /**
         * @brief Calls movement cycle methods of all
         * GameObjects present in a scene.
         * 
         * @param scene Scene to use.
         */
        static void move_objects(Scene& scene);
    };
}

#endif // ENGINE_PHYSICS_H
#ifndef ENGINE_SCENE_H
#define ENGINE_SCENE_H

#include "gameobject.h"
#include "window.h"
#include "vector2d.h"
#include "physics.h"
#include "render.h"

#include <vector>
#include <unordered_map>
#include <memory>
#include <string>

namespace Engine
{
    using GameObject_ptr = std::shared_ptr<GameObject>;

    enum class CameraType
    {
        STATIC,
        FOLLOW_PLAYER
    };

    /**
     * @brief Class representing a game scene.
     * 
     */
    class Scene
    {
    public:
        Scene(CameraType cam_type = CameraType::FOLLOW_PLAYER);
        ~Scene() = default;

        /**
         * @brief Updates all the GameObject of the scene.
         * 
         */
        void update_scene();

        /**
         * @brief Renders GameObject of the scene.
         * 
         * @param window 
         */
        void render_scene(Window& window);

        /**
         * @brief Shifts camera offset to follow player.
         * 
         */
        void follow_player();

        /**
         * @brief Sets the player GameObject of the scene.
         * 
         * @param player_obj 
         */
        void set_player(GameObject_ptr player_obj);

        /**
         * @brief Adds a GameObject to the scene.
         * 
         * @param gameobj GameObject pointer.
         * @param name Name of the GameObject.
         * @param tag Tag of the GameObject.
         */
        void add_gameobject(
            GameObject_ptr gameobj,
            std::string name = {},
            std::string tag = {}
        );

        /**
         * @brief Gets the count of scene's GameObjects.
         * 
         * @return size_t GameObject count.
         */
        size_t          get_object_count();

        /**
         * @brief Gets the GameObject with corresponding index.
         * 
         * @param obj_index Index of the GameObject.
         * @return GameObject_ptr& Pointer to the GameObject.
         */
        GameObject_ptr& get_scene_object(size_t      obj_index);

        /**
         * @brief Gets the GameObject with corresponding name.
         * 
         * @param obj_name Name of the GameObject.
         * @return GameObject_ptr& Pointer to the GameObject.
         */
        GameObject_ptr& get_scene_object(std::string obj_name);

        /**
         * @brief Gets the player GameObject of the scene.
         * 
         * @return GameObject_ptr& Pointer to the player GameObject.
         */
        GameObject_ptr& get_player_object();

        /**
         * @brief Gets all the GameObjects of the scene.
         * 
         * @return std::vector<GameObject_ptr>& Vector of GameObject pointers.
         */
        std::vector<GameObject_ptr>& get_scene_objects();

    private:
        size_t         player_ind_;
        CameraType     camera_type_;
        Vector2D<int>  camera_offset_;

        std::vector<GameObject_ptr>                          scene_objects_;
        std::unordered_map<std::string, size_t>              named_objects_;
        std::unordered_map<std::string, std::vector<size_t>> tagged_objects_;
    };
}

#endif // ENGINE_SCENE_H
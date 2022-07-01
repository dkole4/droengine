#ifndef ENGINE_SCENE_BUILDER_H
#define ENGINE_SCENE_BUILDER_H

#include "../core/gameobject.h"
#include "../prefabs/entity.h"
#include "../prefabs/tiled_texture.h"
#include "../core/scene.h"

#include <unordered_map>

namespace Engine
{
    using namespace Prefabs;

    namespace Util
    {
        /**
         * @brief Class used in a scene loading and building.
         * 
         */
        class SceneBuilder
        {
        public:
            /**
             * @brief Builds a scene based on its map and given GameObjects.
             * 
             * @param scene_map_file Path to the object map of the scene.
             * @param prefabs GameObjects to instantiate on the scene.
             * @param tiles Tiles to instantiate on the scene.
             * @param player Player GameObject to use in the scene.
             * @param camera_type Camera type of the scene.
             * @return Scene Scene object with loaded GameObjects.
             */
            static Scene build_scene(
                const char                             *scene_map_file,
                std::unordered_map<char, GameObject>    prefabs,
                std::unordered_map<char, TiledTexture>  tiles,
                GameObject_ptr                          player,
                CameraType camera_type = CameraType::FOLLOW_PLAYER
            );

            /**
             * @brief Initializes the map of TiledTextures represented by
             * chars and their containers of tile lines.
             * 
             * @param tiles Map of TiledTextures that are present on the
             * scene and their char representations.
             * @return std::unordered_map<char, std::vector<TileLine>> Map of
             * chars representing TiledTextures and their vectors of TileLine.
             */
            static std::unordered_map<char, std::vector<TileLine>>
            init_tile_lines(
                std::unordered_map<char, TiledTexture>& tiles
            );

            /**
             * @brief Adds a GameObject to the scene.
             * 
             * @param scene Scene to add GameObject to.
             * @param cur_scene_coord Coordinate to add GameObject to.
             * @param cur_prefab GameObject to add.
             */
            static void add_gameobject(
                Scene&           scene,
                Vector2D<float>& cur_scene_coord,
                GameObject&      cur_prefab
            );

            /**
             * @brief Adds a new tile line to the vector of
             * tile lines or extends an existing one.
             * 
             * @param cur_pos Position of the tile line.
             * @param tile_lines Vector of tile lines to add to.
             */
            static void add_tile_line(
                const Vector2D<int>    cur_pos,
                std::vector<TileLine>& tile_lines
            );

            /**
             * @brief Adds TiledTexture object to the scene.
             * 
             * @param scene Scene to add objects to.
             * @param tiles TiledTexture objects to add.
             * @param tile_lines Tile lines to assign to added TiledTextures.
             */
            static void add_tiles_to_scene(
                Scene& scene,
                const std::unordered_map<char, TiledTexture>&          tiles,
                const std::unordered_map<char, std::vector<TileLine>>& tile_lines
            );
        };
    }
}

#endif // ENGINE_SCENE_BUILDER_H
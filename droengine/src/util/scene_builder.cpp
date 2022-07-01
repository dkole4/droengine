#include "../../include/util/scene_builder.h"

#include "../../include/constants.h"

#include <fstream>
#include <string>
#include <memory>

namespace Engine
{
    namespace Util
    {
        Scene SceneBuilder::build_scene(
            const char                             *scene_map_file,
            std::unordered_map<char, GameObject>    prefabs,
            std::unordered_map<char, TiledTexture>  tiles,
            GameObject_ptr                          player,
            CameraType                              camera_type
        ) {
            Scene scene { camera_type };

            Vector2D<float> cur_scene_coord { 0, 0 };
            auto            tile_lines { init_tile_lines(tiles) };

            std::string   cur_line {};
            std::ifstream scene_file(scene_map_file);
            if (scene_file.is_open())
            {
                while ( std::getline(scene_file, cur_line) )
                {
                    for (auto& line_char : cur_line)
                    {
                        auto cur_prefab { prefabs.find(line_char) };
                        if (cur_prefab != prefabs.end())
                        {
                            add_gameobject(scene, cur_scene_coord, cur_prefab->second);
                            
                        }
                        auto cur_tile   { tiles.find(line_char) };
                        if (cur_tile != tiles.end())
                        {
                            add_tile_line(cur_scene_coord, tile_lines[line_char]);
                        }

                        cur_scene_coord.x += SPRITE_SIZE_PX;
                    }
                    cur_scene_coord.y += SPRITE_SIZE_PX;
                    cur_scene_coord.x = 0;
                }
                scene_file.close();
            }
            
            add_tiles_to_scene(scene, tiles, tile_lines);

            scene.set_player(player);

            return scene;
        }

        std::unordered_map<char, std::vector<TileLine>>
        SceneBuilder::init_tile_lines(
            std::unordered_map<char, TiledTexture>& tiles
        ) {
            std::unordered_map<char, std::vector<TileLine>> tile_lines {};
            for (const auto& tile : tiles)
            {
                tile_lines.insert({ tile.first, {} });
            }
            return tile_lines;
        }

        void SceneBuilder::add_gameobject(
            Scene&           scene,
            Vector2D<float>& cur_scene_coord,
            GameObject&      cur_prefab
        ) {
            scene.add_gameobject(
                std::make_shared<GameObject>(
                    cur_scene_coord,
                    cur_prefab.sprite,
                    cur_prefab.collider,
                    cur_prefab.rigidbody
                )
            );
        }

        void SceneBuilder::add_tile_line(
            const Vector2D<int>    cur_pos,
            std::vector<TileLine>& tile_lines
        ) {
            if (tile_lines.size() == 0)
            {
                tile_lines.push_back({ cur_pos, 1 });
            }
            else
            {
                auto& last_line { tile_lines[tile_lines.size() - 1] };
                if (last_line.start.y == cur_pos.y
                    && (last_line.start.x + last_line.length * SPRITE_SIZE_PX)
                        == cur_pos.x
                ) {
                    ++last_line.length;
                }
                else
                {
                    tile_lines.push_back({ cur_pos, 1 });
                }
            }
        }

        void SceneBuilder::add_tiles_to_scene(
            Scene& scene,
            const std::unordered_map<char, TiledTexture>&          tiles,
            const std::unordered_map<char, std::vector<TileLine>>& tile_lines
        ) {
            for (const auto& tile : tile_lines)
            {
                const auto& tile_obj { tiles.find(tile.first)->second };
                scene.add_gameobject(
                    std::make_shared<TiledTexture>(
                        tile_obj.sprite,
                        tile.second,
                        tile_obj.collider,
                        tile_obj.rigidbody
                    )
                );
            }
        }
    }
}
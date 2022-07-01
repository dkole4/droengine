#include "../include/game.h"

#include "../include/player/player.h"

#include "../../droengine/include/constants.h"
#include "../../droengine/include/prefabs/entity.h"
#include "../../droengine/include/prefabs/tiled_texture.h"
#include "../../droengine/include/core/framerate.h"
#include "../../droengine/include/core/scene.h"
#include "../../droengine/include/core/input.h"
#include "../../droengine/include/util/scene_builder.h"

#include <SDL2/SDL_rect.h>

using namespace Engine;

namespace Game
{
    GameState::GameState()
    {
        std::cout << "This is the first line of the engine\n";

        if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
        {
            std::cout << "Failed to initialize the SDL2 library\n";
            return;
        }

        if (main_window.init_window(WINDOW_WIDTH, WINDOW_HEIGHT) < 0) {
            std::cout << "Failed to initialize the main window\n";
            return;
        }

        std::cout << "Loaded main window\n";
    }

    GameState::~GameState() { }

    void GameState::update()
    {
        Scene scene {
            Util::SceneBuilder::build_scene(
                "first_map",
                {},
                {
                    {
                        'X',
                        TiledTexture(
                            Sprite("wall_tile.bmp", SpriteType::SINGLE_SPRITE),
                            {},
                            BoxCollider(false, false, { 64, 64 }, { 0, 64 }),
                            Rigidbody(true, 1, 0.05)
                        )
                    }, {
                        '.',
                        TiledTexture(
                            Sprite("floor_tile.bmp", SpriteType::SINGLE_SPRITE, 0),
                            {},
                            BoxCollider(false),
                            Rigidbody(true, 1, 0.05)
                        )
                    }
                },
                std::make_shared<Player>(
                    WINDOW_CENTER,
                    Sprite("player_sheet.bmp", SpriteType::SPRITESHEET),
                    BoxCollider(true, false, { 32, 8 }, { 16, 56 }),
                    Rigidbody(false, 1, 0.05)
                )
            )
        };

        scene.add_gameobject(
            std::make_shared<GameObject>(
                Vector2D<float>(640.0f, 480.0f),
                Sprite("bed10.bmp", SpriteType::SINGLE_SPRITE),
                BoxCollider(true, false, { 96, 128 }, { 0, 44 }),
                Rigidbody(false, 10, 0.05)
            ),
            "bed10"
        );

        scene.add_gameobject(
            std::make_shared<GameObject>(
                Vector2D<float>(500.0, 480.0),
                Sprite("bed5.bmp", SpriteType::SINGLE_SPRITE),
                BoxCollider(true, false, { 96, 128 }, { 0, 44 }),
                Rigidbody(false, 5, 0.05)
            ),
            "bed5"
        );

        scene.add_gameobject(
            std::make_shared<GameObject>(
                Vector2D<float>(360.0, 480.0),
                Sprite("bed1.bmp", SpriteType::SINGLE_SPRITE),
                BoxCollider(true, false, { 96, 128 }, { 0, 44 }),
                Rigidbody(false, 1, 0.05)
            ),
            "bed1"
        );

        bool keep_window_open { true };
        while(keep_window_open)
        {
            while(SDL_PollEvent(&main_window.event) > 0)
            {
                switch(main_window.event.type)
                {
                    case SDL_QUIT:
                        keep_window_open = false;
                        break;
                }
            }

            scene.update_scene();
            scene.render_scene(main_window);

            stabilize_framerate();
        }
    }
} // namespace Game

#include "../../include/core/scene.h"

namespace Engine
{
    Scene::Scene(CameraType cam_type):
        player_ind_(0),
        camera_type_(cam_type),
        camera_offset_(0, 0),
        scene_objects_(),
        named_objects_(),
        tagged_objects_()
    { }

    void Scene::update_scene()
    {
        for (auto& obj_ptr : scene_objects_)
        {
            obj_ptr->update();
        }
        
        PhysicsHandler::handle_collisions(*this);

        if (camera_type_ == CameraType::FOLLOW_PLAYER)
            follow_player();
    }

    void Scene::render_scene(Window& window)
    {
        window.clear();

        for (auto& sprite_layer : get_render_order(*this, camera_offset_))
        {
            for (auto& render_line : sprite_layer)
            {
                for (auto obj_ind : render_line)
                {
                    auto& obj { scene_objects_[obj_ind] };
                    if (obj->sprite.image)
                    {
                        obj->draw(window, camera_offset_);
                    }
                }
            }
        }

        window.update_surface();
    }

    void Scene::follow_player()
    {
        Vector2D<int> offset { get_player_object()->position - WINDOW_CENTER };
        if (camera_offset_.get_distance<int>(offset) > CAMERA_FOLLOW_DIST)
        {
            camera_offset_ += (offset - camera_offset_) / 20;
        }
    }

    void Scene::set_player(GameObject_ptr player_obj)
    {
        if (!player_obj) return;
        add_gameobject(player_obj, "player", "player");
        player_ind_ = scene_objects_.size() - 1;
    }

    void Scene::add_gameobject(
        GameObject_ptr gameobj,
        std::string name,
        std::string tag
    ) {
        if (!gameobj) return;
        if (named_objects_.find(name) != named_objects_.end()) return;

        scene_objects_.push_back(gameobj);
        size_t obj_ind { scene_objects_.size() - 1 };

        if (!name.empty())
        {
            named_objects_.insert({ name, obj_ind });
        }

        if (!tag.empty())
        {
            if (tagged_objects_.find(tag) == tagged_objects_.end())
            {
                tagged_objects_.insert({ tag, { obj_ind } });
            }
            else
            {
                tagged_objects_[tag].push_back(obj_ind);
            }
        }
    }

    size_t Scene::get_object_count()
    {
        return scene_objects_.size();
    }
    
    GameObject_ptr& Scene::get_scene_object(size_t obj_index)
    {
        return scene_objects_[obj_index];
    }

    GameObject_ptr& Scene::get_scene_object(std::string obj_name)
    {
        size_t obj_index { named_objects_[obj_name] };
        return scene_objects_[obj_index];
    }

    std::vector<GameObject_ptr>& Scene::get_scene_objects()
    {
        return scene_objects_;
    }

    GameObject_ptr& Scene::get_player_object()
    {
        return scene_objects_[player_ind_];
    }
}
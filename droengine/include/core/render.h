#ifndef ENGINE_RENDER_H
#define ENGINE_RENDER_H

#include "vector2d.h"
#include "scene.h"
#include "window.h"
#include "../constants.h"

namespace Engine
{
    class Scene;

    using RenderOrder = std::vector<std::vector<std::vector<size_t>>>;

    /**
     * @brief Gets the render order of a Scene.
     * 
     * @param scene Scene containing GameObjects to render.
     * @param camera_offset Camera offset of the scene.
     * @return RenderOrder Indeces of GameObjects placed in their render order.
     */
    RenderOrder
    get_render_order(Scene& scene, const Vector2D<int>& camera_offset);

    /**
     * @brief Initializes render order object.
     * 
     * @param render_order RenderOrder to initialize.
     */
    void init_render_order_vector(RenderOrder& render_order);
}

#endif // ENGINE_RENDER_H
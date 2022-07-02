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
     * @brief Configures the render order of a Scene for this tick.
     * 
     * @param scene Scene containing GameObjects to render.
     */
    void configure_render_order(Scene& scene);

    /**
     * @brief Initializes render order object.
     * 
     * @param render_order RenderOrder to initialize.
     */
    void init_render_order_vector(RenderOrder& render_order);

    /**
     * @brief Resets Render Order object.
     * 
     * @param render_order Render order object to reset.
     */
    void reset_render_order_vector(RenderOrder& render_order);
}

#endif // ENGINE_RENDER_H
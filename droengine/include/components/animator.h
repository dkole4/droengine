#ifndef ENGINE_ANIMATOR_H
#define ENGINE_ANIMATOR_H

#include "../constants.h"
#include "../core/vector2d.h"

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

namespace Engine {
    namespace Components {
        // Sequence of Sprite positions on the GameObject's spritesheet.
        using FrameSequence = std::vector<std::pair<size_t, size_t>>;

        /**
         * @brief Animator components for GameObjects;
         * 
         */
        class Animator
        {
        public:
            Animator();
            ~Animator() = default;

            /**
             * @brief Adds FrameSequence respresenting an animation
             * to the component's animation list.
             * 
             * @param anim_id Name of new animation.
             * @param frame_seq FrameSequence representing the animation.
             */
            void add_animation(std::string anim_id, FrameSequence frame_seq);

            /**
             * @brief Set the current animation.
             * 
             * @param animation_id Name of the animation to set active.
             */
            void set_cur_animation(std::string animation_id);

            /**
             * @brief Set the current animation.
             * 
             * @param animation_ind Index of the animation to set active.
             */
            void set_cur_animation(size_t animation_ind);

            /**
             * @brief Get the position of the next frame.
             * 
             * @return SDL_Rect Position of the next frame on the spritesheet.
             */
            SDL_Rect get_next_frame();

            size_t cur_animation  { 0 };    // Index of current animation.
            size_t cur_frame      { 0 };    // Current frame of the animation.
            int    cur_frame_tick { 0 };    // Current tick of the frame.

            // List of GameObject's animations.
            std::vector<FrameSequence>              animations {};

            // Map of animation names to their indexes in the animation list.
            std::unordered_map<std::string, size_t> animation_ids {};
        };
    }
}

#endif // ENGINE_ANIMATOR_H
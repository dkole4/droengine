#include "../../include/components/animator.h"

namespace Engine {
    namespace Components {
        Animator::Animator() {}

        void Animator::add_animation(std::string anim_id, FrameSequence frame_seq)
        {
            size_t cur_anim_ind { animation_ids.size() };

            animation_ids.insert({ anim_id, cur_anim_ind });
            animations.push_back(frame_seq);
        }

        void Animator::set_cur_animation(std::string anim_id) 
        {
            auto new_anim { animation_ids[anim_id] };

            // Not setting if requested animation is the
            // one that is currently being played.
            if (new_anim != cur_animation)
            {
                cur_animation = new_anim;
                cur_frame = 0;
            }
        }

        void Animator::set_cur_animation(size_t anim_ind) 
        {
            // Not setting if requested animation is the one that is currently
            // being played or if index is out of animation list's size.
            if (anim_ind < animations.size() && anim_ind != cur_animation)
            {
                cur_animation = anim_ind;
                cur_frame = 0;
            }
        }

        SDL_Rect Animator::get_next_frame()
        {
            SDL_Rect frame_rect;
            frame_rect.w = SPRITE_SIZE_PX;
            frame_rect.h = SPRITE_SIZE_PX;

            // Returning the first sprite of the
            // spritesheet if no animation was added.
            if (animations.size() == 0)
            {
                frame_rect.x = 0;
                frame_rect.y = 0;
                return frame_rect;
            }
            
            // Increasing the tick count and moving to the next frame if
            // current frame was shown for long enough time.
            ++cur_frame_tick;
            if (cur_frame_tick >= TICKS_PER_FRAME)
            {
                cur_frame = (cur_frame + 1) % animations[cur_animation].size();
                cur_frame_tick = 0;
            }

            std::pair<size_t, size_t>& frame_ind {
                animations[cur_animation][cur_frame] 
            };

            frame_rect.x = frame_ind.first  * static_cast<uint>(SPRITE_SIZE_PX);
            frame_rect.y = frame_ind.second * static_cast<uint>(SPRITE_SIZE_PX);

            return frame_rect;
        }
    }
}
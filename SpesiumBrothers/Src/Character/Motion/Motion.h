#ifndef MOTION_H
#define MOTION_H

#include <algorithm>
#include <functional>
#include <map>
#include <span>
#include <string>

namespace spesium {
    namespace character {
        class CharacterBase;

        class Motion {
           public:
            Motion() = default;

           public:
            enum class MotionState {
                WAIT,
                RUN,
                JUMP,
            };

           private:
            struct ChangeList {
                MotionState motionState;
                std::function<bool()> condition;
            };

           public:
            std::multimap<MotionState, ChangeList> changeMotionList {};
            MotionState currentMotion;

            void Register( ChangeList origin_, ChangeList next_, std::function<bool()> condition_ ) {
                changeMotionList.emplace( origin_, next_, condition_ );
            }

            auto Update() -> MotionState {
                auto [index, end] { changeMotionList.equal_range( currentMotion ) };

                for ( ; index != end; ++index ) {
                    if ( index->second.condition() ) {
                        currentMotion = index->second.motionState;
                    }
                }

                return currentMotion;
            }
        };
    }  // namespace character

}  // namespace spesium

#endif  // !MOTION_H

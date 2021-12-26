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
            struct ChangeMotionList {
                MotionState motionState;
                std::function<bool()> condition;
            };

           public:
            std::multimap<MotionState, ChangeMotionList> changeMotionList;
            MotionState currentMotion;

            void Register( ChangeMotionList origin_, ChangeMotionList next_, std::function<bool()> condition_ ) {
                changeMotionList.emplace( origin_, next_, condition_ );
            }

            auto Update() -> std::string {
                auto tmp { changeMotionList.equal_range( currentMotion ) };

                //std::span<std::multimap<MotionState, ChangeMotionList>> targetExec(tmp.first, tmp.second);

                auto end { tmp.second + 1 };
                for ( auto index { tmp.first }; index == end; ++index ) {
                    if ( index.second.condition_() ) {
                        currentMotion = index.secoud;
                    }
                }

                return currentMotion;
            }
        };
    }  // namespace character

}  // namespace spesium

#endif  // !MOTION_H

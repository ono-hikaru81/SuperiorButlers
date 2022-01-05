
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
            ~Motion() = default;

           public:
            enum class State {
                Wait,
                Run,
                Jump,
                DoubleJump,
                Guard,
                NeutralAttack,
                StrongAttack,
                AerialNeutralAttack,
                AerialStrongAttack,
                FallLanding,
                SmallHitBack,
                BigHitBack,
                Fall,
                Turn,
            };

           private:
            struct ChangeList {
                State motionState;
                std::function<bool()> condition;
            };

           public:
            std::multimap<State, ChangeList> changeMotionList {};
            State currentMotion;

            void Register( const State& origin_, const State& next_, const std::function<bool()>& condition_ ) {
                changeMotionList.emplace( origin_, ChangeList { next_, condition_ } );
            }

            auto Update() -> State {
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


#ifndef MOTION_BASE_H
#define MOTION_BASE_H

#include <Utility/Property.hpp>

namespace spesium {
    namespace character {

        class CharacterBase;

        class MotionBase {
           public:
            MotionBase() = default;
            ~MotionBase() = default;

            virtual void Init( CharacterBase* character_ ) = 0;
            virtual void Update( CharacterBase* character_ ) = 0;
        };
    }  // namespace character
}  // namespace spesium

#endif  // !MOTION_NODE_H

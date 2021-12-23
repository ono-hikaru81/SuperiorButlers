
#ifndef WAIT_H
#define WAIT_H

#include <Character/Motion/MotionBase.h>

namespace spesium {
    namespace character {
        class Wait : public MotionBase {
           private:
            Wait() = default;
            ~Wait() = default;

           public:
            static Wait* GetInstance() {
                static Wait instance;
                return &instance;
            }

            virtual void Init( CharacterBase* character_ );
            virtual void Update( CharacterBase* character_ );
        };
    }  // namespace character
}  // namespace spesium

#endif  // !WAIT_H

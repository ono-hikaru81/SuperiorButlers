
#ifndef RUN_H
#define RUN_H

#include <Character/Motion/MotionBase.h>

namespace spesium {
    namespace character {
        class Run : public MotionBase {
           private:
            Run() = default;
            ~Run() = default;

           public:
            static Run* GetInstance() {
                static Run instance;
                return &instance;
            }

            virtual void Init( CharacterBase* character_ );
            virtual void Update( CharacterBase* character_ );
        };
    }  // namespace character
}  // namespace spesium

#endif  // !RUN_H


#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <DxLib.h>
#include <Utility/Singleton.h>

namespace spesium {
    class InputManager : public Singleton<InputManager> {
       public:
        InputManager();
        virtual ~InputManager() {};

       public:
        //毎フレーム呼び出す
        void UpdateKeyStatus();

        //押した瞬間
        bool IsKeyPushed( int key );

        //押している
        bool IsKeyHeld( int key );

        //離した
        bool IsKeyReleased( int key );

       private:
        char keyStatus[256];
        char previousKeyStatus[256];
    };
}  // namespace spesium

#endif  // !INPUT_MANAGER_H

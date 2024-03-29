﻿
#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <DxLib.h>
#include <Manager/InputState.h>
#include <Utility/Singleton.h>

#include <array>

namespace spesium {
    namespace input {
        class InputManager : public Singleton<InputManager> {
           public:
            InputManager();
            ~InputManager() {};

           public:
            //毎フレーム呼び出す
            void UpdateKeyStatus();

            //押した瞬間
            bool IsKeyPushed( const int32_t& key );

            //押している
            bool IsKeyHeld( const int32_t& key );

            //離した
            bool IsKeyReleased( const int32_t& key );

           private:
            static constexpr uint32_t KEY_MAX { 256 };

            std::array<InputState, KEY_MAX> inputState;
            std::array<bool, KEY_MAX> keyStateList {};
            std::array<bool, KEY_MAX> previousKeyStateList {};
        };
    }  // namespace input
}  // namespace spesium

#endif  // !INPUT_MANAGER_H

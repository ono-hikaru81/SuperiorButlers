#include "InputManager.h"
namespace input {
    InputManager::InputManager() {
        keyStateList.fill( 0 );
        previousKeyStateList.fill( 0 );
    }

    void InputManager::UpdateKeyStatus() {
        for ( int32_t i = 0; auto& target : inputState ) {
            keyStateList.at( i ) = CheckHitKey( i ) == ON;
            target = ConvertState(keyStateList.at( i ), previousKeyStateList.at( i ) );
            previousKeyStateList.at( i ) = keyStateList.at( i );
            i++;
        }
    }

    bool InputManager::IsKeyPushed( const int32_t& key ) {
        return inputState.at(key) == InputState::push;
    }

    bool InputManager::IsKeyHeld( const int32_t& key ) {
        return inputState.at( key ) == InputState::hold;
    }

    bool InputManager::IsKeyReleased( const int32_t& key ) {
        return inputState.at( key ) == InputState::release;
    }

}  // namespace input

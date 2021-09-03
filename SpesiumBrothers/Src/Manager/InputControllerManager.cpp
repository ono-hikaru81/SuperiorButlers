#include "InputControllerManager.h"

namespace input {
    InputControllerManager::InputControllerManager() {
        previousButtonList.fill( 0 );
        buttonStateList.fill( InputState::none );
        GetJoypadXInputState( DX_INPUT_PAD1, &inputXbox );
    }

    void InputControllerManager::UpdateControllerStatus() {
        GetJoypadXInputState( DX_INPUT_PAD1, &inputXbox );
        FindPadNum();

        for ( int32_t i = 0; auto& target : buttonStateList) {
            target = ConvertState( inputXbox.Buttons[i] == ON, previousButtonList.at( i ) );
            previousButtonList[i] = inputXbox.Buttons[i] == ON;
            i++;
        }

        leftStick.Set( inputXbox.ThumbLX, inputXbox.ThumbLY );

        rightStick.Set( inputXbox.ThumbRX, inputXbox.ThumbRY );

        leftTrigger = inputXbox.LeftTrigger;

        rightTrigger = inputXbox.RightTrigger;
    }

    bool InputControllerManager::IsPadKeyPushed( const int32_t& Key ) {
        return buttonStateList.at( Key ) == InputState::push;
    }

    bool InputControllerManager::IsPadKeyHold( const int32_t& Key ) {
        return buttonStateList.at( Key ) == InputState::hold;
    }

    bool InputControllerManager::IsPadKeyReleased( const int32_t& Key ) {
        return buttonStateList.at( Key ) == InputState::release;
    }

    void InputControllerManager::FindPadNum() {
        padNum = GetJoypadNum();
    }
}  // namespace input

#include "InputManager.h"

InputManager::InputManager() {
    for ( int i = 0; i < 256; i++ ) {
        keyStatus[i] = 0;
        previousKeyStatus[i] = 0;
    }
}

void InputManager::UpdateKeyStatus() {
    for ( int i = 0; i < 256; i++ ) {
        previousKeyStatus[i] = keyStatus[i];
    }

    GetHitKeyStateAll( keyStatus );
}

bool InputManager::IsKeyPushed( int key ) {
    return previousKeyStatus[key] == 0 && keyStatus[key] == 1;
}

bool InputManager::IsKeyHeld( int key ) {
    return previousKeyStatus[key] == 1 && keyStatus[key] == 1;
}

bool InputManager::IsKeyReleased( int key ) {
    return previousKeyStatus[key] == 1 && keyStatus[key] == 0;
}

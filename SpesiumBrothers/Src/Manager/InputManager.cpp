#include "InputManager.h"

void InputManager::UpdateKeyStatus()
{
	for (int i = 0; i < 256; i++)
	{
		previousKeyStatus[i] = keyStatus[i];
	}

	GetHitKeyStateAll(keyStatus);
}

bool InputManager::IsKeyPushed(int key)
{
	return ( previousKeyStatus[key] == 0 && keyStatus[key] == 1 );
}

bool InputManager::IsKeyHeld(int key)
{
	return ( previousKeyStatus[key] == 1 && keyStatus[key] == 1 );
}

bool InputManager::IsKeyRelesed(int key)
{
	return ( previousKeyStatus[key] == 1 && keyStatus[key] == 0 );
}

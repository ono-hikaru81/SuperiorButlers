#include "DxLib.h"
#include "Definition.h"
#include "Utility/Vector.h"
#include "Manager/SceneManager.h"
#include "Manager/InputManager.h"

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetGraphMode((int)WindowSize.x, (int)WindowSize.y, 32);
	SetBackgroundColor(100, 100, 100);
	SetMainWindowText("大乱闘スペシウムブラザーズ");
	if (DxLib_Init() == -1) { return -1; }
	SetDrawScreen(DX_SCREEN_BACK);

	// 管理クラス作成
	InputManager::CreateInstance();
	InputManager* inputManager = InputManager::GetInstance();
	SceneManager::CreateInstance();
	SceneManager* sceneManager = SceneManager::GetInstance();

	while (true)
	{
		if (ProcessMessage() == -1 ||
			inputManager->IsKeyPushed(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// キー更新
		inputManager->UpdateKeyStatus();

		ClearDrawScreen();
		clsDx();

		// シーン処理
		sceneManager->Exec();
		
		// シーン描画
		sceneManager->Draw();

		ScreenFlip();
	}

	// 管理クラス削除
	sceneManager = nullptr;
	inputManager = nullptr;
	SceneManager::DestoroyInstance();
	InputManager::DestoroyInstance();

	DxLib_End();
	return 0;
}

#include <memory>

#include "Definition.h"
#include "DxLib.h"
#include "Manager/InputManager.h"
#include "Manager/SceneManager.h"
#include "Utility/DxLibExtention.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	dxx::WindowSetting(window::SIZE);
	SetBackgroundColor(100, 100, 100);
	SetMainWindowText("大乱闘スペシウムブラザーズ");
	if (DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	// カメラの視点、注視点を設定
	SetCameraPositionAndTarget_UpVecY(VGet(0, 0, -1280), VGet(0, 0, 0));

	// 管理クラス作成
	auto inputManager = InputManager::Instance();
	auto sceneManager = scene::SceneManager::Instance();

	while (true) {
		// ループを抜ける条件
		if (ProcessMessage() == -1) break;
		if (inputManager.lock()->IsKeyPushed(KEY_INPUT_ESCAPE)) break;

		// キー更新
		inputManager.lock()->UpdateKeyStatus();

		// 画面リセット
		ClearDrawScreen();
		clsDx();

		// シーンの更新
		sceneManager.lock()->Update();

		ScreenFlip();
	}

	DxLib_End();
	return 0;
}

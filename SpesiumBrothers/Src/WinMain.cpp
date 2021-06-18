#include "Definition.h"
#include "DxLib.h"
#include "Manager/InputManager.h"
#include "Manager/SceneManager.h"
#include "Utility/Function.h"
#include "Utility/Vector.h"

int WINAPI WinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow ) {
    SetOutApplicationLogValidFlag( FALSE );
    ChangeWindowMode( TRUE );
    SetGraphMode( WINDOW_SIZE.x, WINDOW_SIZE.y, 32, FPS );
    SetBackgroundColor( 100, 100, 100 );
    SetMainWindowText( "大乱闘スペシウムブラザーズ" );
    if ( DxLib_Init() == -1 ) return -1;
    SetDrawScreen( DX_SCREEN_BACK );

    // 管理クラス作成
    auto inputManager = InputManager::CreateInstance();
    auto sceneManager = SceneManager::CreateInstance();
    auto function = Function::CreateInstance();

    while ( true ) {
        function->LockFPSHead();

        // ループを抜ける条件
        if ( ProcessMessage() == -1 ) break;
        if ( inputManager->IsKeyPushed( KEY_INPUT_ESCAPE ) ) break;

        // キー更新
        inputManager->UpdateKeyStatus();

        ClearDrawScreen();
        clsDx();

        // シーン処理
        sceneManager->Exec();

        // シーン描画
        sceneManager->Draw();

        ScreenFlip();

        function->LockFPSTail();
    }

    // 管理クラス削除
    sceneManager = nullptr;
    inputManager = nullptr;
    function = nullptr;
    SceneManager::DestoroyInstance();
    InputManager::DestoroyInstance();
    Function::DestoroyInstance();

    DxLib_End();
    return 0;
}

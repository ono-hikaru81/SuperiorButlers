#include "ResultScene.h"

#include "../Definition.h"
#include "../Manager/SceneManager.h"
#include "../SceneDefinition.h"
#include "DxLib.h"

ResultScene::ResultScene() {
    sceneTag = Scene::Result;
    inputManager = InputManager::GetInstance();
}

ResultScene::~ResultScene() {
    inputManager = nullptr;
}

void ResultScene::Exec() {
    // 次のシーンへ進む
    if ( inputManager->IsKeyPushed( KEY_INPUT_RETURN ) ) {
        SceneManager::GetInstance()->SetNextScene( Scene::Title );
    }
}

void ResultScene::Draw() {
    DrawString( 120, 120, "Result", GetColor( 0, 0, 0 ) );
}

#include "TitleScene.h"

#include "../Definition.h"
#include "../Manager/SceneManager.h"
#include "../SceneDefinition.h"
#include "DxLib.h"

TitleScene::TitleScene() {
    sceneTag = Scene::Title;
    inputManager = InputManager::GetInstance();
}

TitleScene::~TitleScene() {
    inputManager = nullptr;
}

void TitleScene::Exec() {
    if ( inputManager->IsKeyPushed( KEY_INPUT_RETURN ) ) {
        SceneManager::GetInstance()->SetNextScene( Scene::InGame );
    }
}

void TitleScene::Draw() {
    DrawString( 120, 120, "Title", GetColor( 0, 0, 0 ) );
}

#include "InGameScene.h"

#include "../Definition.h"
#include "../Manager/SceneManager.h"
#include "../SceneDefinition.h"
#include "DxLib.h"

InGameScene::InGameScene() {
    sceneTag = Scene::InGame;
    inputManager = InputManager::GetInstance();
}

InGameScene::~InGameScene() {
    inputManager = nullptr;
}

void InGameScene::Exec() {
    if ( inputManager->IsKeyPushed( KEY_INPUT_RETURN ) ) {
        SceneManager::GetInstance()->SetNextScene( Scene::Result );
    }
}

void InGameScene::Draw() {
    DrawString( 120, 120, "InGame", GetColor( 0, 0, 0 ) );
}

#include "InGameScene.h"

#include "../Definition.h"
#include "../Manager/SceneManager.h"
#include "DxLib.h"

namespace scene {
    InGameScene::InGameScene() {
    }

    InGameScene::~InGameScene() {
    }

    void InGameScene::Exec() {
        if ( inputManager.lock()->IsKeyPushed( KEY_INPUT_RETURN ) ) {
            SceneManager::Instance().lock()->NextScene = Scene::Result;
        }
    }

    void InGameScene::Draw() {
        DrawString( 120, 120, "InGame", GetColor( 0, 0, 0 ) );
    }
}  // namespace scene

#include "ResultScene.h"

#include "../Definition.h"
#include "../Manager/SceneManager.h"
#include "DxLib.h"

namespace scene {
    ResultScene::ResultScene() {
    }

    ResultScene::~ResultScene() {
    }

    void ResultScene::Exec() {
        if ( inputManager.lock()->IsKeyPushed( KEY_INPUT_RETURN ) ) {
            SceneManager::Instance().lock()->NextScene = Scene::Title;
        }
    }

    void ResultScene::Draw() {
        DrawString( 120, 120, "Result", GetColor( 0, 0, 0 ) );
    }
}  // namespace scene

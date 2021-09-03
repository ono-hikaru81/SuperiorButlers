#include "TitleScene.h"

#include "../Definition.h"
#include "../Manager/SceneManager.h"
#include "DxLib.h"

namespace scene {
	TitleScene::TitleScene() {
	}

	TitleScene::~TitleScene() {
	}

    void TitleScene::Exec() {
        if ( inputManager.lock()->IsKeyPushed( KEY_INPUT_RETURN ) ) {
            SceneManager::Instance().lock()->NextScene = Scene::InGame;
        } 
    }

	void TitleScene::Draw() {
		DrawString(120, 120, "Title", GetColor(0, 0, 0));
	}
}  // namespace scene

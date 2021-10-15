#include "InGameScene.h"

#include "../Definition.h"
#include "../Manager/SceneManager.h"
#include "DxLib.h"

using namespace function;

namespace scene {
	InGameScene::InGameScene() {
		monster = new character::Monster;
		bgTex = LoadGraph("Res/Texture/usagiInName.png");
	}

	InGameScene::~InGameScene() {
		delete(monster);
		DeleteGraph(bgTex);
	}

	void InGameScene::Exec() {
		if (inputManager.lock()->IsKeyPushed(KEY_INPUT_RETURN)) {
			SceneManager::Instance().lock()->NextScene = Scene::Result;
		}


		Vector3 hoge{ 0.0f, 0.0f, 0.0f };
		camera.Update(monster->Pos, hoge);

		Vector3 vec{ 0.0, 100.0, -100.0 };
		Vector3 direction{ 0.0f, 0.0f, 1.0f };

		monster->Exec();
	}

	void InGameScene::Draw() {
		DrawString(120, 120, "InGame", GetColor(0, 0, 0));
		monster->Draw(camera);
	}
}  // namespace scene

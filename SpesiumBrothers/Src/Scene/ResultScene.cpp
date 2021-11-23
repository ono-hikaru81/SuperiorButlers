
#include <Definition/Definition.h>
#include <DxLib.h>
#include <Manager/SceneManager.h>
#include <Scene/ResultScene.h>

namespace spesium {
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
}  // namespace spesium

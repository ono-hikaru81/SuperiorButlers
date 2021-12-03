
#include <Definition/Definition.h>
#include <DxLib.h>
#include <Manager/SceneManager.h>
#include <Scene/InGameScene.h>

namespace spesium {
    namespace scene {
        InGameScene::InGameScene() {
            detector.Set( monster1, monster2 );
        }

        InGameScene::~InGameScene() {
        }

        void InGameScene::Exec() {
            if ( inputManager.lock()->IsKeyPushed( KEY_INPUT_RETURN ) ) {
                SceneManager::Instance().lock()->NextScene = Scene::Result;
            }

            monster1->Exec();
            //monster2->Exec();
            camera->UpdatePos( monster1->Pos, monster2->Pos );
            detector.Update();
        }

        void InGameScene::Draw() {
            monster1->Draw();
            monster2->Draw();
            DrawString( 120, 120, "InGame", GetColor( 0, 0, 0 ) );
        }
    }  // namespace scene
}  // namespace spesium

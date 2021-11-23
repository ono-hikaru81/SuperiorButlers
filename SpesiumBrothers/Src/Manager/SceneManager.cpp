
#include <Manager/SceneManager.h>
#include <Scene/InGameScene.h>
#include <Scene/ResultScene.h>
#include <Scene/TitleScene.h>

namespace spesium {
    namespace scene {
        SceneManager::SceneManager() :
            nextScene( Scene::Title ), previousScene( Scene::Title ) {
            CreateNextScene();
        }

        SceneManager::~SceneManager() {
        }

        void SceneManager::Exec() {
            if ( !currentScene ) return;

            currentScene->Exec();

            if ( previousScene != nextScene ) { CreateNextScene(); }
        }

        void SceneManager::Draw() {
            if ( currentScene == nullptr ) return;

            currentScene->Draw();
        }

        void SceneManager::CreateNextScene() {
            switch ( nextScene ) {
                case Scene::Title: currentScene.reset( new TitleScene() ); break;
                case Scene::InGame: currentScene.reset( new InGameScene() ); break;
                case Scene::Result: currentScene.reset( new ResultScene() ); break;
            }

            previousScene = nextScene;
        }
    }  // namespace scene
}  // namespace spesium

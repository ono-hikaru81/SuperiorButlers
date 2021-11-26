
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <Definition/Definition.h>
#include <Scene/SceneBase.h>
#include <Utility/Singleton.h>

#include <Utility/Property.hpp>
#include <memory>

namespace spesium {
    namespace scene {
        class SceneManager : public Singleton<SceneManager> {
           public:
            SceneManager();

            virtual ~SceneManager();

           public:
            /// @brief シーンの更新
            void Update() {
                Exec();
                Draw();
            }

           private:
            /// @brief 処理
            void Exec();

            /// @brief 描画
            void Draw();

            /// @brief nextSceneを参照してcurrentSceneを更新する
            void CreateNextScene();

           public:
            /// @brief 遷移先のシーン
            BasicProperty<Scene> NextScene { nextScene };

           private:
            std::unique_ptr<SceneBase> currentScene;
            Scene previousScene;
            Scene nextScene;
        };
    }  // namespace scene
}  // namespace spesium

#endif  // !SCENEMANAGER_H

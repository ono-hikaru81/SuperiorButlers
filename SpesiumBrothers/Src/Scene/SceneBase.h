
#ifndef SCENE_BASE_H
#define SCENE_BASE_H

#include <Manager/InputManager.h>

#include <memory>

namespace spesium {
    namespace scene {
        class SceneBase {
           public:
            SceneBase() {
                inputManager = InputManager::Instance();
            }

            virtual ~SceneBase() {}

           public:
            virtual void Exec() = 0;

            virtual void Draw() = 0;

           protected:
            std::weak_ptr<InputManager> inputManager;
        };
    }  // namespace scene
}  // namespace spesium

#endif  // !SCENE_BASE_H

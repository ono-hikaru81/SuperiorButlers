#ifndef SCENE_BASE_H
#define SCENE_BASE_H

#include <memory>

#include "../Definition.h"
#include "../Manager/InputManager.h"
#include "../Singleton.h"

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

#endif  // !SCENE_BASE_H

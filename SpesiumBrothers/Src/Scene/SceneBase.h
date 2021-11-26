﻿
#ifndef SCENE_BASE_H
#define SCENE_BASE_H

#include <Manager/InputManager.h>

#include <memory>

#include "../Definition.h"
#include "../Manager/InputManager.h"
#include "../Singleton.h"
#include "../Camera/Camera.h"

namespace scene {
    class SceneBase {
       public:
        SceneBase() {
            inputManager = input::InputManager::Instance();
        }

            virtual ~SceneBase() {}

           public:
            virtual void Exec() = 0;

            virtual void Draw() = 0;

       protected:
        std::weak_ptr<input::InputManager> inputManager;
    };
}  // namespace scene

#endif  // !SCENE_BASE_H

﻿
#ifndef IN_GAME_SCENE_H
#define IN_GAME_SCENE_H

#include <Scene/SceneBase.h>

namespace spesium {
    namespace scene {
        class InGameScene : public SceneBase {
           public:
            InGameScene();

            virtual ~InGameScene();

            virtual void Exec();

            virtual void Draw();
        };
    }  // namespace scene
}  // namespace spesium

#endif  // !IN_GAME_SCENE_H


#ifndef IN_GAME_SCENE_H
#define IN_GAME_SCENE_H

#include <Camera/Camera.h>
#include <Character/Monster.h>
#include <Scene/SceneBase.h>

#include <Manager/CollisionDetector.hpp>
#include <memory>

namespace spesium {
    namespace scene {
        class InGameScene : public SceneBase {
           public:
            InGameScene();

            virtual ~InGameScene();

            virtual void Exec();

            virtual void Draw();

           private:
            std::shared_ptr<character::Monster> monster1 { new character::Monster() };
            std::shared_ptr<character::Monster> monster2 { new character::Monster() };
            std::shared_ptr<tool::Camera> camera { new tool::Camera() };
            CollisionDetector detector {};
        };
    }  // namespace scene
}  // namespace spesium

#endif  // !IN_GAME_SCENE_H

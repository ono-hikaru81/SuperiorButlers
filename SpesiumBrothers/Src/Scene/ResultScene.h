
#ifndef RESULT_SCENE_H
#define RESULT_SCENE_H

#include <Scene/SceneBase.h>

namespace spesium {
    namespace scene {
        class ResultScene : public SceneBase {
           public:
            ResultScene();

            virtual ~ResultScene();

            virtual void Exec();

            virtual void Draw();
        };
    }  // namespace scene
}  // namespace spesium

#endif  // !RESULT_SCENE_H

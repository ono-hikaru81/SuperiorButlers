#ifndef RESULT_SCENE_H
#define RESULT_SCENE_H

#include "SceneBase.h"

namespace scene {
    class ResultScene : public SceneBase {
       public:
        ResultScene();

        virtual ~ResultScene();

        virtual void Exec();

        virtual void Draw();
    };
}  // namespace scene

#endif  // !RESULT_SCENE_H

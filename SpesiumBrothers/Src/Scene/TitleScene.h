#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include "SceneBase.h"

namespace scene {
    class TitleScene : public SceneBase {
       public:
        TitleScene();

        virtual ~TitleScene();

       public:
        virtual void Exec();

        virtual void Draw();
    };
}  // namespace scene

#endif  // !TITLE_SCENE_H

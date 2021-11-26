
#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include <Scene/SceneBase.h>

namespace spesium {
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
}  // namespace spesium

#endif  // !TITLE_SCENE_H

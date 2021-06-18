#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include "../Manager/InputManager.h"
#include "SceneBase.h"

class TitleScene : public SceneBase {
   public:
    TitleScene();
    virtual ~TitleScene();

   public:
    // シーン処理
    virtual void Exec();

    // シーン描画
    virtual void Draw();

    virtual Scene GetSceneTag() { return sceneTag; }
    virtual void SetSceneTag( Scene sceneTag_ ) { sceneTag = sceneTag_; }
};

#endif  // !TITLE_SCENE_H

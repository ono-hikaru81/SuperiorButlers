#ifndef RESULT_SCENE_H
#define RESULT_SCENE_H

#include "../Manager/InputManager.h"
#include "SceneBase.h"

class ResultScene : public SceneBase {
   public:
    ResultScene();
    virtual ~ResultScene();

    // シーン処理
    virtual void Exec();

    // シーン描画
    virtual void Draw();

    virtual Scene GetSceneTag() { return sceneTag; }
    virtual void SetSceneTag( Scene sceneTag_ ) { sceneTag = sceneTag_; }
};

#endif  // !RESULT_SCENE_H

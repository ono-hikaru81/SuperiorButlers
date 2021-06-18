#ifndef IN_GAME_SCENE_H
#define IN_GAME_SCENE_H

#include "SceneBase.h"

class InGameScene : public SceneBase {
   public:
    InGameScene();
    virtual ~InGameScene();

    // シーン処理
    virtual void Exec();

    // シーン描画
    virtual void Draw();

    virtual Scene GetSceneTag() { return sceneTag; }
    virtual void SetSceneTag( Scene sceneTag_ ) { sceneTag = sceneTag_; }
};

#endif  // !IN_GAME_SCENE_H

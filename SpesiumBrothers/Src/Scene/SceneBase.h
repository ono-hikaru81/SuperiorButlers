#ifndef SCENE_BASE_H
#define SCENE_BASE_H

#include "../Manager/InputManager.h"
#include "../SceneDefinition.h"
#include "../Singleton.h"

class SceneBase : public Singleton<SceneBase> {
   public:
    SceneBase() :
        sceneTag( Scene::None ) {}
    virtual ~SceneBase() {}

   public:
    virtual void Exec() = 0;
    virtual void Draw() = 0;

    virtual Scene GetSceneTag() = 0;
    virtual void SetSceneTag( Scene sceneTag_ ) = 0;

   protected:
    Scene sceneTag;
    InputManager* inputManager = nullptr;
};

#endif  // !SCENE_BASE_H

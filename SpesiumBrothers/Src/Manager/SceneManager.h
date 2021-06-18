#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "../SceneDefinition.h"
#include "../Singleton.h"

class SceneManager : public Singleton<SceneManager> {
   public:
    SceneManager();
    virtual ~SceneManager();

   public:
    void Exec();
    void Draw();

    void SetNextScene( Scene next );

   private:
    class SceneBase* CreateNextScene();

   private:
    class SceneBase* currentScene;
    static Scene nextScene;
};

#endif  // !SCENEMANAGER_H

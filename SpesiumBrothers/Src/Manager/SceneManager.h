#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "../SceneDefinition.h"
#include "../Singleton.h"

class SceneManager : public Singleton<SceneManager>
{
public:
	SceneManager();
	~SceneManager();

	void Exec();
	void Draw();

	void SetNextScene(Scene next);

private:
	class SceneBase* CreateNextScene();

private:
	class SceneBase* m_pScene;
	static Scene m_NextScene;
};

#endif // !SCENEMANAGER_H

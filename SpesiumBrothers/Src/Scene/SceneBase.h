#ifndef SCENE_BASE_H
#define SCENE_BASE_H

#include "../Singleton.h"
#include "../Manager/InputManager.h"

class SceneBase : public Singleton<SceneBase>
{
public:
	SceneBase() :
		m_Step(0)
	{}
	virtual ~SceneBase() {}

	virtual void Exec() = 0;
	virtual void Draw() = 0;

	virtual bool IsEnd() const = 0;

protected:
	int m_Step;
	InputManager* inputManager = nullptr;
};

#endif // !SCENE_BASE_H

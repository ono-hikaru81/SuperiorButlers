#include "InGameScene.h"
#include "DxLib.h"
#include "../Definition.h"
#include "../SceneDefinition.h"
#include "../Manager/SceneManager.h"

enum
{
	STEP_IN,
	STEP_END
};

InGameScene::InGameScene()
{
	m_Step = STEP_IN;
	inputManager = InputManager::GetInstance();
}

InGameScene::~InGameScene()
{
	inputManager = nullptr;
}

void InGameScene::Exec()
{
	if (inputManager->IsKeyPushed(KEY_INPUT_RETURN))
	{
		m_Step = STEP_END;
	}

	if (m_Step == STEP_END)
	{
		SceneManager::GetInstance()->SetNextScene(Scene::Result);
	}
}

void InGameScene::Draw()
{
	DrawString(120, 120, "InGame", GetColor(0, 0, 0));
}

bool InGameScene::IsEnd() const
{
	return (m_Step == STEP_END);
}

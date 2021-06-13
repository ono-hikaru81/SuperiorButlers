#include "ResultScene.h"
#include "DxLib.h"
#include "../Definition.h"
#include "../SceneDefinition.h"
#include "../Manager/SceneManager.h"
enum
{
	STEP_IN,
	STEP_END
};

ResultScene::ResultScene()
{
	m_Step = STEP_IN;
	inputManager = InputManager::GetInstance();
}

ResultScene::~ResultScene()
{
	inputManager = nullptr;
}

void ResultScene::Exec()
{
	if (inputManager->IsKeyPushed(KEY_INPUT_RETURN))
	{
		m_Step = STEP_END;
	}

	if (m_Step == STEP_END)
	{
		SceneManager::GetInstance()->SetNextScene(Scene::Title);
	}
}

void ResultScene::Draw()
{
	DrawString(120, 120, "Result", GetColor(0, 0, 0));
}

bool ResultScene::IsEnd() const
{
	return (m_Step == STEP_END);
}

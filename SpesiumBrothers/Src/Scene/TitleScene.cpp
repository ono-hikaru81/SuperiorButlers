#include "TitleScene.h"
#include "DxLib.h"
#include "../Definition.h"
#include "../SceneDefinition.h"
#include "../Manager/SceneManager.h"

enum
{
	STEP_IN,
	STEP_END
};


TitleScene::TitleScene()
{
	m_Step = STEP_IN;
	inputManager = InputManager::GetInstance();
}

TitleScene::~TitleScene()
{
	inputManager = nullptr;
}

void TitleScene::Exec()
{

	if (inputManager->IsKeyPushed(KEY_INPUT_RETURN))
	{
		m_Step = STEP_END;
	}

	if (m_Step == STEP_END)
	{
		SceneManager::GetInstance()->SetNextScene(Scene::InGame);
	}
}

void TitleScene::Draw()
{
	DrawString(120, 120, "Title", GetColor(0, 0, 0));
}

bool TitleScene::IsEnd() const
{
	return (m_Step == STEP_END);
}
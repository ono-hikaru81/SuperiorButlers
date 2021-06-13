#include "SceneManager.h"
#include "../Scene/SceneBase.h"
#include "../Scene/TitleScene.h"
#include "../Scene/InGameScene.h"
#include "../Scene/ResultScene.h"

Scene SceneManager::m_NextScene = Scene::Non;

SceneManager::SceneManager() :
	m_pScene(nullptr)	
{
	SetNextScene(Scene::Title);
	m_pScene = CreateNextScene();
}


SceneManager::~SceneManager()
{
	delete m_pScene;
	m_pScene = nullptr;
}

void SceneManager::Exec()
{
	if (m_pScene == nullptr) { return; }

	m_pScene->Exec();

	if (m_pScene->IsEnd())
	{
		delete m_pScene;
		m_pScene = CreateNextScene();
	}
}

void SceneManager::Draw()
{
	if (m_pScene == nullptr) { return; }

	m_pScene->Draw();
}

void SceneManager::SetNextScene(Scene next)
{
	m_NextScene = next;
}

SceneBase* SceneManager::CreateNextScene()
{
	SceneBase* next = nullptr;

	switch (m_NextScene)
	{
	case Scene::Title: next = new TitleScene(); break;
	case Scene::InGame: next = new InGameScene(); break;
	case Scene::Result: next = new ResultScene(); break;
	}

	return next;
}

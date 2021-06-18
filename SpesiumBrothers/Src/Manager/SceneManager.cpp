#include "SceneManager.h"

#include "../Scene/InGameScene.h"
#include "../Scene/ResultScene.h"
#include "../Scene/SceneBase.h"
#include "../Scene/TitleScene.h"

Scene SceneManager::nextScene = Scene::None;

SceneManager::SceneManager() :
    currentScene( nullptr ) {
    SetNextScene( Scene::Title );
    currentScene = CreateNextScene();
}

SceneManager::~SceneManager() {
    delete currentScene;
    currentScene = nullptr;
}

void SceneManager::Exec() {
    if ( currentScene == nullptr ) return;

    currentScene->Exec();

    if ( currentScene->GetSceneTag() != nextScene ) {
        delete currentScene;
        currentScene = CreateNextScene();
    }
}

void SceneManager::Draw() {
    if ( currentScene == nullptr ) return;

    currentScene->Draw();
}

void SceneManager::SetNextScene( Scene next ) {
    nextScene = next;
}

SceneBase* SceneManager::CreateNextScene() {
    SceneBase* next = nullptr;

    switch ( nextScene ) {
        case Scene::Title: next = new TitleScene(); break;
        case Scene::InGame: next = new InGameScene(); break;
        case Scene::Result: next = new ResultScene(); break;
    }

    return next;
}

#ifndef RESULT_SCENE_H
#define RESULT_SCENE_H

#include "SceneBase.h"
#include "../Manager/InputManager.h"

class ResultScene : public SceneBase
{
public:
	ResultScene();
	virtual ~ResultScene();

	// シーン処理
	virtual void Exec();

	// シーン描画
	virtual void Draw();

	// シーン終了フラグ
	virtual bool IsEnd() const;
};

#endif // !RESULT_SCENE_H

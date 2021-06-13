#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include "SceneBase.h"
#include "../Manager/InputManager.h"

class TitleScene : public SceneBase
{
public:
	TitleScene();
	virtual ~TitleScene();

	// シーン処理
	virtual void Exec();

	// シーン描画
	virtual void Draw();

	// シーン終了フラグ
	virtual bool IsEnd() const;
};

#endif // !TITLE_SCENE_H

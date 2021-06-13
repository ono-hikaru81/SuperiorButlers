#ifndef INGAME_SCENE_H
#define INGAME_SCENE_H

#include "SceneBase.h"

class InGameScene : public SceneBase
{
public:
	InGameScene();
	virtual ~InGameScene();

	// シーン処理
	virtual void Exec();

	// シーン描画
	virtual void Draw();

	// シーン終了フラグ
	virtual bool IsEnd() const;
};

#endif // !INGAME_SCENE_H

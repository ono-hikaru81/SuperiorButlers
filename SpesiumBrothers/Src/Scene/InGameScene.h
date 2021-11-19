#ifndef IN_GAME_SCENE_H
#define IN_GAME_SCENE_H

#include "SceneBase.h"

namespace scene {
	class InGameScene : public SceneBase {
	public:
		InGameScene();

		virtual ~InGameScene();

		virtual void Exec();

		virtual void Draw();
	};
}  // namespace scene

#endif  // !IN_GAME_SCENE_H

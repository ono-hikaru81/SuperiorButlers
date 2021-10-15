#ifndef IN_GAME_SCENE_H
#define IN_GAME_SCENE_H

#include "SceneBase.h"

#include "../Character/Monster.h"
#include "../Light/Light.h"

namespace scene {
	class InGameScene : public SceneBase {
	public:
		InGameScene();

		virtual ~InGameScene();

		virtual void Exec();

		virtual void Draw();

	private:
		character::Monster* monster = nullptr;
		display::Light light;
		function::Camera camera;

		int bgTex;
	};
}  // namespace scene

#endif  // !IN_GAME_SCENE_H

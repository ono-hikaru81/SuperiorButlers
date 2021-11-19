// 定義

#ifndef DEFINITION_H
#define DEFINITION_H

#include <cstdint>

#include "Utility/Size.h"

namespace window {
	/// @brief ウィンドウのサイズ
	const utility::Size SIZE{ 1280, 720 };
	/// @brief 1秒あたりの更新回数
	constexpr int8_t FPS = 60;
}  // namespace window

namespace scene {
	/// @brief シーン名
	enum class Scene {
		Title,  // タイトル
		CharacterSelect,  // キャラクター選択
		StageSelect,  // ステージ選択
		InGame,  // プレイ中
		Result,  // 結果
	};
}  // namespace scene

namespace law
{
	/// @brief 重力量
	constexpr double gravity = 0.5;
}	// namespace law

namespace friction
{
	/// @brief 摩擦力
	constexpr double Force = 0.2;
}	// namespace friction

#endif  // !DEFINITION_H

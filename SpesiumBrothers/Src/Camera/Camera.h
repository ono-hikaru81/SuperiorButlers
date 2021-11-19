#ifndef CAMERA_H
#define CAMERA_H

#include "../Utility/Vector.h"

namespace tool
{
	class Camera
	{
	public:
		Camera() = default;
		~Camera() = default;

	public:
		/*
		* @brief カメラ更新関数
		* @param (pos_1) 座標1
		* @param (pos_2) 座標2
		*/
		void UpdatePos(const utility::Vector3& distance_characters_pos1_, const utility::Vector3& distance_characters_pos2_);

		/*
		* @brief Get,Set関数
		* @param (pos) カメラ座標
		*/
		utility::Property<utility::Vector3> Pos{ pos };

	private:
		/*
		* @breif 平面軸の更新
		* @param (pos_1) 座標1
		* @param (pos_2) 座標2
		*/
		void UpdateFlat(const utility::Vector3& distance_characters_pos1_, const utility::Vector3& distance_characters_pos2_);

		/*
		* @breif 奥行き(カメラの距離)の更新
		* @param (pos_1) 座標1
		* @param (pos_2) 座標2
		*/
		void UpdateDepth(const utility::Vector3& distance_characters_pos1_, const utility::Vector3& distance_characters_pos2_);

	private:
		/// @brief カメラ座標
		utility::Vector3 pos{ 0.0, 0.0, initialDepthValue };
		/// @brief 注視点
		utility::Vector3 gazePos{ pos.X, pos.Y, 0.0 };
		/// @brief 移動速度
		static constexpr double speed{ 5.0 };
		/// @brief 奥行きの初期値
		static constexpr double initialDepthValue{ -500.0 };
	};
}

#endif // !CAMERA_H

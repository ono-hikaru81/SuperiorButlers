#ifndef CAMERA_H
#define CAMERA_H

#include "../Utility/Vector.h"

namespace function
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
		void Update(utility::Vector3 pos1_, utility::Vector3 pos2_);

		/*
		* @brief ワールド座標をスクリーン座標に変換する
		* @param (pos_) 座標
		*/
		utility::Vector3 ConvertWorldPosToScreen(utility::Vector3 pos_);

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
		void UpdateFlat(utility::Vector3 pos1_, utility::Vector3 pos2_);

		/*
		* @breif 奥行き(カメラの距離)の更新
		* @param (pos_1) 座標1
		* @param (pos_2) 座標2
		*/
		void UpdateDepth(utility::Vector3 pos1_, utility::Vector3 pos2_);

	private:
		/// @brief カメラ座標
		utility::Vector3 pos = utility::Vector3{ 0.0f, 0.0f, initialDepthValue };
		/// @brief 注視点
		utility::Vector3 gazePos = utility::Vector3{ pos.X, pos.Y, 0.0f };
		/// @brief 移動速度
		const float speed = 5.0f;
		/// @brief 奥行きの初期値
		const float initialDepthValue = -500.0f;
	};
}

#endif // !CAMERA_H

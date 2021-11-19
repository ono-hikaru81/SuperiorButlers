#ifndef LIGHT_H
#define LIGHT_H

#include "../Utility/Vector.h"

#include "DxLib.h"

namespace tool
{
	class Light
	{
	public:
		Light() = default;
		~Light() = default;

	public:
		/*
		* @breif ディレクションライト作成
		* @param (pos_) 座標(向き指定)
		*/
		void CreateDirectionLight(utility::Vector3 pos_);

		/*
		* @brief ポイントライト作成
		* @param (pos_) 座標
		* @param (max_range_) 光の届く範囲
		* @param (attenuation_0_) 光の減衰率
		* @param (attenuation_1_) 光の減衰率(距離に比例)
		* @param (attenuation_2_) 光の減衰率(距離の2乗に比例)
		*/
		void CreatePointLight(utility::Vector3 pos_, float max_range_, float attenuation_0_, float attenuation_1_, float attenuation_2_);

		/*
		* @brief スポットライト作成
		* @param (pos_) 座標
		* @param (direction_) 方向
		* @param (angle_) スポットライトが照らす角度
		* @param (angle_attenuation_) 光の減衰が始まる角度
		* @param (max_range_) 光の届く範囲
		* @param (attenuation_0_) 光の減衰率
		* @param (attenuation_1_) 光の減衰率(距離に比例)
		* @param (attenuation_2_) 光の減衰率(距離の2乗に比例)
		*/
		void CreateSpotLight(utility::Vector3 pos_, utility::Vector3 direction_, float angle_, float angle_attenuation_, float max_range_, float attenuation_0_, float attenuation_1_, float attenuation_2_);

		/*
		* @brief ライト削除
		*/
		void DeleteLight();

	private:
		/// @brief 格納用変数
		int32_t lightHandle{ 0 };
	};
}

#endif // !LIGHT_H

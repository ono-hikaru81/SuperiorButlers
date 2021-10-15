#ifndef MONSTER_H
#define MONSTER_H

#include "CharacterBase.h"

// オタマジャクシ君
namespace character
{
	class Monster : public CharacterBase
	{
	public:
		Monster();

		~Monster();

	public:
		utility::Property<utility::Vector3> Pos{ status.pos };

	public:
		/**
		* @brief 実行関数
		*/
		void Exec();

		/**
		* @brief 描画関数
		*/
		void Draw(function::Camera camera);

	private:
		/*
		* @brief テクスチャ読み込み関数
		*/
		void LoadTexture();

		/*
		* @brief テクスチャ解放関数
		*/
		void ReleaseTexture();

		/**
		* @brief モデル読み込み関数
		*/
		void LoadModel();

		/**
		* @brief モデル解放関数
		*/
		void ReleaseModel();

		/**
		* @brief 弱攻撃モーション関数
		*/
		void LightAttackMotion();

		/**
		* @brief 強攻撃モーション関数
		*/
		void HeavytAttackMotion();

		/**
		* @brief 空中弱攻撃モーション関数
		*/
		void AerialLightAttackMotion();

		/**
		* @brief 空中強攻撃モーション関数
		*/
		void AerialHeavytAttackMotion();

		/**
		* @brief 防御モーション関数
		*/
		void DefenceMotion();

	private:
		/// @brief モデル格納用
		int modelHandle;
		int textureNum;
		int texWidth;
		int texHeight;
		int graphicsHandle;
	};
}

#endif // !MONSTER_H

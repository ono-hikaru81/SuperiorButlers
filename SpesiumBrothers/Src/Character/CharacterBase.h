#ifndef CHARACTER_BASE_H
#define CHARACTER_BASE_H

#include <memory>

#include "../Definition.h"
#include "../Utility/Vector.h"
#include "../Manager/InputManager.h"
#include "../Camera/Camera.h"

namespace character
{
	class CharacterBase
	{
	public:
		CharacterBase() = default;

		~CharacterBase() = default;

	protected:
		/// @brief キャラのステータス
		struct Status
		{
			utility::Vector3 pos;		 // 座標
			utility::Vector3 moveVec;	 // 移動量
			utility::Vector3 speedVec; // 速度量
			float angle;	 // 回転角

			int32_t hp;           // 体力
			int32_t shieldAmount; // シールド量
			int32_t power;        // 攻撃力
			float speed;		  // 速度
			float maxSpeed;		  // 最大速度
			float jumpPower;	  // ジャンプ力
		};

	protected:
		/**
		* @brief 実行関数
		*/
		virtual void Exec() = 0;

		/**
		* @brief 描画関数
		*/
		virtual void Draw(function::Camera camera_) = 0;

		/*
		* @brief テクスチャ読み込み関数
		*/
		virtual void LoadTexture() = 0;

		/*
		* @brief テクスチャ解放関数
		*/
		virtual void ReleaseTexture() = 0;

		/**
		* @brief モデル読み込み関数
		*/
		virtual void LoadModel() = 0;

		/**
		* @brief モデル解放関数
		*/
		virtual void ReleaseModel() = 0;

		/**
		* @brief 移動関数
		*/
		virtual void Move();

		/**
		* @brief ジャンプ関数
		*/
		virtual void Jump();

		/*
		* @brief 向き変更
		*/
		virtual void UpdateDirection();

		/*
		* @brief 重力関数
		*/
		virtual void Gravity();

		/*
		* @brief 立ってるかチェック
		*/
		virtual bool IsStanding() const;

		/**
		* @brief 運動摩擦関数
		*/
		virtual void KineticFriction();

		/*
		* @brief 座標更新関数
		*/
		virtual void UpdatePos();

		/**
		* @brief 弱攻撃モーション関数
		*/
		virtual void LightAttackMotion() = 0;

		/**
		* @brief 強攻撃モーション関数
		*/
		virtual void HeavytAttackMotion() = 0;

		/**
		* @brief 空中弱攻撃モーション関数
		*/
		virtual void AerialLightAttackMotion() = 0;

		/**
		* @brief 空中強攻撃モーション関数
		*/
		virtual void AerialHeavytAttackMotion() = 0;

		/**
		* @brief 防御モーション関数
		*/
		virtual void DefenceMotion() = 0;

	protected:
		/// @brief キーボード入力
		std::weak_ptr<InputManager> inputManager = InputManager::Instance();

	protected:
		/// @brief ステータス
		Status status;
		/// @brief 重力量
		const float gravityVec = gravity::Acceleration;
		/// @brief 摩擦量
		const float frictionVec = friction::Force;

		/// @brief 生存フラグ
		bool isAlive;
		/// @brief ジャンプ可能か
		bool canJump;
		/// @ brief 地面に立ってるか
		bool isStandingGround;
		/// @brief ダウンしたか(倒れたか)
		bool isKnockdown;
	};
}	// namespace character

#endif // !SCENEMANAGER_H

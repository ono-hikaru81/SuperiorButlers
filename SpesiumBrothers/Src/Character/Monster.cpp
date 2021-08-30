#include "Monster.h"

#include "DxLib.h"

namespace character
{
	Monster::Monster()
	{
		status =
		{
			{0.0f,0.0f,0.0f}, // 座標
			{0.0f,0.0f,0.0f}, // 移動量
			{0.0f,0.0f,0.0f}, // 速度量
			0.0f,			  // 回転角

			0,		// 体力
			0,		// シールド量
			0,		// 攻撃力
			1.0f,	// 速度
			5.0f,	// 最大速度
			10.0f,	// ジャンプ力
		};
		isAlive = false;
		LoadModel();
	}

	Monster::~Monster()
	{
		ReleaseModel();
	}

	void Monster::Exec()
	{
		Move();

		if (IsStanding())
		{
			status.speedVec.y = 0.0f;

			KineticFriction();
		}
		else
		{
			Gravity();
		}

		Jump();

		UpdateDirection();

		// 最後の座標処理
		UpdatePos();
	}

	void Monster::Draw()
	{
		MV1SetPosition(modelHandle, VGet(static_cast<float>(status.pos.x), static_cast<float>(status.pos.y), static_cast<float>(status.pos.z)));

		MV1SetRotationXYZ(modelHandle, VGet(0.0f, status.angle / 180.0f * DX_PI_F, 0.0f));


		MV1DrawModel(modelHandle);
	}

	void Monster::LoadTexture()
	{
	}

	void Monster::ReleaseTexture()
	{
	}

	void Monster::LoadModel()
	{
		modelHandle = MV1LoadModel("Res/Model/monster.mv1");
	}

	void Monster::ReleaseModel()
	{
		MV1DeleteModel(modelHandle);
	}

	void Monster::LightAttackMotion()
	{
	}

	void Monster::HeavytAttackMotion()
	{
	}

	void Monster::AerialLightAttackMotion()
	{
	}

	void Monster::AerialHeavytAttackMotion()
	{
	}

	void Monster::DefenceMotion()
	{
	}
}

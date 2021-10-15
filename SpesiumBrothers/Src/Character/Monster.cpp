#include "Monster.h"

#include "DxLib.h"

using namespace utility;

namespace character
{
	Monster::Monster()
	{
		status =
		{
			{Vector3(0.0f,0.0f,0.0f)}, // 座標
			{Vector3(0.0f,0.0f,0.0f)}, // 移動量
			{Vector3(0.0f,0.0f,0.0f)}, // 速度量
			0.0f,			  // 回転角

			0,		// 体力
			0,		// シールド量
			0,		// 攻撃力
			1.0f,	// 速度
			10.0f,	// 最大速度
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
			status.speedVec.Y = 0.0f;

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

	void Monster::Draw(function::Camera camera)
	{
		Vector3 drawPos = camera.ConvertWorldPosToScreen(status.pos);

		MV1SetPosition(modelHandle, drawPos);

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
		modelHandle = MV1LoadModel("Res/Model/monster_04.mv1");
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

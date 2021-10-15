#include "CharacterBase.h"

#include "DxLib.h"

using namespace utility;

namespace character
{
	void character::CharacterBase::Move()
	{
		// 右移動
		if (inputManager.lock()->IsKeyPushed(KEY_INPUT_RIGHT) ||
			inputManager.lock()->IsKeyHeld(KEY_INPUT_RIGHT))
		{
			status.speedVec.X += status.speed;

			if (status.speedVec.X > status.maxSpeed)
			{
				status.speedVec.X = status.maxSpeed;
			}
		}

		// 左移動
		if (inputManager.lock()->IsKeyPushed(KEY_INPUT_LEFT) ||
			inputManager.lock()->IsKeyHeld(KEY_INPUT_LEFT))
		{
			status.speedVec.X -= status.speed;

			if (status.speedVec.X < (status.maxSpeed * -1))
			{
				status.speedVec.X = (status.maxSpeed * -1);
			}
		}
	}

	void character::CharacterBase::Jump()
	{
		if (!inputManager.lock()->IsKeyPushed(KEY_INPUT_UP)) { return; }

		if (IsStanding())
		{
			status.speedVec.Y = status.jumpPower;
		}
	}

	void CharacterBase::UpdateDirection()
	{
		// 右向きに変更
		if (status.speedVec.X > 0 && (!inputManager.lock()->IsKeyPushed(KEY_INPUT_RIGHT) || !inputManager.lock()->IsKeyHeld(KEY_INPUT_RIGHT)))
		{
			status.angle = 270.0f;
		}

		// 左向きに変更
		if (status.speedVec.X < 0 && (!inputManager.lock()->IsKeyPushed(KEY_INPUT_LEFT) || !inputManager.lock()->IsKeyHeld(KEY_INPUT_LEFT)))
		{
			status.angle = 90.0f;
		}
	}

	void character::CharacterBase::Gravity()
	{
		status.speedVec.Y -= gravityVec;
	}

	bool character::CharacterBase::IsStanding() const
	{
		if (status.pos.Y < 0)
		{
			return true;
		}

		return false;
	}

	void character::CharacterBase::KineticFriction()
	{
		// 右移動
		if (status.speedVec.X > 0 && (!inputManager.lock()->IsKeyPushed(KEY_INPUT_RIGHT) || !inputManager.lock()->IsKeyHeld(KEY_INPUT_RIGHT)))
		{
			status.speedVec.X -= frictionVec;

			status.angle = 270.0f;

			if (status.speedVec.X < 0)
			{
				status.speedVec.X = 0;
			}
		}

		// 左移動
		if (status.speedVec.X < 0 && (!inputManager.lock()->IsKeyPushed(KEY_INPUT_LEFT) || !inputManager.lock()->IsKeyHeld(KEY_INPUT_LEFT)))
		{
			status.speedVec.X += frictionVec;

			status.angle = 90.0f;

			if (status.speedVec.X > 0)
			{
				status.speedVec.X = 0;
			}
		}
	}

	void character::CharacterBase::UpdatePos()
	{
		// X座標
		status.moveVec.X = static_cast<double>(status.speedVec.X);
		status.pos.X += status.moveVec.X;
		// Y座標
		status.moveVec.Y = static_cast<double>(status.speedVec.Y);
		status.pos.Y += status.moveVec.Y;
	}
}

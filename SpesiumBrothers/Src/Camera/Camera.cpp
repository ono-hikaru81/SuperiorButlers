#include "Camera.h"

#include <cmath>

#include "../Definition.h"

using namespace utility;

namespace tool
{
	void Camera::UpdatePos(const Vector3& distance_characters_pos1_, const Vector3& distance_characters_pos2_)
	{
		UpdateFlat(distance_characters_pos1_, distance_characters_pos2_);
		UpdateDepth(distance_characters_pos1_, distance_characters_pos2_);

		SetCameraPositionAndTargetAndUpVec(pos, gazePos, Vector3(0.0, 1.0, 0.0));
	}

	void Camera::UpdateFlat(const Vector3& distance_characters_pos1_, const Vector3& distance_characters_pos2_)
	{
		double middleX = (distance_characters_pos1_.X + distance_characters_pos2_.X) / 2;
		double middleY = (distance_characters_pos1_.Y + distance_characters_pos2_.Y) / 2;

		gazePos.X = middleX;
		gazePos.Y = middleY;

		if (double differenceOfPosX = (pos.X - middleX); differenceOfPosX >= 0.0)
		{
			pos.X -= speed;

			if (differenceOfPosX < 0.0)
			{
				pos.X = middleX;
			}
		}
		else
		{
			pos.X += speed;

			if (differenceOfPosX >= 0.0)
			{
				pos.X = middleX;
			}
		}

		if (double differenceOfPosY = (pos.Y - middleY); differenceOfPosY >= 0.0)
		{
			pos.Y -= speed;

			if (differenceOfPosY < 0.0)
			{
				pos.Y = middleY;
			}
		}
		else
		{
			pos.Y += speed;

			if (differenceOfPosY >= 0.0)
			{
				pos.Y = middleY;
			}
		}
	}

	void Camera::UpdateDepth(const Vector3& distance_characters_pos1_, const Vector3& distance_characters_pos2_)
	{
		double distanceX = fabs(distance_characters_pos2_.X - distance_characters_pos1_.X);
		double distanceY = fabs(distance_characters_pos2_.Y - distance_characters_pos1_.Y);
		double hypotenuse = sqrt(pow(distanceX, 2.0) + pow(distanceY, 2.0));

		double depthValue = initialDepthValue + (-hypotenuse) / 2;

		pos.Z = depthValue;

#if _DEBUG
		DrawSphere3D(VGet(pos.X, pos.Y, pos.Z), 50.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
		DrawSphere3D(VGet(gazePos.X, gazePos.Y, gazePos.Z), 50.0f, 32, GetColor(0, 255, 0), GetColor(255, 255, 255), TRUE);
		DrawFormatString(0, 100, GetColor(0, 255, 0), "2点間距離[%d]", static_cast<int32_t>(hypotenuse));
		DrawFormatString(0, 200, GetColor(0, 255, 0), "カメラX座標[%d]", static_cast<int32_t>(pos.X));
		DrawFormatString(0, 300, GetColor(0, 255, 0), "カメラY座標[%d]", static_cast<int32_t>(pos.Y));
		DrawFormatString(0, 400, GetColor(0, 255, 0), "カメラZ座標[%d]", static_cast<int32_t>(pos.Z));
		DrawFormatString(0, 500, GetColor(0, 255, 0), "注視点X座標[%d]", static_cast<int32_t>(gazePos.X));
		DrawFormatString(0, 600, GetColor(0, 255, 0), "注視点Y座標[%d]", static_cast<int32_t>(gazePos.Y));
		DrawFormatString(0, 700, GetColor(0, 255, 0), "注視点Z座標[%d]", static_cast<int32_t>(gazePos.Z));
#endif // DEBUG
	}
}

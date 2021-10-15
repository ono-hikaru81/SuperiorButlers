#include "Camera.h"

#include <math.h>

#include "../Definition.h"

using namespace utility;

namespace function
{
	void Camera::Update(Vector3 pos1_, Vector3 pos2_)
	{
		UpdateFlat(pos1_, pos2_);
		UpdateDepth(pos1_, pos2_);

		gazePos.X = pos.X.Cast<float>();
		gazePos.Y = pos.Y.Cast<float>();

		SetCameraPositionAndTargetAndUpVec(pos, gazePos, VGet(0.0f, 1.0f, 0.0f));
	}

	Vector3 Camera::ConvertWorldPosToScreen(Vector3 pos_)
	{
		return pos_;
	}

	void Camera::UpdateFlat(Vector3 pos1_, Vector3 pos2_)
	{
		float middleX = (pos1_.X.Cast<float>() + pos2_.X.Cast<float>()) / 2;
		float middleY = (pos1_.Y.Cast<float>() + pos2_.Y.Cast<float>()) / 2;

		gazePos.X = middleX;
		gazePos.Y = middleY;

		if ((pos.X - middleX) >= 0.0f)
		{
			pos.X -= speed;

			if (pos.X - middleX <= 0.0f)
			{
				pos.X = middleX;
			}
		}
		else if ((pos.X - middleX) <= 0.0f)
		{
			pos.X += speed;

			if (pos.X - middleX >= 0.0f)
			{
				pos.X = middleX;
			}
		}
	}

	void Camera::UpdateDepth(Vector3 pos1_, Vector3 pos2_)
	{
		float distanceX = fabsf(pos2_.X.Cast<float>() - pos1_.X.Cast<float>());
		float distanceY = fabsf(pos2_.Y.Cast<float>() - pos1_.Y.Cast<float>());
		float hypotenuse = sqrtf(powf(distanceX, 2.0f) + powf(distanceY, 2.0f));

		float depthValue = initialDepthValue + (-hypotenuse) / 2;

		pos.Z = depthValue;

#if _DEBUG
		DrawSphere3D(VGet(pos.X.Cast<float>(), pos.Y.Cast<float>(), pos.Z.Cast<float>()), 50.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
		DrawSphere3D(VGet(gazePos.X.Cast<float>(), gazePos.Y.Cast<float>(), gazePos.Z.Cast<float>()), 50.0f, 32, GetColor(0, 255, 0), GetColor(255, 255, 255), TRUE);
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


#include <Character/Human.h>
#include <DxLib.h>

namespace spesium {
    namespace character {
        Human::Human() {
            status = {
                .hp = 0,
                .shieldAmount = 0,
                .power = 0,
                .speed = 1.0,
                .maxSpeed = 10.0,
                .jumpPower = 10.0,
                .canJumpNum = 2,
            };

            modelName = "Res/Model/test.mv1";

            LoadModel();

            motionList = {
                .wait = { .motionModelHandle = MV1AttachAnim( modelHandle, 0, -1, FALSE ), .startFrame { MotionList::wait.start }, .totalFrame { MotionList::wait.total } },
                .run = { .startFrame { MotionList::run.start }, .totalFrame { MotionList::run.total } },
                .jump = { .startFrame { MotionList::jump.start }, .totalFrame { MotionList::jump.total } },
                .doubleJump = { .startFrame { MotionList::doubleJump.start }, .totalFrame { MotionList::doubleJump.total } },
                .guard = { .startFrame { MotionList::guard.start }, .totalFrame { MotionList::guard.total } },
                .neutralAttack = { .startFrame { MotionList::neutralAttack.start }, .totalFrame { MotionList::neutralAttack.total } },
                .strongAttack = { .startFrame { MotionList::strongAttack.start }, .totalFrame { MotionList::strongAttack.total } },
                .aerialNeutralAttack = { .startFrame { MotionList::aerialNeutralAttack.start }, .totalFrame { MotionList::aerialNeutralAttack.total } },
                .aerialStrongAttack = { .startFrame { MotionList::aerialStrongAttack.start }, .totalFrame { MotionList::aerialStrongAttack.total } },
                .fallLanding = { .startFrame { MotionList::fallLanding.start }, .totalFrame { MotionList::fallLanding.total } },
                .smallHitBack = { .startFrame { MotionList::smallHitBack.start }, .totalFrame { MotionList::smallHitBack.total } },
                .bigHitBack = { .startFrame { MotionList::bigHitBack.start }, .totalFrame { MotionList::bigHitBack.total } },
                .fall = { .startFrame { MotionList::fall.start }, .totalFrame { MotionList::fall.total } },
                .turn = { .startFrame { MotionList::turn.start }, .totalFrame { MotionList::turn.total } },
            };

            //SwitchMotion( motionList.wait );
            UpdateMotion();

        }  // namespace character

        Human::~Human() {
            ReleaseModel();
        }

        void Human::Draw() {
            MV1SetPosition( modelHandle, pos );

            MV1SetRotationXYZ( modelHandle, Vector3( 0.0, angle / 180.0 * DX_PI, 0.0 ) );

            MV1DrawModel( modelHandle );

#if _DEBUG
            DrawFormatString( 0, 0, GetColor( 0, 255, 0 ), "モンスター座標[%d,%d]", static_cast<int32_t>( pos.X ), static_cast<int32_t>( pos.Y ) );
#endif  // _DEBUG
        }

    }  // namespace character
}  // namespace spesium

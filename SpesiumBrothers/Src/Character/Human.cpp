
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

            InitMotionList( MotionList {
                .wait = { .motionModelHandle = MV1AttachAnim( modelHandle, 0, -1, FALSE ), .startFrame { MotionDataList::wait.start }, .totalFrame { MotionDataList::wait.total } },
                .run = { .startFrame { MotionDataList::run.start }, .totalFrame { MotionDataList::run.total } },
                .jump = { .startFrame { MotionDataList::jump.start }, .totalFrame { MotionDataList::jump.total } },
                .doubleJump = { .startFrame { MotionDataList::doubleJump.start }, .totalFrame { MotionDataList::doubleJump.total } },
                .guard = { .startFrame { MotionDataList::guard.start }, .totalFrame { MotionDataList::guard.total } },
                .neutralAttack = { .startFrame { MotionDataList::neutralAttack.start }, .totalFrame { MotionDataList::neutralAttack.total } },
                .strongAttack = { .startFrame { MotionDataList::strongAttack.start }, .totalFrame { MotionDataList::strongAttack.total } },
                .aerialNeutralAttack = { .startFrame { MotionDataList::aerialNeutralAttack.start }, .totalFrame { MotionDataList::aerialNeutralAttack.total } },
                .aerialStrongAttack = { .startFrame { MotionDataList::aerialStrongAttack.start }, .totalFrame { MotionDataList::aerialStrongAttack.total } },
                .fallLanding = { .startFrame { MotionDataList::fallLanding.start }, .totalFrame { MotionDataList::fallLanding.total } },
                .smallHitBack = { .startFrame { MotionDataList::smallHitBack.start }, .totalFrame { MotionDataList::smallHitBack.total } },
                .bigHitBack = { .startFrame { MotionDataList::bigHitBack.start }, .totalFrame { MotionDataList::bigHitBack.total } },
                .fall = { .startFrame { MotionDataList::fall.start }, .totalFrame { MotionDataList::fall.total } },
                .turn = { .startFrame { MotionDataList::turn.start }, .totalFrame { MotionDataList::turn.total } },
            } );

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

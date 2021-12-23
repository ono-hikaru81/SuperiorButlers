
#include <Character/Monster.h>
#include <DxLib.h>

namespace spesium {
    namespace character {
        Monster::Monster() {
            status = {
                .hp = 0,
                .shieldAmount = 0,
                .power = 0,
                .speed = 1.0,
                .maxSpeed = 10.0,
                .jumpPower = 10.0,
                .canJumpNum = 2,
            };

            modelName = "Res/Model/motion_monster.mv1";

            motionModel = { 0 };

            motionPlayTime = {
                .wait = InitMotionTime::wait,
                .run = InitMotionTime::run,
                .jump = InitMotionTime::jump,
                .doubleJump = InitMotionTime::doubleJump,
                .guard = InitMotionTime::guard,
                .neutralAttack = InitMotionTime::neutralAttack,
                .strongAttack = InitMotionTime::strongAttack,
                .aerialNeutralAttack = InitMotionTime::aerialNeutralAttack,
                .aerialStrongAttack = InitMotionTime::aerialStrongAttack,
                .fallLanding = InitMotionTime::fallLanding,
                .smallHitBack = InitMotionTime::smallHitBack,
                .bigHitBack = InitMotionTime::bigHitBack,
                .fall = InitMotionTime::fall,
                .turn = InitMotionTime::turn,
            };

            motionTotalTime = {
                .wait = 120.0f,
                .run = 168.0f,
                .jump = 239.0f,
                .doubleJump = 298.0f,
                .guard = 305.0f,
                .neutralAttack = 331.0f,
                .strongAttack = 363.0f,
                .aerialNeutralAttack = 394.0f,
                .aerialStrongAttack = 433.0f,
                .fallLanding = 467.0f,
                .smallHitBack = 472.0,
                .bigHitBack = 515.0f,
                .fall = 562.0f,
                .turn = 568.0f,
            };

            LoadModel();

            motionModel.wait = MV1AttachAnim( model, 0, -1, FALSE );
        }

        Monster::~Monster() {
            ReleaseModel();
        }

        void Monster::Draw() {
            MV1SetPosition( model, pos );

            MV1SetRotationXYZ( model, Vector3( 0.0, angle / 180.0 * DX_PI, 0.0 ) );

            MV1DrawModel( model );

#if _DEBUG
            DrawFormatString( 0, 0, GetColor( 0, 255, 0 ), "モンスター座標[%d,%d]", static_cast<int32_t>( pos.X ), static_cast<int32_t>( pos.Y ) );
#endif  // _DEBUG
        }

        void Monster::WaitMotion() {
            motionPlayTime.wait += 1.0f;

            // 再生時間を0に戻す
            if ( motionPlayTime.wait >= motionTotalTime.wait ) {
                motionPlayTime.wait = InitMotionTime::wait;
            }

            MV1SetAttachAnimTime( model, motionModel.wait, motionPlayTime.wait );

            DrawFormatString( 300, 0, GetColor( 0, 255, 0 ), "待機モーション再生時間(加算値)[%lf]", motionPlayTime.wait );
        }

        void Monster::DashMotion() {
            motionPlayTime.run += 1.0f;

            if ( motionPlayTime.run >= motionTotalTime.run ) {
                motionPlayTime.run = InitMotionTime::run;
            }

            MV1SetAttachAnimTime( model, motionModel.run, motionPlayTime.run );

            DrawFormatString( 300, 0, GetColor( 0, 255, 0 ), "待機モーション再生時間(加算値)[%lf]", motionPlayTime.run );
        }

        void Monster::JumpMotion() {
            motionPlayTime.jump += 1.0f;

            if ( motionPlayTime.jump >= motionTotalTime.jump ) {
                motionPlayTime.jump = InitMotionTime::jump;
            }

            MV1SetAttachAnimTime( model, motionModel.jump, motionPlayTime.jump );

            DrawFormatString( 300, 0, GetColor( 0, 255, 0 ), "待機モーション再生時間(加算値)[%lf]", motionPlayTime.jump );
        }

        void Monster::DoubleJumpMotion() {
            motionPlayTime.doubleJump += 1.0f;

            if ( motionPlayTime.doubleJump >= motionTotalTime.doubleJump ) {
                motionPlayTime.doubleJump = InitMotionTime::doubleJump;
            }

            MV1SetAttachAnimTime( model, motionModel.doubleJump, motionPlayTime.doubleJump );

            DrawFormatString( 300, 0, GetColor( 0, 255, 0 ), "待機モーション再生時間(加算値)[%lf]", motionPlayTime.doubleJump );
        }

        void Monster::GuardMotion() {
            motionPlayTime.guard += 1.0f;

            if ( motionPlayTime.guard >= motionTotalTime.guard ) {
                motionPlayTime.guard = InitMotionTime::guard;
            }

            MV1SetAttachAnimTime( model, motionModel.guard, motionPlayTime.guard );

            DrawFormatString( 300, 0, GetColor( 0, 255, 0 ), "待機モーション再生時間(加算値)[%lf]", motionPlayTime.guard );
        }

        void Monster::NeutralAttackMotion() {
            motionPlayTime.neutralAttack += 1.0f;

            if ( motionPlayTime.neutralAttack >= motionTotalTime.neutralAttack ) {
                motionPlayTime.neutralAttack = InitMotionTime::neutralAttack;
            }

            MV1SetAttachAnimTime( model, motionModel.neutralAttack, motionPlayTime.neutralAttack );

            DrawFormatString( 300, 0, GetColor( 0, 255, 0 ), "待機モーション再生時間(加算値)[%lf]", motionPlayTime.neutralAttack );
        }

        void Monster::StrongAttackMotion() {
            motionPlayTime.strongAttack += 1.0f;

            if ( motionPlayTime.strongAttack >= motionTotalTime.strongAttack ) {
                motionPlayTime.strongAttack = InitMotionTime::strongAttack;
            }

            MV1SetAttachAnimTime( model, motionModel.strongAttack, motionPlayTime.strongAttack );

            DrawFormatString( 300, 0, GetColor( 0, 255, 0 ), "待機モーション再生時間(加算値)[%lf]", motionPlayTime.strongAttack );
        }

        void Monster::AerialNeutralAttackMotion() {
            motionPlayTime.aerialNeutralAttack += 1.0f;

            if ( motionPlayTime.aerialNeutralAttack >= motionTotalTime.aerialNeutralAttack ) {
                motionPlayTime.aerialNeutralAttack = InitMotionTime::aerialNeutralAttack;
            }

            MV1SetAttachAnimTime( model, motionModel.aerialNeutralAttack, motionPlayTime.aerialNeutralAttack );

            DrawFormatString( 300, 0, GetColor( 0, 255, 0 ), "待機モーション再生時間(加算値)[%lf]", motionPlayTime.aerialNeutralAttack );
        }

        void Monster::AerialStrongAttackMotion() {
            motionPlayTime.aerialStrongAttack += 1.0f;

            if ( motionPlayTime.aerialStrongAttack >= motionTotalTime.aerialStrongAttack ) {
                motionPlayTime.aerialStrongAttack = InitMotionTime::aerialStrongAttack;
            }

            MV1SetAttachAnimTime( model, motionModel.aerialStrongAttack, motionPlayTime.aerialStrongAttack );

            DrawFormatString( 300, 0, GetColor( 0, 255, 0 ), "待機モーション再生時間(加算値)[%lf]", motionPlayTime.aerialStrongAttack );
        }

        void Monster::FallLandingMotion() {
            motionPlayTime.fallLanding += 1.0f;

            if ( motionPlayTime.fallLanding >= motionTotalTime.fallLanding ) {
                motionPlayTime.fallLanding = InitMotionTime::fallLanding;
            }

            MV1SetAttachAnimTime( model, motionModel.fallLanding, motionPlayTime.fallLanding );

            DrawFormatString( 300, 0, GetColor( 0, 255, 0 ), "待機モーション再生時間(加算値)[%lf]", motionPlayTime.fallLanding );
        }

        void Monster::SmallHitBackMotion() {
            motionPlayTime.smallHitBack += 1.0f;

            if ( motionPlayTime.smallHitBack >= motionTotalTime.smallHitBack ) {
                motionPlayTime.smallHitBack = InitMotionTime::smallHitBack;
            }

            MV1SetAttachAnimTime( model, motionModel.smallHitBack, motionPlayTime.smallHitBack );

            DrawFormatString( 300, 0, GetColor( 0, 255, 0 ), "待機モーション再生時間(加算値)[%lf]", motionPlayTime.smallHitBack );
        }

        void Monster::BigHitBackMotion() {
            motionPlayTime.bigHitBack += 1.0f;

            if ( motionPlayTime.bigHitBack >= motionTotalTime.bigHitBack ) {
                motionPlayTime.bigHitBack = InitMotionTime::bigHitBack;
            }

            MV1SetAttachAnimTime( model, motionModel.bigHitBack, motionPlayTime.bigHitBack );

            DrawFormatString( 300, 0, GetColor( 0, 255, 0 ), "待機モーション再生時間(加算値)[%lf]", motionPlayTime.bigHitBack );
        }

        void Monster::FallMotion() {
            motionPlayTime.fall += 1.0f;

            if ( motionPlayTime.fall >= motionTotalTime.fall ) {
                motionPlayTime.fall = InitMotionTime::fall;
            }

            MV1SetAttachAnimTime( model, motionModel.fall, motionPlayTime.fall );

            DrawFormatString( 300, 0, GetColor( 0, 255, 0 ), "待機モーション再生時間(加算値)[%lf]", motionPlayTime.fall );
        }

        void Monster::TurnMotion() {
            motionPlayTime.turn += 1.0f;

            if ( motionPlayTime.turn >= motionTotalTime.turn ) {
                motionPlayTime.turn = InitMotionTime::turn;
            }

            MV1SetAttachAnimTime( model, motionModel.turn, motionPlayTime.turn );

            DrawFormatString( 300, 0, GetColor( 0, 255, 0 ), "待機モーション再生時間(加算値)[%lf]", motionPlayTime.turn );
        }
    }  // namespace character
}  // namespace spesium

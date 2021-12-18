
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

            modelName = "Res/Model/motion_human.mv1";

            motionModel = {};

            motionModelName = {};

            playMotionTime = {
                .wait = 0.0,
                .dash = 121.0 / 2,
                .jump = 169.0 / 2,
                .twoStepJump = 240.0 / 2,
                .guard = 299.0 / 2,
                .neutralAttack = 306.0,
                .strongAttack = 318.0,
                .aerialNeutralAttack = 340.0,
                .aerialStrongAttack = 358.0,
                .landing = 387.0,
                .smallHitBackMotion = 421.0,
                .bigHitBackMotion = 426.0,
                .fall = 469.0,
                .turn = 516.0,
            };

            playTotalMotionTime = {
                .wait = 120.0 / 2,
                .dash = 168.0 / 2,
                .jump = 239.0 / 2,
                .twoStepJump = 298.0 / 2,
                .guard = 305.0 / 2,
                .neutralAttack = 317.0 / 2,
                .strongAttack = 339.0 / 2,
                .aerialNeutralAttack = 357.0 / 2,
                .aerialStrongAttack = 386.0 / 2,
                .landing = 420.0 / 2,
                .smallHitBackMotion = 425.0 / 2,
                .bigHitBackMotion = 468.0 / 2,
                .fall = 515.0 / 2,
                .turn = 521.0 / 2,
            };

            LoadModel();

            motionModel.wait = MV1AttachAnim( model, 0, -1, FALSE );
        }

        Human::~Human() {
            ReleaseModel();
        }

        void Human::Draw() {
            MV1SetPosition( model, pos );

            MV1SetRotationXYZ( model, Vector3( 0.0, angle / 180.0 * DX_PI, 0.0 ) );

            TurnMotion();

            MV1DrawModel( model );

#if _DEBUG
            DrawFormatString( 0, 0, GetColor( 0, 255, 0 ), "モンスター座標[%d,%d]", static_cast<int32_t>( pos.X ), static_cast<int32_t>( pos.Y ) );
#endif  // _DEBUG
        }

        void Human::WaitMotion() {
            count += 1;

            if ( count % 2 == 0 ) {
                playMotionTime.wait += 1;
            }

            // 再生時間を0に戻す
            if ( playMotionTime.wait >= playTotalMotionTime.wait ) {
                playMotionTime.wait = 0.0;
            }

            MV1SetAttachAnimTime( model, motionModel.wait, playMotionTime.wait );

            DrawFormatString( 300, 0, GetColor( 0, 255, 0 ), "待機モーション再生時間(加算値)[%d]", playMotionTime.wait );
        }

        void Human::DashMotion() {
            count += 1;

            if ( count % 2 == 0 ) {
                playMotionTime.dash += 1;
            }

            if ( playMotionTime.dash >= playTotalMotionTime.dash ) {
                playMotionTime.dash = 121.0 / 2;
            }

            MV1SetAttachAnimTime( model, motionModel.dash, playMotionTime.dash );
        }

        void Human::JumpMotion() {
            count += 1;

            if ( count % 2 == 0 ) {
                playMotionTime.jump += 1;
            }

            if ( playMotionTime.jump >= playTotalMotionTime.jump ) {
                playMotionTime.jump = 169.0 / 2;
            }

            MV1SetAttachAnimTime( model, motionModel.jump, playMotionTime.jump );
        }

        void Human::TwoStepJumpMotion() {
            count += 1;

            if ( count % 2 == 0 ) {
                playMotionTime.twoStepJump += 1;
            }

            if ( playMotionTime.twoStepJump >= playTotalMotionTime.twoStepJump ) {
                playMotionTime.twoStepJump = 240.0 / 2;
            }

            MV1SetAttachAnimTime( model, motionModel.twoStepJump, playMotionTime.twoStepJump );
        }

        void Human::GuardMotion() {
            count += 1;

            if ( count % 2 == 0 ) {
                playMotionTime.guard += 1;
            }

            if ( playMotionTime.guard >= playTotalMotionTime.guard ) {
                playMotionTime.guard = 299.0 / 2;
            }

            MV1SetAttachAnimTime( model, motionModel.guard, playMotionTime.guard );
        }

        void Human::NeutralAttackMotion() {
            count += 1;

            if ( count % 2 == 0 ) {
                playMotionTime.neutralAttack += 1;
            }

            if ( playMotionTime.neutralAttack >= playTotalMotionTime.neutralAttack ) {
                playMotionTime.neutralAttack = 306.0 / 2;
            }

            MV1SetAttachAnimTime( model, motionModel.neutralAttack, playMotionTime.neutralAttack );
        }

        void Human::StrongAttackMotion() {
            count += 1;

            if ( count % 2 == 0 ) {
                playMotionTime.strongAttack += 1;
            }

            if ( playMotionTime.strongAttack >= playTotalMotionTime.strongAttack ) {
                playMotionTime.strongAttack = 318.0 / 2;
            }

            MV1SetAttachAnimTime( model, motionModel.strongAttack, playMotionTime.strongAttack );
        }

        void Human::AerialNeutralAttackMotion() {
            count += 1;

            if ( count % 2 == 0 ) {
                playMotionTime.aerialNeutralAttack += 1;
            }

            if ( playMotionTime.aerialNeutralAttack >= playTotalMotionTime.aerialNeutralAttack ) {
                playMotionTime.aerialNeutralAttack = 340.0 / 2;
            }

            MV1SetAttachAnimTime( model, motionModel.aerialNeutralAttack, playMotionTime.aerialNeutralAttack );
        }

        void Human::AerialStrongAttackMotion() {
            count += 1;

            if ( count % 2 == 0 ) {
                playMotionTime.aerialStrongAttack += 1;
            }

            if ( playMotionTime.aerialStrongAttack >= playTotalMotionTime.aerialStrongAttack ) {
                playMotionTime.aerialStrongAttack = 358.0 / 2;
            }

            MV1SetAttachAnimTime( model, motionModel.aerialStrongAttack, playMotionTime.aerialStrongAttack );
        }

        void Human::LandingMotion() {
            count += 1;

            if ( count % 2 == 0 ) {
                playMotionTime.landing += 1;
            }

            if ( playMotionTime.landing >= playTotalMotionTime.landing ) {
                playMotionTime.landing = 387.0 / 2;
            }

            MV1SetAttachAnimTime( model, motionModel.landing, playMotionTime.landing );
        }

        void Human::SmallHitBackMotion() {
            count += 1;

            if ( count % 2 == 0 ) {
                playMotionTime.smallHitBackMotion += 1;
            }

            if ( playMotionTime.smallHitBackMotion >= playTotalMotionTime.smallHitBackMotion ) {
                playMotionTime.smallHitBackMotion = 421.0 / 2;
            }

            MV1SetAttachAnimTime( model, motionModel.smallHitBackMotion, playMotionTime.landing );
        }

        void Human::BigHitBackMotion() {
            count += 1;

            if ( count % 2 == 0 ) {
                playMotionTime.bigHitBackMotion += 1;
            }

            if ( playMotionTime.bigHitBackMotion >= playTotalMotionTime.bigHitBackMotion ) {
                playMotionTime.bigHitBackMotion = 426.0 / 2;
            }

            MV1SetAttachAnimTime( model, motionModel.bigHitBackMotion, playMotionTime.bigHitBackMotion );
        }

        void Human::FallMotion() {
            count += 1;

            if ( count % 2 == 0 ) {
                playMotionTime.fall += 1;
            }

            if ( playMotionTime.fall >= playTotalMotionTime.fall ) {
                playMotionTime.fall = 469.0 / 2;
            }

            MV1SetAttachAnimTime( model, motionModel.fall, playMotionTime.fall );
        }

        void Human::TurnMotion() {
            count += 1;

            if ( count % 2 == 0 ) {
                playMotionTime.turn += 1;
            }

            if ( playMotionTime.turn >= playTotalMotionTime.turn ) {
                playMotionTime.turn = 516.0 / 2;
            }

            MV1SetAttachAnimTime( model, motionModel.turn, playMotionTime.turn );
        }
    }  // namespace character
}  // namespace spesium

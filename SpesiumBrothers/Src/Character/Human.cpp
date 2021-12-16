
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

            motionModel = {};

            motionModelName = {};

            playMotionTime = {};

            playTotalMotionTime = {};
        }

        Human::~Human() {
        }

        void Human::Draw() {
            MV1SetPosition( model, pos );

            MV1SetRotationXYZ( model, Vector3( 0.0, angle / 180.0 * DX_PI, 0.0 ) );

            MV1DrawModel( model );

#if _DEBUG
            DrawFormatString( 0, 0, GetColor( 0, 255, 0 ), "モンスター座標[%d,%d]", static_cast<int32_t>( pos.X ), static_cast<int32_t>( pos.Y ) );
#endif  // _DEBUG
        }

        void Human::WaitMotion() {
            // 再生時間を0に戻す
            if ( playMotionTime.wait >= playTotalMotionTime.wait ) {
                playMotionTime.wait = 0.0f;
            }

            MV1SetAttachAnimTime( model, motionModel.wait, playMotionTime.wait );
        }

        void Human::DashMotion() {
            MV1SetAttachAnimTime( model, motionModel.dash, playMotionTime.dash );
        }

        void Human::JumpMotion() {
            MV1SetAttachAnimTime( model, motionModel.jump, playMotionTime.jump );
        }

        void Human::TwoStepJumpMotion() {
            MV1SetAttachAnimTime( model, motionModel.twoStepJump, playMotionTime.twoStepJump );
        }

        void Human::GuardMotion() {
            MV1SetAttachAnimTime( model, motionModel.guard, playMotionTime.guard );
        }

        void Human::NeutralAttackMotion() {
            MV1SetAttachAnimTime( model, motionModel.neutralAttack, playMotionTime.neutralAttack );
        }

        void Human::StrongAttackMotion() {
            MV1SetAttachAnimTime( model, motionModel.strongAttack, playMotionTime.strongAttack );
        }

        void Human::AerialNeutralAttackMotion() {
            MV1SetAttachAnimTime( model, motionModel.aerialNeutralAttack, playMotionTime.aerialNeutralAttack );
        }

        void Human::AerialStrongAttackMotion() {
            MV1SetAttachAnimTime( model, motionModel.aerialStrongAttack, playMotionTime.aerialStrongAttack );
        }

        void Human::LandingMotion() {
            MV1SetAttachAnimTime( model, motionModel.landing, playMotionTime.landing );
        }

        void Human::SmallHitBackMotion() {
            MV1SetAttachAnimTime( model, motionModel.smallHitBackMotion, playMotionTime.landing );
        }

        void Human::BigHitBackMotion() {
            MV1SetAttachAnimTime( model, motionModel.bigHitBackMotion, playMotionTime.bigHitBackMotion );
        }

        void Human::FallMotion() {
            MV1SetAttachAnimTime( model, motionModel.fall, playMotionTime.fall );
        }

        void Human::TurnMotion() {
            MV1SetAttachAnimTime( model, motionModel.turn, playMotionTime.turn );
        }
    }  // namespace character
}  // namespace spesium


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

            motionModel = {};

            motionModelName = {};

            playMotionTime = {};

            playTotalMotionTime = {};
        }

        Monster::~Monster() {
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
            // 再生時間を0に戻す
            if ( playMotionTime.wait >= playTotalMotionTime.wait ) {
                playMotionTime.wait = 0.0f;
            }

            MV1SetAttachAnimTime( model, motionModel.wait, playMotionTime.wait );
        }

        void Monster::DashMotion() {
            MV1SetAttachAnimTime( model, motionModel.dash, playMotionTime.dash );
        }

        void Monster::JumpMotion() {
            MV1SetAttachAnimTime( model, motionModel.jump, playMotionTime.jump );
        }

        void Monster::TwoStepJumpMotion() {
            MV1SetAttachAnimTime( model, motionModel.twoStepJump, playMotionTime.twoStepJump );
        }

        void Monster::GuardMotion() {
            MV1SetAttachAnimTime( model, motionModel.guard, playMotionTime.guard );
        }

        void Monster::NeutralAttackMotion() {
            MV1SetAttachAnimTime( model, motionModel.neutralAttack, playMotionTime.neutralAttack );
        }

        void Monster::StrongAttackMotion() {
            MV1SetAttachAnimTime( model, motionModel.strongAttack, playMotionTime.strongAttack );
        }

        void Monster::AerialNeutralAttackMotion() {
            MV1SetAttachAnimTime( model, motionModel.aerialNeutralAttack, playMotionTime.aerialNeutralAttack );
        }

        void Monster::AerialStrongAttackMotion() {
            MV1SetAttachAnimTime( model, motionModel.aerialStrongAttack, playMotionTime.aerialStrongAttack );
        }

        void Monster::LandingMotion() {
            MV1SetAttachAnimTime( model, motionModel.landing, playMotionTime.landing );
        }

        void Monster::SmallHitBackMotion() {
            MV1SetAttachAnimTime( model, motionModel.smallHitBackMotion, playMotionTime.landing );
        }

        void Monster::BigHitBackMotion() {
            MV1SetAttachAnimTime( model, motionModel.bigHitBackMotion, playMotionTime.bigHitBackMotion );
        }

        void Monster::FallMotion() {
            MV1SetAttachAnimTime( model, motionModel.fall, playMotionTime.fall );
        }

        void Monster::TurnMotion() {
            MV1SetAttachAnimTime( model, motionModel.turn, playMotionTime.turn );
        }
    }  // namespace character
}  // namespace spesium

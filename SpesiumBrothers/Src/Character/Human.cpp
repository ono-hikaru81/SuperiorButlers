
#include <Character/Human.h>
#include <DxLib.h>

namespace spesium {
    namespace character {
        Human::Human() {
            status = {
                { Vector3( 0.0, 0.0, 0.0 ) },  // 座標
                0.0,  // 回転角

                0,  // 体力
                0,  // シールド量
                0,  // 攻撃力
                1.0,  // 速度
                10.0,  // 最大速度
                10.0,  // ジャンプ力
            };

            motionModel = {};

            motionModelName = {};

            playMotionTime = {};

            playTotalMotionTime = {};
        }

        Human::~Human() {
        }

        void Human::Draw() {
            MV1SetPosition( monsterModel, status.pos );

            MV1SetRotationXYZ( monsterModel, Vector3( 0.0, status.angle / 180.0 * DX_PI, 0.0 ) );

            MV1DrawModel( monsterModel );

#if _DEBUG
            DrawFormatString( 0, 0, GetColor( 0, 255, 0 ), "モンスター座標[%d,%d]", static_cast<int32_t>( status.pos.X ), static_cast<int32_t>( status.pos.Y ) );
#endif  // _DEBUG
        }

        void Human::WaitMotion() {
            // 再生時間を0に戻す
            if ( playMotionTime.wait >= playTotalMotionTime.wait ) {
                playMotionTime.wait = 0.0f;
            }

            MV1SetAttachAnimTime( monsterModel, motionModel.wait, playMotionTime.wait );
        }

        void Human::DashMotion() {
            MV1SetAttachAnimTime( monsterModel, motionModel.dash, playMotionTime.dash );
        }

        void Human::JumpMotion() {
            MV1SetAttachAnimTime( monsterModel, motionModel.jump, playMotionTime.jump );
        }

        void Human::TwoStepJumpMotion() {
            MV1SetAttachAnimTime( monsterModel, motionModel.twoStepJump, playMotionTime.twoStepJump );
        }

        void Human::GuardMotion() {
            MV1SetAttachAnimTime( monsterModel, motionModel.guard, playMotionTime.guard );
        }

        void Human::NeutralAttackMotion() {
            MV1SetAttachAnimTime( monsterModel, motionModel.neutralAttack, playMotionTime.neutralAttack );
        }

        void Human::StrongAttackMotion() {
            MV1SetAttachAnimTime( monsterModel, motionModel.strongAttack, playMotionTime.strongAttack );
        }

        void Human::AerialNeutralAttackMotion() {
            MV1SetAttachAnimTime( monsterModel, motionModel.aerialNeutralAttack, playMotionTime.aerialNeutralAttack );
        }

        void Human::AerialStrongAttackMotion() {
            MV1SetAttachAnimTime( monsterModel, motionModel.aerialStrongAttack, playMotionTime.aerialStrongAttack );
        }

        void Human::LandingMotion() {
            MV1SetAttachAnimTime( monsterModel, motionModel.landing, playMotionTime.landing );
        }

        void Human::SmallHitBackMotion() {
            MV1SetAttachAnimTime( monsterModel, motionModel.smallHitBackMotion, playMotionTime.landing );
        }

        void Human::BigHitBackMotion() {
            MV1SetAttachAnimTime( monsterModel, motionModel.bigHitBackMotion, playMotionTime.bigHitBackMotion );
        }

        void Human::FallMotion() {
            MV1SetAttachAnimTime( monsterModel, motionModel.fall, playMotionTime.fall );
        }

        void Human::TurnMotion() {
            MV1SetAttachAnimTime( monsterModel, motionModel.turn, playMotionTime.turn );
        }
    }  // namespace character
}  // namespace spesium

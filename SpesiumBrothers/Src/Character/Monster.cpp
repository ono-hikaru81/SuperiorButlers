
#include <Character/Monster.h>
#include <DxLib.h>

namespace spesium {
    namespace character {
        Monster::Monster() {
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
        }

        Monster::~Monster() {
        }

        void Monster::Draw() {
            MV1SetPosition( monsterModel, status.pos );

            MV1SetRotationXYZ( monsterModel, Vector3( 0.0, status.angle / 180.0 * DX_PI, 0.0 ) );

            MV1DrawModel( monsterModel );

#if _DEBUG
            DrawFormatString( 0, 0, GetColor( 0, 255, 0 ), "モンスター座標[%d,%d]", static_cast<int32_t>( status.pos.X ), static_cast<int32_t>( status.pos.Y ) );
#endif  // _DEBUG
        }

        void Monster::WaitMotion() {
        }
        void Monster::DashMotion() {
        }
        void Monster::JumpMotion() {
        }
        void Monster::TwoStepJumpMotion() {
        }
        void Monster::GuardMotion() {
        }
        void Monster::NeutralAttackMotion() {
        }
        void Monster::StrongAttackMotion() {
        }
        void Monster::AerialNeutralAttackMotion() {
        }
        void Monster::AerialStrongAttackMotion() {
        }
        void Monster::LandingMotion() {
        }
        void Monster::SmallHitBackMotion() {
        }
        void Monster::BigHitBackMotion() {
        }
        void Monster::FallMotion() {
        }
        void Monster::TurnMotion() {
        }
    }  // namespace character
}  // namespace spesium

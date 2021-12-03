
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

            // 待機->移動
            motion.Register( Motion::State::Wait, Motion::State::Run, [this]() { return ( ( abs( velocity.X ) > 0.5 && IsStanding() ) ); } );
            // 移動->待機
            motion.Register( Motion::State::Run, Motion::State::Wait, [this]() { return ( ( abs( velocity.X ) < 0.5 && IsStanding() ) ); } );
            // 待機->ガード
            motion.Register( Motion::State::Wait, Motion::State::Guard, [this]() { return inputManager.lock()->IsKeyPushed( KEY_INPUT_S ); } );
            // ガード->待機
            motion.Register( Motion::State::Guard, Motion::State::Wait, [this]() { return inputManager.lock()->IsKeyReleased( KEY_INPUT_S ); } );
            // 待機->ジャンプ
            motion.Register( Motion::State::Wait, Motion::State::Jump, [this]() { return inputManager.lock()->IsKeyPushed( KEY_INPUT_W ); } );
            // ジャンプ->待機
            motion.Register( Motion::State::Jump, Motion::State::Wait, [this]() { return IsStanding(); } );
            // 待機->弱攻撃
            motion.Register( Motion::State::Wait, Motion::State::NeutralAttack, [this]() { return inputManager.lock()->IsKeyPushed( KEY_INPUT_P ); } );
            // 弱攻撃->待機
            motion.Register( Motion::State::NeutralAttack, Motion::State::Wait, [this]() { return isFinishMotion == true; } );
            // 待機->強攻撃
            motion.Register( Motion::State::Wait, Motion::State::StrongAttack, [this]() { return inputManager.lock()->IsKeyPushed( KEY_INPUT_L ); } );
            // 強攻撃->待機
            motion.Register( Motion::State::StrongAttack, Motion::State::Wait, [this]() { return isFinishMotion == true; } );
            //// 待機->振り向き
            //motion.Register( Motion::State::Wait, Motion::State::Turn, [this]() { return isTurn == true; } );
            //// 振り向き->待機
            //motion.Register( Motion::State::Turn, Motion::State::Wait, [this]() { return isFinishMotion == true; } );
            // 移動->弱攻撃
            motion.Register( Motion::State::Run, Motion::State::NeutralAttack, [this]() { return inputManager.lock()->IsKeyPushed( KEY_INPUT_P ); } );
            // 移動->強攻撃
            motion.Register( Motion::State::Run, Motion::State::StrongAttack, [this]() { return inputManager.lock()->IsKeyPushed( KEY_INPUT_L ); } );
            // 移動->ジャンプ
            motion.Register( Motion::State::Run, Motion::State::Jump, [this]() { return inputManager.lock()->IsKeyPushed( KEY_INPUT_W ); } );
            // 移動->ガード
            motion.Register( Motion::State::Run, Motion::State::Guard, [this]() { return inputManager.lock()->IsKeyPushed( KEY_INPUT_S ); } );
            //// 移動->振り向き
            //motion.Register( Motion::State::Run, Motion::State::Turn, [this]() { return isTurn == true; } );
            // ジャンプ->2段ジャンプ
            motion.Register( Motion::State::Jump, Motion::State::DoubleJump, [this]() { return inputManager.lock()->IsKeyPushed( KEY_INPUT_W ); } );
            // ジャンプ->空中弱攻撃
            motion.Register( Motion::State::Jump, Motion::State::AerialNeutralAttack, [this]() { return inputManager.lock()->IsKeyPushed( KEY_INPUT_P ); } );
            // ジャンプ->空中強攻撃
            motion.Register( Motion::State::Jump, Motion::State::AerialStrongAttack, [this]() { return inputManager.lock()->IsKeyPushed( KEY_INPUT_L ); } );
            // 2段ジャンプ->空中弱攻撃
            motion.Register( Motion::State::DoubleJump, Motion::State::AerialNeutralAttack, [this]() { return inputManager.lock()->IsKeyPushed( KEY_INPUT_P ); } );
            // 2段ジャンプ->空中強攻撃
            motion.Register( Motion::State::DoubleJump, Motion::State::AerialStrongAttack, [this]() { return inputManager.lock()->IsKeyPushed( KEY_INPUT_L ); } );
            // 2段ジャンプ->着地
            motion.Register( Motion::State::DoubleJump, Motion::State::Wait, [this]() { return IsStanding(); } );
            // ガード->弱攻撃
            motion.Register( Motion::State::Guard, Motion::State::NeutralAttack, [this]() { return inputManager.lock()->IsKeyPushed( KEY_INPUT_P ); } );
            // ガード->強攻撃
            motion.Register( Motion::State::Guard, Motion::State::StrongAttack, [this]() { return inputManager.lock()->IsKeyPushed( KEY_INPUT_L ); } );
            // ガード->ジャンプ
            motion.Register( Motion::State::Guard, Motion::State::Jump, [this]() { return inputManager.lock()->IsKeyPushed( KEY_INPUT_W ); } );
            // 落下->二段ジャンプ
            motion.Register( Motion::State::Fall, Motion::State::DoubleJump, [this]() { return inputManager.lock()->IsKeyPushed( KEY_INPUT_W ); } );
            // 落下->弱攻撃
            motion.Register( Motion::State::Fall, Motion::State::NeutralAttack, [this]() { return inputManager.lock()->IsKeyPushed( KEY_INPUT_J ); } );
            // 落下->強攻撃
            motion.Register( Motion::State::Fall, Motion::State::StrongAttack, [this]() { return inputManager.lock()->IsKeyPushed( KEY_INPUT_K ); } );
            //// 落下->ダウン
            //motion.Register( Motion::State::Fall, Motion::State::Run, [this]() { return inputManager.lock()->IsKeyPushed( KEY_INPUT_0 ); } );
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

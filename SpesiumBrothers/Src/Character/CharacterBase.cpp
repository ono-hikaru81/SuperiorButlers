
#include <Character/CharacterBase.h>
#include <DxLib.h>
#include <Utility/Function.h>

#include <cmath>

namespace spesium {
    namespace character {
        void CharacterBase::Exec() {
            Move();

            if ( IsStanding() ) {
                velocity.Y = 0.0f;
                status.canJumpNum = 2;

                KineticFriction();
            }
            else {
                Gravity();
            }

            Jump();

            UpdateDirection();

            PlayMotion();

            // 最後の座標処理
            UpdatePos();

            UpdateMotion();
        }

        void CharacterBase::LoadModel() {
            modelHandle = MV1LoadModel( modelName.c_str() );
        }

        void CharacterBase::ReleaseModel() {
            MV1DeleteModel( modelHandle );
        }

        void CharacterBase::Move() {
            const double reverseMaxSpeed = status.maxSpeed * -1;

            // 右移動
            if ( inputManager.lock()->IsKeyPushed( KEY_INPUT_D ) || inputManager.lock()->IsKeyHeld( KEY_INPUT_D ) ) {
                velocity.X += status.speed;

                DisabledExceed( status.maxSpeed, *velocity.X );
            }
            // 左移動
            else if ( inputManager.lock()->IsKeyPushed( KEY_INPUT_A ) || inputManager.lock()->IsKeyHeld( KEY_INPUT_A ) ) {
                velocity.X -= status.speed;

                DisabledBelow( reverseMaxSpeed, *velocity.X );
            }

            // 接触
            /*if ( inputManager.lock()->IsKeyPushed( KEY_INPUT_SPACE ) || inputManager.lock()->IsKeyHeld( KEY_INPUT_SPACE ) ) {
                isCollision = true;
            }
            else {
                isCollision = false;
            }*/

            BlowOffCalculation();
        }

        void CharacterBase::Jump() {
            if ( status.canJumpNum <= 0 || !inputManager.lock()->IsKeyPushed( KEY_INPUT_W ) ) { return; }
            velocity.Y = status.jumpPower;
            status.canJumpNum--;
        }

        void CharacterBase::UpdateDirection() {
            // 右向きに変更
            if ( velocity.X > 0 && ( !inputManager.lock()->IsKeyPushed( KEY_INPUT_D ) || !inputManager.lock()->IsKeyHeld( KEY_INPUT_D ) ) ) {
                angle = angleOfDirectionRight;
            }

            // 左向きに変更
            if ( velocity.X < 0 && ( !inputManager.lock()->IsKeyPushed( KEY_INPUT_A ) || !inputManager.lock()->IsKeyHeld( KEY_INPUT_A ) ) ) {
                angle = angleOfDirectionLeft;
            }
        }

        void CharacterBase::Gravity() {
            velocity.Y -= law::gravity;
        }

        bool CharacterBase::IsStanding() const {
            return ( pos.Y < 0 );
        }

        void CharacterBase::KineticFriction() {
            // 右移動
            if ( velocity.X > 0 && ( !inputManager.lock()->IsKeyPushed( KEY_INPUT_D ) || !inputManager.lock()->IsKeyHeld( KEY_INPUT_D ) ) ) {
                velocity.X -= friction::Force;

                DisabledBelow( 0.0, *velocity.X );
            }

            // 左移動
            if ( velocity.X < 0 && ( !inputManager.lock()->IsKeyPushed( KEY_INPUT_A ) || !inputManager.lock()->IsKeyHeld( KEY_INPUT_A ) ) ) {
                velocity.X += friction::Force;

                DisabledExceed( 0.0, *velocity.X );
            }
        }

        void CharacterBase::UpdatePos() {
            // X座標
            moveVec.X = velocity.X;
            pos.X += moveVec.X;

            // Y座標
            moveVec.Y = velocity.Y;
            pos.Y += moveVec.Y;
        }

        void CharacterBase::BlowOffCalculation() {
            if ( !isCollision ) { return; }

            static double initVelocity { 10.0 };  // 初速
            static double pi { 3.14 };  // 円周率
            static double degree { 60.0 };  // 角度
            static double radian { 30 * ( 3.14 / 180 ) };  // ラジアン角

            velocity.X = initVelocity * cosh( radian );
            velocity.Y = initVelocity * sinh( radian );
        }

        void CharacterBase::PlayMotion() {
            motionData.playFrame++;

            isFinishMotion = false;

            // 再生時間を0に戻す(モーションをループさせる)
            if ( motionData.playFrame >= motionData.totalFrame ) {
                motionData.playFrame = motionData.startFrame;
                isFinishMotion = true;
            }

            MV1SetAttachAnimTime( modelHandle, motionData.motionModelHandle, motionData.playFrame );

            DrawFormatString( 300, 0, GetColor( 0, 255, 0 ), "待機モーション再生時間(加算値)[%lf]", motionData.playFrame );
        }

        void CharacterBase::InitMotionList( MotionList motion_list_ ) {
            motionList.emplace( Motion::State::Wait, motion_list_.wait );
            motionList.emplace( Motion::State::Run, motion_list_.run );
            motionList.emplace( Motion::State::Jump, motion_list_.jump );
            motionList.emplace( Motion::State::DoubleJump, motion_list_.doubleJump );
            motionList.emplace( Motion::State::Guard, motion_list_.guard );
            motionList.emplace( Motion::State::NeutralAttack, motion_list_.neutralAttack );
            motionList.emplace( Motion::State::StrongAttack, motion_list_.strongAttack );
            motionList.emplace( Motion::State::AerialNeutralAttack, motion_list_.aerialNeutralAttack );
            motionList.emplace( Motion::State::AerialStrongAttack, motion_list_.aerialStrongAttack );
            motionList.emplace( Motion::State::FallLanding, motion_list_.fallLanding );
            motionList.emplace( Motion::State::SmallHitBack, motion_list_.smallHitBack );
            motionList.emplace( Motion::State::BigHitBack, motion_list_.bigHitBack );
            motionList.emplace( Motion::State::Fall, motion_list_.fall );
            motionList.emplace( Motion::State::Turn, motion_list_.turn );

            motionData = motion_list_.wait;
        }

        void CharacterBase::UpdateMotion() {
            if ( auto result { motion.Update() };
                 result != current ) {
                motionData = motionList.find( result )->second;
                motionData.playFrame = motionData.startFrame;
                current = result;
            }
        }
    }  // namespace character
}  // namespace spesium

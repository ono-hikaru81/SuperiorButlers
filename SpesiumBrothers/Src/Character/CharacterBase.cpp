﻿
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
            if ( inputManager.lock()->IsKeyPushed( KEY_INPUT_SPACE ) || inputManager.lock()->IsKeyHeld( KEY_INPUT_SPACE ) ) {
                isCollision = true;
            }
            else {
                isCollision = false;
            }

            BlowOffCalculation();
        }

        void CharacterBase::Jump() {
            if ( !inputManager.lock()->IsKeyPushed( KEY_INPUT_W ) ) { return; }

            if ( IsStanding() ) {
                velocity.Y = status.jumpPower;
            }
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

                angle = angleOfDirectionRight;

                DisabledBelow( 0.0, *velocity.X );
            }

            // 左移動
            if ( velocity.X < 0 && ( !inputManager.lock()->IsKeyPushed( KEY_INPUT_A ) || !inputManager.lock()->IsKeyHeld( KEY_INPUT_A ) ) ) {
                velocity.X += friction::Force;

                angle = angleOfDirectionLeft;

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
            motionData.playFrame += 1.0f;

            // 再生時間を0に戻す(モーションをループさせる)
            if ( motionData.playFrame >= motionData.totalFrame ) {
                motionData.playFrame = motionData.startFrame;
            }

            MV1SetAttachAnimTime( modelHandle, motionData.motionModelHandle, motionData.playFrame );

            DrawFormatString( 300, 0, GetColor( 0, 255, 0 ), "待機モーション再生時間(加算値)[%lf]", motionData.playFrame );
        }

        void CharacterBase::InitMotionList( MotionList motion_list_ ) {
            motionList.emplace( Motion::MotionState::WAIT, motion_list_.wait );
            motionList.emplace( Motion::MotionState::RUN, motion_list_.run );
            motionList.emplace( Motion::MotionState::JUMP, motion_list_.jump );
        }

        void CharacterBase::UpdateMotion() {
            if ( auto result { motion.Update() };
                 result != current ) {
                motionData = motionList.find( result )->second;
            }
        }
    }  // namespace character
}  // namespace spesium

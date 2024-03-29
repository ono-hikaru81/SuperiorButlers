﻿
#include <Character/CharacterBase.h>
#include <DxLib.h>
#include <Utility/Function.h>

namespace spesium {
    namespace character {
        CharacterBase::CharacterBase() {
            LoadModel();
        }

        CharacterBase::~CharacterBase() {
            ReleaseModel();
        }

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

            // 最後の座標処理
            UpdatePos();
        }

        void CharacterBase::LoadModel() {
            monsterModel = MV1LoadModel( monsterModelName.c_str() );
        }

        void CharacterBase::ReleaseModel() {
            MV1DeleteModel( monsterModel );
        }

        void CharacterBase::Move() {
            const double reverseMaxSpeed = status.maxSpeed * -1;

            // 右移動
            if ( inputManager.lock()->IsKeyPushed( KEY_INPUT_RIGHT ) || inputManager.lock()->IsKeyHeld( KEY_INPUT_RIGHT ) ) {
                velocity.X += status.speed;

                DisabledExceed( status.maxSpeed, *velocity.X );
            }

            // 左移動
            if ( inputManager.lock()->IsKeyPushed( KEY_INPUT_LEFT ) || inputManager.lock()->IsKeyHeld( KEY_INPUT_LEFT ) ) {
                velocity.X -= status.speed;

                DisabledBelow( reverseMaxSpeed, *velocity.X );
            }
        }

        void CharacterBase::Jump() {
            if ( !inputManager.lock()->IsKeyPushed( KEY_INPUT_UP ) ) { return; }

            if ( IsStanding() ) {
                velocity.Y = status.jumpPower;
            }
        }

        void CharacterBase::UpdateDirection() {
            // 右向きに変更
            if ( velocity.X > 0 && ( !inputManager.lock()->IsKeyPushed( KEY_INPUT_RIGHT ) || !inputManager.lock()->IsKeyHeld( KEY_INPUT_RIGHT ) ) ) {
                status.angle = angleOfDirectionRight;
            }

            // 左向きに変更
            if ( velocity.X < 0 && ( !inputManager.lock()->IsKeyPushed( KEY_INPUT_LEFT ) || !inputManager.lock()->IsKeyHeld( KEY_INPUT_LEFT ) ) ) {
                status.angle = angleOfDirectionLeft;
            }
        }

        void CharacterBase::Gravity() {
            velocity.Y -= law::gravity;
        }

        bool CharacterBase::IsStanding() const {
            return ( status.pos.Y < 0 );
        }

        void CharacterBase::KineticFriction() {
            // 右移動
            if ( velocity.X > 0 && ( !inputManager.lock()->IsKeyPushed( KEY_INPUT_RIGHT ) || !inputManager.lock()->IsKeyHeld( KEY_INPUT_RIGHT ) ) ) {
                velocity.X -= friction::Force;

                status.angle = angleOfDirectionRight;

                DisabledBelow( 0.0, *velocity.X );
            }

            // 左移動
            if ( velocity.X < 0 && ( !inputManager.lock()->IsKeyPushed( KEY_INPUT_LEFT ) || !inputManager.lock()->IsKeyHeld( KEY_INPUT_LEFT ) ) ) {
                velocity.X += friction::Force;

                status.angle = angleOfDirectionLeft;

                DisabledExceed( 0.0, *velocity.X );
            }
        }

        void CharacterBase::UpdatePos() {
            // X座標
            moveVec.X = velocity.X;
            status.pos.X += moveVec.X;

            // Y座標
            moveVec.Y = velocity.Y;
            status.pos.Y += moveVec.Y;
        }
    }  // namespace character
}  // namespace spesium

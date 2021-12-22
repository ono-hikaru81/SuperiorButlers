
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

            // 最後の座標処理
            UpdatePos();
        }

        void CharacterBase::LoadModel() {
            model = MV1LoadModel( modelName.c_str() );
        }

        void CharacterBase::ReleaseModel() {
            MV1DeleteModel( model );
        }

        void CharacterBase::Move() {
            const double reverseMaxSpeed = status.maxSpeed * -1;

            // 右移動
            if ( inputManager.lock()->IsKeyPushed( KEY_INPUT_D ) || inputManager.lock()->IsKeyHeld( KEY_INPUT_D ) ) {
                velocity.X += status.speed;

                DisabledExceed( status.maxSpeed, *velocity.X );

                currentMotion = KindMotion::RUN;
            }
            // 左移動
            else if ( inputManager.lock()->IsKeyPushed( KEY_INPUT_A ) || inputManager.lock()->IsKeyHeld( KEY_INPUT_A ) ) {
                velocity.X -= status.speed;

                DisabledBelow( reverseMaxSpeed, *velocity.X );

                currentMotion = KindMotion::RUN;
            }
            else {
                currentMotion = KindMotion::WAIT;
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

            currentMotion = KindMotion::BIG_HITBACK;
        }

        void CharacterBase::SwitchMotion() {
            switch ( currentMotion ) {
                case KindMotion::WAIT: WaitMotion(); break;
                case KindMotion::RUN: DashMotion(); break;
                case KindMotion::JUMP: JumpMotion(); break;
                case KindMotion::DOUBLE_JUMP: DoubleJumpMotion(); break;
                case KindMotion::GUARD: GuardMotion(); break;
                case KindMotion::NEUTRAL_ATTACK: NeutralAttackMotion(); break;
                case KindMotion::STRONG_ATTACK: StrongAttackMotion(); break;
                case KindMotion::AERIAL_NEUTRAL_ATTACK: AerialNeutralAttackMotion(); break;
                case KindMotion::AERIAL_STRONG_ATTACK: AerialStrongAttackMotion(); break;
                case KindMotion::FAll_LANDING: FallLandingMotion(); break;
                case KindMotion::SMALL_HITBACK: SmallHitBackMotion(); break;
                case KindMotion::BIG_HITBACK: BigHitBackMotion(); break;
                case KindMotion::FALL: FallMotion(); break;
                case KindMotion::TURN: TurnMotion(); break;
            }

            /*if () {
            }
            else {
                currentMotion = KindMotion::WAIT;
            }*/

            DrawFormatString( 300, 100, GetColor( 0, 255, 0 ), "%d\n", currentMotion );
        }
    }  // namespace character
}  // namespace spesium

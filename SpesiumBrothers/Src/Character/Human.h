
#ifndef HUMAN_H
#define HUMAN_H

#include <Character/CharacterBase.h>

namespace spesium {
    namespace character {
        class Human : public CharacterBase {
           public:
            Human();
            ~Human() override;

           public:
            void Draw() override;

           private:
            /// @breif 待機モーション
            void WaitMotion() override;

            /// @breif ダッシュモーション
            void DashMotion() override;

            /// @breif ジャンプモーション
            void JumpMotion() override;

            /// @breif 2段ジャンプモーション
            void TwoStepJumpMotion() override;

            /// @breif ガードモーション
            void GuardMotion() override;

            /// @breif 弱攻撃モーション
            void NeutralAttackMotion() override;

            /// @breif 強攻撃モーション
            void StrongAttackMotion() override;

            /// @breif 空中弱攻撃モーション
            void AerialNeutralAttackMotion() override;

            /// @breif 空中強攻撃モーション
            void AerialStrongAttackMotion() override;

            /// @breif 着地モーション
            void LandingMotion() override;

            /// @breif ヒットバックモーション小
            void SmallHitBackMotion() override;

            /// @breif ヒットバックモーション大
            void BigHitBackMotion() override;

            /// @breif 落下モーション
            void FallMotion() override;

            /// @brief 振り向きモーション
            void TurnMotion() override;

           public:
            /// @brief アクセサ
            /// @param (status.pos) 座標
            BasicProperty<Vector3<double>> Pos { status.pos };
        };
    }  // namespace character
}  // namespace spesium

#endif

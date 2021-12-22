
#ifndef MONSTER_H
#define MONSTER_H

#include <Character/CharacterBase.h>

namespace spesium {
    namespace character {
        class Monster : public CharacterBase {
           public:
            Monster();
            ~Monster() override;

           private:
            /// @breif モーション開始フレーム
            struct InitMotionTime {
                static constexpr float wait { 0.0f };  // 待機
                static constexpr float run { 121.0f };  // 移動
                static constexpr float jump { 169.0f };  // ジャンプ
                static constexpr float doubleJump { 240.0f };  // 2段ジャンプ
                static constexpr float guard { 299.0f };  // ガード
                static constexpr float neutralAttack { 306.0f };  // 弱攻撃
                static constexpr float strongAttack { 332.0f };  // 強攻撃
                static constexpr float aerialNeutralAttack { 364.0f };  // 空中弱攻撃
                static constexpr float aerialStrongAttack { 395.0f };  // 空中強攻撃
                static constexpr float fallLanding { 434.0f };  // 落下着地
                static constexpr float smallHitBack { 468.0f };  // ノックバック小
                static constexpr float bigHitBack { 473.0f };  // ノックバック大
                static constexpr float fall { 516.0f };  //　落下
                static constexpr float turn { 563.0f };  // 振りむき
            };

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
            void DoubleJumpMotion() override;

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
            void FallLandingMotion() override;

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
            BasicProperty<Vector3<double>> Pos { pos };
        };
    }  // namespace character
}  // namespace spesium

#endif  // !MONSTER_H

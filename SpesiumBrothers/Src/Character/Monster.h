
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
            /// @brief モーションフレーム
            struct MotionFrame {
                float start { 0.0f };  // 開始フレーム
                float total { 0.0f };  // 総フレーム
            };

            /// @breif 各モーションのリスト
            struct MotionDataList {
                static constexpr MotionFrame wait { .start { 0.0f }, .total { 120.0f } };  // 待機
                static constexpr MotionFrame run { .start { 121.0f }, .total { 168.0f } };  // 移動
                static constexpr MotionFrame jump { .start { 169.0f }, .total { 239.0f } };  // ジャンプ
                static constexpr MotionFrame doubleJump { .start { 240.0f }, .total { 298.0f } };  // 2段ジャンプ
                static constexpr MotionFrame guard { .start { 299.0f }, .total { 305.0f } };  // ガード
                static constexpr MotionFrame neutralAttack { .start { 306.0f }, .total { 331.0f } };  // 弱攻撃
                static constexpr MotionFrame strongAttack { .start { 332.0f }, .total { 363.0f } };  // 強攻撃
                static constexpr MotionFrame aerialNeutralAttack { .start { 364.0f }, .total { 394.0f } };  // 空中弱攻撃
                static constexpr MotionFrame aerialStrongAttack { .start { 395.0f }, .total { 433.0f } };  // 空中強攻撃
                static constexpr MotionFrame fallLanding { .start { 434.0f }, .total { 467.0f } };  // 落下着地
                static constexpr MotionFrame smallHitBack { .start { 468.0f }, .total { 472.0 } };  // ノックバック小
                static constexpr MotionFrame bigHitBack { .start { 473.0f }, .total { 515.0f } };  // ノックバック大
                static constexpr MotionFrame fall { .start { 516.0f }, .total { 562.0f } };  //　落下
                static constexpr MotionFrame turn { .start { 563.0f }, .total { 568.0f } };  // 振りむき
            };

           public:
            void Draw() override;

           public:
            /// @brief アクセサ
            /// @param (status.pos) 座標
            BasicProperty<Vector3<double>> Pos { pos };
        };
    }  // namespace character
}  // namespace spesium

#endif  // !MONSTER_H

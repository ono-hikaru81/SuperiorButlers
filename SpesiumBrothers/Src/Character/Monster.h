
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
            /// @breif 各モーションのリスト
            struct MotionDataList {
                static constexpr DefaultMotionFrame wait { .start { 0.0f }, .total { 120.0f } };  // 待機
                static constexpr DefaultMotionFrame run { .start { 121.0f }, .total { 168.0f } };  // 移動
                static constexpr DefaultMotionFrame jump { .start { 169.0f }, .total { 239.0f } };  // ジャンプ
                static constexpr DefaultMotionFrame doubleJump { .start { 240.0f }, .total { 298.0f } };  // 2段ジャンプ
                static constexpr DefaultMotionFrame guard { .start { 299.0f }, .total { 305.0f } };  // ガード
                static constexpr DefaultMotionFrame neutralAttack { .start { 306.0f }, .total { 331.0f } };  // 弱攻撃
                static constexpr DefaultMotionFrame strongAttack { .start { 332.0f }, .total { 363.0f } };  // 強攻撃
                static constexpr DefaultMotionFrame aerialNeutralAttack { .start { 364.0f }, .total { 394.0f } };  // 空中弱攻撃
                static constexpr DefaultMotionFrame aerialStrongAttack { .start { 395.0f }, .total { 433.0f } };  // 空中強攻撃
                static constexpr DefaultMotionFrame fallLanding { .start { 434.0f }, .total { 467.0f } };  // 落下着地
                static constexpr DefaultMotionFrame smallHitBack { .start { 468.0f }, .total { 472.0 } };  // ノックバック小
                static constexpr DefaultMotionFrame bigHitBack { .start { 473.0f }, .total { 515.0f } };  // ノックバック大
                static constexpr DefaultMotionFrame fall { .start { 516.0f }, .total { 562.0f } };  //　落下
                static constexpr DefaultMotionFrame turn { .start { 563.0f }, .total { 568.0f } };  // 振りむき
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


#ifndef HUMAN_H
#define HUMAN_H

#include <Character/CharacterBase.h>

namespace spesium {
    namespace character {
        class Human : public CharacterBase {
           public:
            Human();
            ~Human() override;

           private:
            /// @breif 各モーションのリスト
            struct MotionDataList {
                static constexpr DefaultMotionFrame wait { .start { 0.0f }, .total { 120.0f } };  // 待機
                static constexpr DefaultMotionFrame run { .start { 121.0f }, .total { 168.0f } };  // 移動
                static constexpr DefaultMotionFrame jump { .start { 169.0f }, .total { 239.0f } };  // ジャンプ
                static constexpr DefaultMotionFrame doubleJump { .start { 240.0f }, .total { 298.0f } };  // 2段ジャンプ
                static constexpr DefaultMotionFrame guard { .start { 299.0f }, .total { 305.0f } };  // ガード
                static constexpr DefaultMotionFrame neutralAttack { .start { 306.0f }, .total { 317.0f } };  // 弱攻撃
                static constexpr DefaultMotionFrame strongAttack { .start { 318.0f }, .total { 339.0f } };  // 強攻撃
                static constexpr DefaultMotionFrame aerialNeutralAttack { .start { 340.0f }, .total { 357.0f } };  // 空中弱攻撃
                static constexpr DefaultMotionFrame aerialStrongAttack { .start { 358.0f }, .total { 386.0f } };  // 空中強攻撃
                static constexpr DefaultMotionFrame fallLanding { .start { 387.0f }, .total { 420.0f } };  // 落下着地
                static constexpr DefaultMotionFrame smallHitBack { .start { 421.0f }, .total { 425.0 } };  // ノックバック小
                static constexpr DefaultMotionFrame bigHitBack { .start { 426.0f }, .total { 468.0f } };  // ノックバック大
                static constexpr DefaultMotionFrame fall { .start { 469.0f }, .total { 515.0f } };  //　落下
                static constexpr DefaultMotionFrame turn { .start { 516.0f }, .total { 521.0f } };  // 振りむき
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

#endif

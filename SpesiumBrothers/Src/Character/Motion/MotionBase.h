
#ifndef MOTION_BASE_H
#define MOTION_BASE_H

namespace spesium {
    namespace character {

        class CharacterBase;

        class MotionBase {
           public:
            MotionBase() = default;
            ~MotionBase() = default;

            virtual void Init( CharacterBase* character_ ) = 0;
            virtual void Update( CharacterBase* character_ ) = 0;
        };
    }  // namespace character
}  // namespace spesium

#endif  // !MOTION_NODE_H

/*
    /// @breif モーションの種類
    enum class KindMotion {
        WAIT,  // 待機
        RUN,  // 移動
        JUMP,  // ジャンプ
        DOUBLE_JUMP,  // 2段ジャンプ
        GUARD,  // ガード
        NEUTRAL_ATTACK,  // 弱攻撃
        STRONG_ATTACK,  // 強攻撃
        AERIAL_NEUTRAL_ATTACK,  // 空中弱攻撃
        AERIAL_STRONG_ATTACK,  // 空中強攻撃
        FALL_LANDING,  // 落下着地
        SMALL_HITBACK,  // ノックバック小
        BIG_HITBACK,  // ノックバック大
        FALL,  //　落下
        TURN,  // 振りむき
    };

*/

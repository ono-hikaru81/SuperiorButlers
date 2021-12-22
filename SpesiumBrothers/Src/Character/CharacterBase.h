
#ifndef CHARACTER_BASE_H
#define CHARACTER_BASE_H

#include <Definition/Definition.h>
#include <Manager/InputManager.h>

#include <Utility/Vector.hpp>
#include <memory>

namespace spesium {
    namespace character {
        class CharacterBase {
           public:
            CharacterBase() = default;
            virtual ~CharacterBase() = default;

           protected:
            /// @brief キャラのステータス
            struct Status {
                int32_t hp { 0 };  // 体力
                int32_t shieldAmount { 0 };  // シールド量
                int32_t power { 0 };  // 攻撃力
                double speed { 0.0 };  // 移動速度
                double maxSpeed { 0.0 };  // 最大移動速度
                double jumpPower { 0.0 };  // ジャンプ力
                int32_t canJumpNum { 0 };  // ジャンプできる回数
            };

            /// @brief モーションモデル
            struct MotionModel {
                int32_t wait;  // 待機
                int32_t run;  // 移動
                int32_t jump;  // ジャンプ
                int32_t doubleJump;  // 2段ジャンプ
                int32_t guard;  // ガード
                int32_t neutralAttack;  // 弱攻撃
                int32_t strongAttack;  // 強攻撃
                int32_t aerialNeutralAttack;  // 空中弱攻撃
                int32_t aerialStrongAttack;  // 空中強攻撃
                int32_t fallLanding;  // 落下着地
                int32_t smallHitBack;  // ノックバック小
                int32_t bigHitBack;  // ノックバック大
                int32_t fall;  //　落下
                int32_t turn;  // 振りむき
            };

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
                FAll_LANDING,  // 落下着地
                SMALL_HITBACK,  // ノックバック小
                BIG_HITBACK,  // ノックバック大
                FALL,  //　落下
                TURN,  // 振りむき
            };

            /// @brief モーションの開始時間
            struct MotionStartTime {
                float wait;  // 待機
                float run;  // 移動
                float jump;  // ジャンプ
                float doubleJump;  // 2段ジャンプ
                float guard;  // ガード
                float neutralAttack;  // 弱攻撃
                float strongAttack;  // 強攻撃
                float aerialNeutralAttack;  // 空中弱攻撃
                float aerialStrongAttack;  // 空中強攻撃
                float fallLanding;  // 落下着地
                float smallHitBack;  // ノックバック小
                float bigHitBack;  // ノックバック大
                float fall;  //　落下
                float turn;  // 振りむき
            };

            /// @brief モーションの再生時間
            struct MotionPlayTime {
                float wait;  // 待機
                float run;  // 移動
                float jump;  // ジャンプ
                float doubleJump;  // 2段ジャンプ
                float guard;  // ガード
                float neutralAttack;  // 弱攻撃
                float strongAttack;  // 強攻撃
                float aerialNeutralAttack;  // 空中弱攻撃
                float aerialStrongAttack;  // 空中強攻撃
                float fallLanding;  // 落下着地
                float smallHitBack;  // ノックバック小
                float bigHitBack;  // ノックバック大
                float fall;  //　落下
                float turn;  // 振りむき
            };

            /// @brief モーションの総時間
            struct MotionTotalTime {
                float wait;  // 待機
                float run;  // 移動
                float jump;  // ジャンプ
                float doubleJump;  // 2段ジャンプ
                float guard;  // ガード
                float neutralAttack;  // 弱攻撃
                float strongAttack;  // 強攻撃
                float aerialNeutralAttack;  // 空中弱攻撃
                float aerialStrongAttack;  // 空中強攻撃
                float fallLanding;  // 落下着地
                float smallHitBack;  // ノックバック小
                float bigHitBack;  // ノックバック大
                float fall;  //　落下
                float turn;  // 振りむき
            };

           public:
            /// @brief 実行関数
            virtual void Exec();

            /// @brief 描画関数
            virtual void Draw() = 0;

           protected:
            /// @brief モデル読み込み関数
            virtual void LoadModel();

            /// @brief モデル解放関数
            virtual void ReleaseModel();

            /// @brief 移動関数
            void Move();

            /// @brief ジャンプ関数
            void Jump();

            /// @brief 向き変更
            void UpdateDirection();

            /// @brief 重力関数
            void Gravity();

            /// @brief 立ってるかチェック
            bool IsStanding() const;

            /// @brief 運動摩擦関数
            void KineticFriction();

            /// @brief 座標更新関数
            void UpdatePos();

            /// @breif 吹っ飛びの計算
            void BlowOffCalculation();

           protected:
            /// @breif 待機モーション
            virtual void WaitMotion() = 0;

            /// @breif ダッシュモーション
            virtual void DashMotion() = 0;

            /// @breif ジャンプモーション
            virtual void JumpMotion() = 0;

            /// @breif 2段ジャンプモーション
            virtual void DoubleJumpMotion() = 0;

            /// @breif ガードモーション
            virtual void GuardMotion() = 0;

            /// @breif 弱攻撃モーション
            virtual void NeutralAttackMotion() = 0;

            /// @breif 強攻撃モーション
            virtual void StrongAttackMotion() = 0;

            /// @breif 空中弱攻撃モーション
            virtual void AerialNeutralAttackMotion() = 0;

            /// @breif 空中強攻撃モーション
            virtual void AerialStrongAttackMotion() = 0;

            /// @breif 着地モーション
            virtual void FallLandingMotion() = 0;

            /// @breif ヒットバックモーション小
            virtual void SmallHitBackMotion() = 0;

            /// @breif ヒットバックモーション大
            virtual void BigHitBackMotion() = 0;

            /// @breif 落下モーション
            virtual void FallMotion() = 0;

            /// @brief 振り向きモーション
            virtual void TurnMotion() = 0;

            /// @breif モーション切り替え
            void SwitchMotion();

           protected:
            /// @brief キーボード入力
            std::weak_ptr<input::InputManager> inputManager = input::InputManager::Instance();

           protected:
            /// @brief ステータス
            Status status { 0 };

            /// @breif 座標
            Vector3<double> pos { 0.0, 0.0, 0.0 };
            /// @brief 回転角
            double angle { 0.0 };
            /// @breif 左向きの角度
            static constexpr double angleOfDirectionLeft { 90.0 };
            /// @breif 右向きの角度
            static constexpr double angleOfDirectionRight { 270.0 };

            /// @brief 移動量
            Vector3<double> moveVec { 0.0, 0.0, 0.0 };
            /// @brief 移動速度量
            Vector3<double> velocity { 0.0, 0.0, 0.0 };

            /// @brief 生存フラグ
            bool isAlive { false };
            /// @brief ジャンプ可能か
            bool canJump { false };
            /// @ brief 地面に立ってるか
            bool isStandingGround { false };
            /// @brief ダウンしたか(倒れたか)
            bool isKnockdown { false };
            /// @brief 接触したか
            bool isCollision { false };

            /// @brief モデル格納用
            int32_t model { 0 };
            /// @breif モデル名
            std::string modelName {};
            /// @brief モーションモデル
            MotionModel motionModel { 0 };
            /// @breif モーションの開始時間
            MotionStartTime motionStartTime { 0.0f };
            /// @brief モーションの再生時間
            MotionPlayTime motionPlayTime { 0.0f };
            /// @brief モーションの総再生時間
            MotionTotalTime motionTotalTime { 0.0f };

            /// 現在のモーション
            KindMotion currentMotion { KindMotion::WAIT };
        };
    }  // namespace character
}  // namespace spesium

#endif  // !CHARACTER_BASE_H

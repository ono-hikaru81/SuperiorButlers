
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
                int32_t wait { 0 };
                int32_t dash { 0 };
                int32_t jump { 0 };
                int32_t twoStepJump { 0 };
                int32_t guard { 0 };
                int32_t neutralAttack { 0 };
                int32_t strongAttack { 0 };
                int32_t aerialNeutralAttack { 0 };
                int32_t aerialStrongAttack { 0 };
                int32_t landing { 0 };
                int32_t smallHitBackMotion { 0 };
                int32_t bigHitBackMotion { 0 };
                int32_t fall { 0 };
                int32_t turn { 0 };
            };

            /// @brief モーションモデルのファイルネーム
            struct MotionModelName {
                std::string wait { 0 };
                std::string dash { 0 };
                std::string jump { 0 };
                std::string twoStepJump { 0 };
                std::string guard { 0 };
                std::string neutralAttack { 0 };
                std::string strongAttack { 0 };
                std::string aerialNeutralAttack { 0 };
                std::string aerialStrongAttack { 0 };
                std::string landing { 0 };
                std::string smallHitBackMotion { 0 };
                std::string bigHitBackMotion { 0 };
                std::string fall { 0 };
                std::string turn { 0 };
            };

            /// @brief モーションの再生時間
            struct PlayMotionTime {
                double wait { 0 };
                double dash { 0 };
                double jump { 0 };
                double twoStepJump { 0 };
                double guard { 0 };
                double neutralAttack { 0 };
                double strongAttack { 0 };
                double aerialNeutralAttack { 0 };
                double aerialStrongAttack { 0 };
                double landing { 0 };
                double smallHitBackMotion { 0 };
                double bigHitBackMotion { 0 };
                double fall { 0 };
                double turn { 0 };
            };

            /// @brief モーションの総再生時間
            struct PlayTotalMotionTime {
                double wait { 0 };
                double dash { 0 };
                double jump { 0 };
                double twoStepJump { 0 };
                double guard { 0 };
                double neutralAttack { 0 };
                double strongAttack { 0 };
                double aerialNeutralAttack { 0 };
                double aerialStrongAttack { 0 };
                double landing { 0 };
                double smallHitBackMotion { 0 };
                double bigHitBackMotion { 0 };
                double fall { 0 };
                double turn { 0 };
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
            virtual void TwoStepJumpMotion() = 0;

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
            virtual void LandingMotion() = 0;

            /// @breif ヒットバックモーション小
            virtual void SmallHitBackMotion() = 0;

            /// @breif ヒットバックモーション大
            virtual void BigHitBackMotion() = 0;

            /// @breif 落下モーション
            virtual void FallMotion() = 0;

            /// @brief 振り向きモーション
            virtual void TurnMotion() = 0;

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
            /// @brief モーションモデルのファイルネーム
            MotionModelName motionModelName { "Res/" };
            /// @brief モーションの再生時間
            PlayMotionTime playMotionTime { 0 };
            /// @brief モーションの総再生時間
            PlayTotalMotionTime playTotalMotionTime { 0 };

            int32_t count = 0;
        };
    }  // namespace character
}  // namespace spesium

#endif  // !CHARACTER_BASE_H

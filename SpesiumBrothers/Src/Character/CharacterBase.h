
#ifndef CHARACTER_BASE_H
#define CHARACTER_BASE_H

#include <Character/Motion/Motion.h>
#include <Definition/Definition.h>
#include <Manager/InputManager.h>

#include <Utility/Property.hpp>
#include <Utility/Vector.hpp>
#include <functional>
#include <map>
#include <memory>

namespace spesium {
    namespace character {
        class CharacterBase {
           public:
            CharacterBase() = default;
            virtual ~CharacterBase() = default;

           public:
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

            /// @brief モーション再生に必要なデータ
            struct MotionData {
                int32_t motionModelHandle { 0 };  // モーションモデルハンドル
                float startFrame { 0.0f };  // 開始フレーム
                float playFrame { 0.0f };  // 再生中フレーム
                float totalFrame { 0.0f };  // 総フレーム
            };

            /// @brief 各モーションのリスト
            struct MotionList {
                MotionData wait;  // 待機
                MotionData run;  // 移動
                MotionData jump;  // ジャンプ
                MotionData doubleJump;  // 2段ジャンプ
                MotionData guard;  // ガード
                MotionData neutralAttack;  // 弱攻撃
                MotionData strongAttack;  // 強攻撃
                MotionData aerialNeutralAttack;  // 空中弱攻撃
                MotionData aerialStrongAttack;  // 空中強攻撃
                MotionData fallLanding;  // 落下着地
                MotionData smallHitBack;  // ノックバック小
                MotionData bigHitBack;  // ノックバック大
                MotionData fall;  //　落下
                MotionData turn;  // 振りむき
            };

            std::map<Motion::State, MotionData> motionList {};

           public:
            /// @brief 実行関数
            virtual void Exec();

            /// @brief 描画関数
            virtual void Draw() = 0;

           public:
            double GetMoveVecX() { return moveVec.X; }
            bool GetIsStanding() { return IsStanding(); }

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

           public:
            /// @breif モーション再生
            void PlayMotion();
            /// @breif モーション初期化
            void InitMotionList( MotionList motion_list_ );
            /// @breif
            void UpdateMotion();

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

           protected:
            /// @brief モデルハンドル
            int32_t modelHandle { 0 };
            /// @breif モデル名
            std::string modelName {};
            /// @breif モーションデータ
            MotionData motionData {};

            //
            Motion motion;

            //
            Motion::State current;
        };
    }  // namespace character
}  // namespace spesium

#endif  // !CHARACTER_BASE_H

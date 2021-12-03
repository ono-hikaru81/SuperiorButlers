
#ifndef CHARACTER_BASE_H
#define CHARACTER_BASE_H

#include <Definition/Definition.h>
#include <Manager/InputManager.h>

#include <Utility/Vector.hpp>
#include <memory>
#include <vector>

namespace spesium {
    namespace character {
        class CharacterBase {
           public:
            CharacterBase();
            virtual ~CharacterBase();

           protected:
            /// @brief キャラのステータス
            struct Status {
                Vector3<double> pos { 0.0, 0.0, 0.0 };  // キャラ座標
                double angle { 0.0 };  // 回転角

                int32_t hp { 0 };  // 体力
                int32_t shieldAmount { 0 };  // シールド量
                int32_t power { 0 };  // 攻撃力
                double speed { 0.0 };  // 移動速度
                double maxSpeed { 0.0 };  // 最大移動速度
                double jumpPower { 0.0 };  // ジャンプ力
            };

           public:
            struct FrameData {
                const uint32_t number {};
                const double radius {};
                const int32_t damage {};

                Vector3<double> position {};
                bool attacking { false };
            };

            /**
   * @brief 実行関数
   */
            virtual void Exec();

            /**
   * @brief 描画関数
   */
            virtual void Draw() = 0;

            virtual void OnCollision() = 0;

            virtual void TakeDamage( const int32_t& damage_ ) = 0;

           protected:
            /**
   * @brief モデル読み込み関数
   */
            void LoadModel( const std::string& file_path_ );

            /**
   * @brief モデル解放関数
   */
            void ReleaseModel();

            /**
   * @brief 移動関数
   */
            void Move();

            /**
   * @brief ジャンプ関数
   */
            void Jump();

            void Attack();

            /*
   * @brief 向き変更
   */
            void UpdateDirection();

            /*
   * @brief 重力関数
   */
            void Gravity();

            /*
   * @brief 立ってるかチェック
   */
            bool IsStanding() const;

            /**
   * @brief 運動摩擦関数
   */
            void KineticFriction();

            /*
   * @brief 座標更新関数
   */
            void UpdatePos();

            void UpdateCollisionData() & noexcept;

           protected:
            /// @brief キーボード入力
            std::weak_ptr<input::InputManager> inputManager = input::InputManager::Instance();

           public:
            /// @brief 位置
            BasicProperty<Vector3<double>> Pos { status.pos };

            ReadonlyProperty<std::vector<FrameData>> FrameDataList { frameDataList };

           protected:
            /// @brief ステータス
            Status status {};

            /// @breif 左向きの角度
            static constexpr double angleOfDirectionLeft { 90.0 };
            /// @breif 右向きの角度
            static constexpr double angleOfDirectionRight { 270.0 };

            /// @brief 移動量
            Vector3<double> moveVec {};
            /// @brief 移動速度量
            Vector3<double> velocity {};

            /// @brief 生存フラグ
            bool isAlive { false };
            /// @brief ジャンプ可能か
            bool canJump { false };
            /// @ brief 地面に立ってるか
            bool isStandingGround { false };
            /// @brief ダウンしたか(倒れたか)
            bool isKnockdown { false };

            /// @brief モデルのハンドル
            int32_t modelHandle {};

            std::vector<FrameData> frameDataList {};

            int32_t attackingParts {};
        };
    }  // namespace character
}  // namespace spesium

#endif  // !CHARACTER_BASE_H

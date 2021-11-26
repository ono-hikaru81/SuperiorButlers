
#ifndef INPUT_CONTROLLER_MANAGER_H
#define INPUT_CONTROLLER_MANAGER_H

#include <DxLib.h>
#include <Manager/InputState.h>
#include <Utility/Singleton.h>

#include <Utility/Vector.hpp>
#include <array>

namespace spesium {
    namespace input {
        class InputControllerManager : public Singleton<InputControllerManager> {
           public:
            InputControllerManager();
            ~InputControllerManager() {}

           public:
            ///@brief コントローラーの更新
            ///@note ループ一回につき一度だけ呼び出す
            void UpdateControllerStatus();

            ///@brief ジョイパッドキーの押下した瞬間
            ///@param Key ジョイパッドの指定キー
            ///@note Dxlib.hのXINPUTの定義参照
            bool IsPadKeyPushed( const int32_t& Key );

            ///@brief ジョイパッドキーの押されている
            ///@param Key ジョイパッドの指定キー
            ///@note XINPUTの定義参照
            bool IsPadKeyHold( const int32_t& Key );

            ///@brief ジョイパッドキーの離した
            ///@param Key ジョイパッドの指定キー
            ///@note XINPUTの定義参照
            bool IsPadKeyReleased( const int32_t& Key );

            ///@brief 左スティックの値
            ///@return -32767～32767
            ReadonlyProperty<Vector2<double>> LeftStick { leftStick };

            ///@brief 右スティックの値
            ///@return -32767～32767
            ReadonlyProperty<Vector2<double>> RightStick { rightStick };

            ///@brief 左トリガーの値(LT)
            ///@return 0～255
            const uint8_t& LeftTrigger() { return leftTrigger; }

            ///@brief //右トリガーの値(RT)
            ///@return 0～255
            const uint8_t& RightTrigger() { return rightTrigger; }

           private:
            /// @brief コントローラーの接続数
            void FindPadNum();

           private:
            static constexpr int32_t MAX_PAD_KEY { 16 };

            XINPUT_STATE inputXbox {};
            int32_t padNum {};

            std::array<bool, MAX_PAD_KEY> previousButtonList {};
            std::array<InputState, MAX_PAD_KEY> buttonStateList {};
            Vector2<double> leftStick {};
            Vector2<double> rightStick {};

            uint8_t leftTrigger {};
            uint8_t rightTrigger {};
        };
    }  // namespace input
}  // namespace spesium

#endif  // !INPUT_CONTROLLER_MANAGER_H

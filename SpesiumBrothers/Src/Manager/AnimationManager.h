#ifndef ANIMATION_MANAGER_H
#define ANIMATION_MANAGER_H

#include <Definition/Definition.h>
#include <DxLib.h>
#include <Utility/Singleton.h>

#include <map>
#include <string>
#include <vector>

namespace spesium {
    /// 拡張子
    static constexpr char PNG[] { ".png" };
    /// 拡張子
    static constexpr char JPEG[] { ".jpg" };

    /// アニメーション管理クラス
    class AnimationManager : public Singleton<AnimationManager> {
       private:
        /// アニメーション保存
        struct Data {
            /// GetAnimationTextureが呼び出された回数をカウント
            uint32_t frameCount { 0 };
            /// テクスチャが切り替わる時間
            uint16_t switchTime { 0 };
            /// テクスチャ枚数
            uint8_t textureNum { 0 };
            /// テクスチャハンドルを保存
            std::vector<int32_t> textureList {};

            /// @brief テクスチャの解放
            void ReleaseTextures() const {
                for ( auto&& texture : std::as_const( textureList ) ) {
                    DeleteGraph( texture );
                }
            }
        };

       public:
        AnimationManager() = default;
        virtual ~AnimationManager() = default;

        /**
        * @brief アニメーションさせるテクスチャの読み込み
        * @param name_ アニメーションの名前
        * @param file_name_ 数字.pngを除いたテクスチャを保存しているファイルパス
        * @param texture_num_ テクスチャの枚数
        * @param switch_time_ 切り替わる時間
        * @param file_type_ 拡張子(PNGかJPEG)
        * @param 指定枚数読み込めたらtrue
        * @note 読み込める枚数は1～255まで
        */
        bool LoadAnimation( const std::string& name_, const std::string& file_name_, const uint8_t& texture_num_, const uint8_t& switch_time_ = 0, const std::string& file_type_ = PNG );

        /**
        * @brief テクスチャの取得
        * @param name_ アニメーションの名前
        * @return テクスチャハンドル
        */
        int32_t GetAnimationTexture( const std::string& name_ );

        /**
        * @brief テクスチャの取得
        * @param name_ アニメーションの名前
        * @param texture_num_ 取得したいテクスチャの番目
        */
        int32_t GetAnimationTexture( const std::string& name_, const uint8_t& texture_num_ );

        /**
        * @brief アニメーションを1枚目にする
        * @param name_ アニメーションの名前
        */
        void ResetAnimation( const std::string& name_ );

        /*
        * @breif テクスチャの全削除
        */
        void ReleaseAnimation();

       private:
        /// アニメーションデータ保存
        std::map<std::string, Data> AnimationList {};
    };
}  // namespace spesium
#endif  // !ANIMATION_MANAGER_H

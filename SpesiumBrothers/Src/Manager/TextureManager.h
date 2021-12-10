
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <Definition/Definition.h>
#include <DxLib.h>
#include <Utility/Singleton.h>

#include <map>
#include <optional>

namespace spesium {
    class TextureManager : public Singleton<TextureManager> {
       public:
        TextureManager() = default;
        virtual ~TextureManager() = default;

        /// @brief テクスチャーの読み込み
        /// @param name：テクスチャーの名前
        /// @param filePath：テクスチャーを保存しているファイルパス
        void LoadTexture( const std::string& name_, const std::string& file_path_ );

        /// @brief テクスチャーの全削除
        void ReleaseTexture();

        /// @brief テクスチャーの取得
        /// @param name：テクスチャーの名前
        /// @return テクスチャーハンドル
        /// @note DrawGraph(X,Y,GetTexture(name),TransFlag)
        /// @note 未登録のテクスチャだった場合例外が出る
        int32_t GetTexture( const std::string& name_ ) const;

       private:
        std::map<std::string, int32_t> TextureList {};
    };
}  // namespace spesium

#endif  // !TEXTURE_MANAGER_H

#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include<map>
#include<DxLib.h>
#include<Definition/Definition.h>
#include<Utility/Singleton.h>
#include<optional>

namespace spesium
{
	class TextureManager :public Singleton<TextureManager> {
	public:
		TextureManager();
		virtual ~TextureManager();

		/// @brief テクスチャーの読み込み
		/// @param name：テクスチャーの名前
		/// @param filePath：テクスチャーを保存しているファイルパス
		void LoadTexture(const std::string& name, const std::string& filePath);

		/// @brief テクスチャーの全削除
		void ReleaseTexture();

		/// @brief テクスチャーの取得
		/// @param name：テクスチャーの名前
		/// @return テクスチャーハンドル
		/// @note DrawGraph(X,Y,GetTexture(name),TransFlag)
		std::optional<int32_t> GetTexture(const std::string& name);

	private:
		std::map<std::string, int32_t>TextureList;
	};
}
#endif // !TEXTURE_MANAGER_H

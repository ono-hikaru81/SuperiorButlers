#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <string>
#include <Utility/Singleton.h>

#include <map>

namespace spesium{
	class SoundManager: public Singleton<SoundManager>
	{
	public:
		SoundManager() = default;
		virtual ~SoundManager() = default;

		/// <summary>
		///		BGMをメモリに保存する関数
		/// </summary>
		/// <param name="name">BGMの名前</param>
		/// <param name="filePath">BGMを保存しているファイルパス</param>
		void LoadBGM(const std::string& name_, const std::string& filePath_);

		/// <summary>
		///		メモリにあるBGMハンドルをすべて削除
		/// </summary>
		void DeleteBGM();

		/// <summary>
		///		BGMを再生
		/// </summary>
		/// <param name="name">BGMの名前</param>
		void PlayBGM(const std::string& name_);

		/// <summary>
		///		BGMを止める
		/// </summary>
		void StopBGM();

		/// <summary>
		///		止めていたBGMを再生
		/// </summary>
		void RePlayBGM();

		/// <summary>
		///		BGMを変える
		/// </summary>
		/// <param name="name">BGMの名前</param>
		void ChangeBGM(const std::string& name_);
		
	private:
		std::map<std::string, int32_t> BGMList{};
		int32_t playingBGM{};
	};
}

#endif // !SOUND_MANAGER_H



#include "SoundManager.h"
#include <DxLib.h>

namespace  spesium{
    void SoundManager::LoadBGM(const std::string& name_, const std::string& filePath_) {
        auto handle{ LoadSoundMem(filePath_.c_str()) };
        if (handle == -1) { return; }

        BGMList.emplace(name_, handle);
    }

    void SoundManager::DeleteBGM() {
        BGMList.clear();
        InitSoundMem();
    }

    void SoundManager::PlayBGM(const std::string& name_) {
        auto handle = BGMList.find(name_)->second;
        if (playingBGM == handle) { return; }
        else
        {
            PlaySoundMem(handle, DX_PLAYTYPE_LOOP);
            playingBGM = handle;
        }
    }

    void SoundManager::StopBGM() {
        StopSoundMem(playingBGM);
    }

    void SoundManager::RePlayBGM() {
        if (CheckSoundMem(playingBGM)!=1)
        {
            PlaySoundMem(playingBGM, DX_PLAYTYPE_LOOP,FALSE);
        }
    }

    void SoundManager::ChangeBGM(const std::string& name_) {
        auto handle = BGMList.find(name_)->second;
        if (playingBGM != handle)
        {
            StopSoundMem(playingBGM);
            PlaySoundMem(handle, DX_PLAYTYPE_LOOP);
            playingBGM = handle;
        }
    }
}


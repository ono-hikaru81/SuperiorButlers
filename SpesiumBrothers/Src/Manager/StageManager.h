#ifndef STAGE_MANAGER_H
#define STAGE_MANAGER_H

#include <array>
#include <string>
#include <vector>

#include "../Singleton.h"
#include "../Utility/Property.h"

namespace stage {
    /// マップチップ横幅
    constexpr uint8_t MAPCHIP_WIDTH = 10;
    /// マップチップ縦幅
    constexpr uint8_t MAPCHIP_HEIGHT = 10;
    /// マップチップ総数
    constexpr uint16_t MAPCHIP_NUM = MAPCHIP_WIDTH * MAPCHIP_HEIGHT;

    /// ステージ情報管理クラス
    class StageManager : public utility::Singleton<StageManager> {
       private:
        /// ファイルの区切り文字
        static constexpr char SPLIT = ',';

        using stageData = std::array<uint16_t, MAPCHIP_NUM>;

       public:
        StageManager() = default;
        ~StageManager() = default;

       public:
        /**
        * @brief ファイル情報の取得
        * @param file_name_ ファイル名
        * @return ファイルが読み込めなかったらfalse
        */
        bool InputStageFile( const std::string& file_name_ );

        /**
        * @brief マップチップの取得
        * @param stage_name_ ステージ番号
        * @return 引数で指定されたマップチップ配列
        * @note ステージ番号は読み込んだ順で0から連番
        */
        stageData GetStageData( const uint8_t& stage_num_ ) const { return stages.at( stage_num_ ); }

       private:
        /// マップチップ情報
        std::vector<stageData> stages {};
    };
}  // namespace stage

#endif  // !STAGE_MANAGER_H

#include "StageManager.h"

#include <fstream>
#include <sstream>

#include "../Definition.h"

namespace stage {
    bool StageManager::InputStageFile( const std::string& file_name_ ) {
        std::ifstream file( file_name_ );
        if ( !file ) { return false; }

        stageData mapChip;

        std::string fileRow;
        uint16_t count { 0 };
        while ( std::getline( file, fileRow ) ) {
            std::stringstream row { fileRow };
            std::string chipNum;
            while ( std::getline( row, chipNum, SPLIT ) ) {
                mapChip.at( count ) = std::stoi( chipNum );
                count++;
            }
        }

        stages.push_back( mapChip );

        return true;
    }
}  // namespace stage

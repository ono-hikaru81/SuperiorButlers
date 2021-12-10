
#include "TextureManager.h"

#include <iostream>

namespace spesium {
    void TextureManager::LoadTexture( const std::string& name_, const std::string& file_path_ ) {
        auto handle { LoadGraph( file_path_.c_str() ) };
        if ( handle == -1 ) { return; }

        TextureList.emplace( name_, handle );
    }

    void TextureManager::ReleaseTexture() {
        TextureList.clear();
        InitGraph();
    }

    int32_t TextureManager::GetTexture( const std::string& name_ ) const {
        return TextureList.at( name_ );
    }
}  // namespace spesium

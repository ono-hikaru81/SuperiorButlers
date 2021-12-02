
#include "TextureManager.h"

namespace spesium {
    void TextureManager::LoadTexture( const std::string& name, const std::string& filePath ) {
        auto handle { LoadGraph( filePath.c_str() ) };
        if ( handle == -1 ) { return; }

        TextureList.emplace( name, handle );
    }

    void TextureManager::ReleaseTexture() {
        TextureList.clear();
        InitGraph();
    }

    std::optional<int32_t> TextureManager::GetTexture( const std::string& name ) {
        auto tmp { TextureList.find( name ) };
        return ( tmp == TextureList.end() ) ? std::nullopt : std::make_optional( tmp->second );
    }
}  // namespace spesium

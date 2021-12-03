
#include <DxLib.h>

#include <Manager/EffectManager.hpp>

namespace spesium {
    void EffectManager::Load( const std::string& name_, const std::string& filePath_ ) & {
        auto handle { LoadGraph( filePath_.c_str() ) };
        if ( handle == -1 ) { return; }
        list.try_emplace( name_, std::move( handle ) );
    }

    void EffectManager::Clear() & noexcept {
        for ( auto&& data : std::as_const( list ) ) {
            DeleteGraph( data.second );
        }

        list.clear();
    }

    auto EffectManager::Get( const std::string& name_ ) const& noexcept -> std::optional<int32_t> {
        auto res { list.find( name_ ) };
        return ( res == list.end() ) ? std::nullopt : std::make_optional( res->second );
    }

    void EffectManager::Generate( const std::string& name_, const Vector3<double>& position_ ) const& noexcept {
    }
}  // namespace spesium

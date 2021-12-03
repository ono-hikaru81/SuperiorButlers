
#include <DxLib.h>

#include <Manager/EffectManager.hpp>
#include <stdexcept>

namespace spesium {
    void EffectManager::Load( const std::string& name_, const std::string& file_path_ ) & {
        auto handle { LoadGraph( file_path_.c_str() ) };
        if ( handle == -1 ) [[unlikely]] {
            throw std::invalid_argument( "画像の読み込みに失敗しました。`" + file_path_ + "`を確認してください。" );
        }
        list.try_emplace( name_, std::move( handle ) );
    }

    void EffectManager::Clear() & noexcept {
        for ( auto&& data : std::as_const( list ) ) {
            DeleteGraph( data.second );
        }

        list.clear();
    }

    auto EffectManager::Get( const std::string& name_ ) const& -> int32_t {
        auto res { list.find( name_ ) };
        if ( res == list.end() ) [[unlikely]] {
            throw std::out_of_range( name_ + "が見つかりませんでした。" );
        }

        return res->second;
    }

    void EffectManager::Generate( const std::string& name_, const Vector3<double>& position_ ) const& noexcept {
    }
}  // namespace spesium

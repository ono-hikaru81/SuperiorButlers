#include "AnimationManager.h"

#include <iomanip>
#include <iostream>
#include <sstream>

namespace spesium {
    bool AnimationManager::LoadAnimation( const std::string& name_, const std::string& file_name_, const uint8_t& texture_num_, const uint8_t& switch_time_, const std::string& file_type_ ) {
        AnimationManager::Data data { .switchTime = switch_time_, .textureNum = texture_num_ };

        for ( uint8_t i = 1; i <= texture_num_; i++ ) {
            std::stringstream fileName {};
            fileName << file_name_ << std::setfill( '0' ) << std::setw( 3 ) << std::right << std::to_string( i ) << file_type_;

            auto handle { LoadGraph( fileName.str().c_str() ) };
            if ( handle == -1 ) {
                data.ReleaseTextures();

                return false;
            }

            data.textureList.push_back( handle );
        }

        AnimationList.emplace( name_, data );

        return true;
    }

    int32_t AnimationManager::GetAnimationTexture( const std::string& name_ ) {
        auto& animationData = AnimationList.at( name_ );

        uint8_t textureNum { animationData.frameCount / animationData.switchTime % animationData.textureNum };

        animationData.frameCount++;

        return animationData.textureList.at( textureNum );
    }

    int32_t AnimationManager::GetAnimationTexture( const std::string& name_, const uint8_t& texture_num_ ) {
        return AnimationList.at( name_ ).textureList.at( texture_num_ );
    }

    void AnimationManager::ResetAnimation( const std::string& name_ ) {
        AnimationList.at( name_ ).frameCount = 0;
    }
    void AnimationManager::ReleaseAnimation() {
        for ( auto&& data : std::as_const( AnimationList ) ) {
            data.second.ReleaseTextures();
        }

        AnimationList.clear();
    }
}  // namespace spesium

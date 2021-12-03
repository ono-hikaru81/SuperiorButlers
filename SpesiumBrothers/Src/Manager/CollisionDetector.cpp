
#include <Manager/CollisionDetector.hpp>

namespace spesium {
    void CollisionDetector::Set( const player_type& player1_, const player_type& player2_ ) & noexcept {
        player1 = player1_;
        player2 = player2_;
    }

    void CollisionDetector::Update() const& {
        if ( player1.expired() ) { return; }
        if ( player2.expired() ) { return; }

        auto p1List { player1.lock()->FrameDataList.Get() };
        auto p2List { player2.lock()->FrameDataList.Get() };

        for ( auto&& p1Frame : std::as_const( p1List ) ) {
            for ( auto&& p2Frame : std::as_const( p2List ) ) {
                auto distance { ConvertDimention( p1Frame.position ).Distance( ConvertDimention( p2Frame.position ) ) };

                distance -= p1Frame.radius + p2Frame.radius;
                if ( distance <= 0.0 ) {
                    player1.lock()->OnCollision();
                    player2.lock()->OnCollision();
                }
            }
        }
    }
}  // namespace spesium

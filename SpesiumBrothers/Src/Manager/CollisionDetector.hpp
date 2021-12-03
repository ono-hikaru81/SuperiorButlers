
// 衝突判定をする

#ifndef COLLISION_DETECTOR_H_
#define COLLISION_DETECTOR_H_

#include <Character/CharacterBase.h>

#include <Utility/Vector.hpp>
#include <vector>

namespace spesium {
    class CollisionDetector {
       public:
        using player_type = std::weak_ptr<character::CharacterBase>;

       public:
        CollisionDetector() = default;

        ~CollisionDetector() = default;

       public:
        void Set( const player_type& player1_, const player_type& player2_ ) & noexcept;

        void Update() const&;

       private:
        player_type player1 {};
        player_type player2 {};
    };
}  // namespace spesium

#endif  // COLLISION_DETECTOR_H_

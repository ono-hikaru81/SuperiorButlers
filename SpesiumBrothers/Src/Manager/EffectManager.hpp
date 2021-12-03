
// エフェクトの管理

#ifndef EFFECT_MANAGER_HPP
#define EFFECT_MANAGER_HPP

#include <Utility/Singleton.h>

#include <Utility/Vector.hpp>
#include <map>
#include <string>

namespace spesium {
    class EffectManager : public Singleton<EffectManager> {
       public:
        EffectManager() = default;

        ~EffectManager() = default;

       public:
        void Load( const std::string& name_, const std::string& file_path_ ) &;

        void Clear() & noexcept;

        [[nodiscard]] auto Get( const std::string& name_ ) const& -> int32_t;

        void Generate( const std::string& name_, const Vector3<double>& position_ ) const& noexcept;

       private:
        std::map<std::string, int32_t> list {};
    };
}  // namespace spesium

#endif  // !EFFECT_MANAGER_HPP

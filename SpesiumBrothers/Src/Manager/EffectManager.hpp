
// エフェクトの管理

#ifndef EFFECT_MANAGER_HPP
#define EFFECT_MANAGER_HPP

#include <Utility/Singleton.h>

namespace spesium {
    class EffectManager : public Singleton<EffectManager> {
       public:
        EffectManager() = default;

        ~EffectManager() = default;
    };
}  // namespace spesium

#endif  // !EFFECT_MANAGER_HPP

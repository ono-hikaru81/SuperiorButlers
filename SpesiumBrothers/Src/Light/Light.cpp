
#include <Light/Light.h>

namespace spesium {
    namespace tool {
        void Light::CreateDirectionLight( Vector3<double> pos_ ) {
            lightHandle = CreateDirLightHandle( pos_ );
        }

        void Light::CreatePointLight( Vector3<double> pos_, float max_range_, float attenuation_0_, float attenuation_1_, float attenuation_2_ ) {
            // d = ライトから頂点への距離
            // ライトの影響力(％) = 100.0f / ( Atten0 + Atten1 * d + Atten2 * d * d )
            lightHandle = CreatePointLightHandle( pos_, max_range_, attenuation_0_, attenuation_1_, attenuation_2_ );
        }

        void Light::CreateSpotLight( Vector3<double> pos_, Vector3<double> direction_, float angle_, float angle_attenuation_, float max_range_, float attenuation_0_, float attenuation_1_, float attenuation_2_ ) {
            lightHandle = CreateSpotLightHandle( pos_, direction_, angle_, angle_attenuation_, max_range_, attenuation_0_, attenuation_1_, attenuation_2_ );
        }

        void Light::DeleteLight() {
            DeleteLightHandle( lightHandle );
        }
    }  // namespace tool
}  // namespace spesium

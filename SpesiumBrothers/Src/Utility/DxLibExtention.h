
// DxLib関数の改良,拡張

#ifndef DX_LIB_EXTENTION_H
#define DX_LIB_EXTENTION_H

#include <DxLib.h>

#include <Utility/Size.hpp>

namespace spesium {
    namespace dxx {
        /// @brief ウィンドウの設定 @n body : SetGraphMode
        /// @param windowSize
        template<std::unsigned_integral T>
        void WindowSetting( Size2<T> windowSize ) {
            SetGraphMode( static_cast<int32_t>( windowSize.X ), static_cast<int32_t>( windowSize.Y ), 32 );
        }
    }  // namespace dxx
}  // namespace spesium

#endif  // !DX_LIB_EXTENTION_H

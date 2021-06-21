// DxLib関数の改良,拡張

#ifndef DX_LIB_EXTENTION_H
#define DX_LIB_EXTENTION_H

#include "DxLib.h"
#include "Size.h"

namespace dxx {
    /// @brief ウィンドウの設定 @n body : SetGraphMode
    /// @param windowSize
    void WindowSetting( utility::Size windowSize ) {
        SetGraphMode( static_cast<int32_t>( windowSize.X ), static_cast<int32_t>( windowSize.Y ), 32 );
    }
}  // namespace dxx

#endif  // !DX_LIB_EXTENTION_H

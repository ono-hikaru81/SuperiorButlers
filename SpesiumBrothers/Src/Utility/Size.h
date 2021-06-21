#ifndef SIZE_H
#define SIZE_H

#include "Property.h"

namespace utility {
    /// @brief 大きさを表現
    struct Size {
       public:
        /// @brief Default
        Size() :
            x( 0.0 ), y( 0.0 ), z( 1.0 ) {}

        /// @brief 大きさを表現
        /// @param xSize X(横)の大きさ
        /// @param ySize Y(縦)の大きさ
        explicit Size( auto xSize, auto ySize ) :
            x( xSize ), y( ySize ), z( 1.0 ) {}

        /// @brief 大きさを表現
        /// @param xSize X(横)の大きさ
        /// @param ySize Y(縦)の大きさ
        /// @param zSize Z(奥)の大きさ
        explicit Size( auto xSize, auto ySize, auto zSize ) :
            x( xSize ), y( ySize ), z( zSize ) {}

       public:
        /// @brief サイズを設定
        /// @param xSize X(横)の大きさ
        /// @param ySize Y(縦)の大きさ
        void Set( auto xSize, auto ySize ) { x = xSize, y = ySize; }

        /// @brief サイズを設定
        /// @param xSize X(横)の大きさ
        /// @param ySize Y(縦)の大きさ
        /// @param zSize Z(奥)の大きさ
        void Set( auto xSize, auto ySize, auto zSize ) { x = xSize, y = ySize, z = zSize; }

#pragma region operator override
        Size operator+( Size size ) const { return Size { x + size.x, y + size.y, z + size.z }; }

        Size operator-( Size size ) const { return Size { x - size.x, y - size.y, z - size.z }; }

        Size operator*( auto value ) const { return Size { x * value, y * value, z * value }; }

        Size operator/( auto value ) const { return Size { x / value, y / value, z / value }; }

        void operator+=( Size size ) { Set( x + size.x, y + size.y, z + size.z ); }

        void operator-=( Size size ) { Set( x - size.x, y - size.y, z - size.z ); }

        void operator*=( auto value ) { Set( x * value, y * value, z * value ); }

        void operator/=( auto value ) { Set( x / value, y / value, z / value ); }

        bool operator==( Size size ) const { return ( x == size.x && y == size.y && z == size.z ); }
#pragma endregion

       public:
        Property<double> X { x };
        Property<double> Y { y };
        Property<double> Z { z };

       private:
        double x;
        double y;
        double z;
    };
}  // namespace utility

#endif  // !SIZE_H

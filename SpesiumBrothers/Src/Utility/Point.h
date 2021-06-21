#ifndef POINT_H
#define POINT_H

#include "Property.h"

namespace utility {
    /// @brief 位置情報
    struct Point {
       public:
        /// @brief Default
        Point() :
            x( 0.0 ), y( 0.0 ), z( 0.0 ) {}

        /// @brief 位置情報
        /// @param xPos Xの位置
        /// @param yPos Yの位置
        explicit Point( auto xPos, auto yPos ) :
            x( xPos ), y( yPos ), z( 0.0 ) {}

        /// @brief 位置情報
        /// @param xPos Xの位置
        /// @param yPos Yの位置
        /// @param zPos Zの位置
        explicit Point( auto xPos, auto yPos, auto zPos ) :
            x( xPos ), y( yPos ), z( zPos ) {}

       public:
        /// @brief 位置を設定
        /// @param xPos Xの位置
        /// @param yPos Yの位置
        void Set( auto xPos, auto yPos ) { x = xPos, y = yPos; }

        /// @brief 位置を設定
        /// @param xPos Xの位置
        /// @param yPos Yの位置
        /// @param zPos Zの位置
        void Set( auto xPos, auto yPos, auto zPos = 0.0 ) { x = xPos, y = yPos, z = zPos; }

#pragma region operator override
        Point operator+( Point point ) const { return Point { x + point.x, y + point.y, z + point.z }; }

        Point operator-( Point point ) const { return Point { x - point.x, y - point.y, z - point.z }; }

        Point operator*( auto value ) const { return Point { x * value, y * value, z * value }; }

        Point operator/( auto value ) const { return Point { x / value, y / value, z / value }; }

        void operator+=( Point point ) { Set( x + point.x, y + point.y, z + point.z ); }

        void operator-=( Point point ) { Set( x - point.x, y - point.y, z - point.z ); }

        void operator*=( auto value ) { Set( x * value, y * value, z * value ); }

        void operator/=( auto value ) { Set( x / value, y / value, z / value ); }

        bool operator==( Point point ) const { return ( x == point.x && y == point.y && z == point.z ); }
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

#endif  // !POINT_H

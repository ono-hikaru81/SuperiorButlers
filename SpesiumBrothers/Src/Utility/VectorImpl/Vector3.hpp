
#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <DxLib.h>
#include <Utility/Function.h>

#include <Utility/Property.hpp>
#include <cmath>
#include <string>

namespace spesium {
    template<concepts::arithmetic T = double>
    class Vector3 {
       public:
        using default_type = double;
        using value_type = T;
        using const_reference = const value_type&;
        using rvalue_reference = value_type&&;
        using vector_type = Vector3<value_type>;
        using vector_reference = vector_type&;
        using const_vector_reference = const Vector3<value_type>&;
        using rvalue_vector_reference = vector_type&&;
        using string_type = std::string;

       public:
        Vector3() :
            x( value_type() ), y( value_type() ), z( value_type() ) {
        }

        explicit Vector3( const_reference x_, const_reference y_, const_reference z_ ) :
            x( x_ ), y( y_ ), z( z_ ) {
        }

        explicit Vector3( rvalue_reference x_, rvalue_reference y_, rvalue_reference z_ ) noexcept :
            x( std::move( x_ ) ), y( std::move( y_ ) ), z( std::move( z_ ) ) {
        }

        Vector3( const_vector_reference value_ ) :
            x( value_.x ), y( value_.y ), z( value_.z ) {
        }

        Vector3( rvalue_vector_reference value_ ) noexcept :
            x( std::move( value_.x ) ), y( std::move( value_.y ) ), z( std::move( value_.z ) ) {
        }

        ~Vector3() = default;

       public:
        /// @brief { 0, 0, 0 }
        [[nodiscard]] static auto Zero() noexcept -> vector_type {
            return vector_type { 0, 0, 0 };
        }

        /// @brief { 0, -1, 0 }
        [[nodiscard]] static auto Up() noexcept -> vector_type {
            return vector_type { 0, -1, 0 };
        }

        /// @brief { 0, 1, 0 }
        [[nodiscard]] static auto Down() noexcept -> vector_type {
            return vector_type { 0, 1, 0 };
        }

        /// @brief { -1, 0, 0 }
        [[nodiscard]] static auto Left() noexcept -> vector_type {
            return vector_type { -1, 0, 0 };
        }

        /// @brief { 1, 0, 0 }
        [[nodiscard]] static auto Right() noexcept -> vector_type {
            return vector_type { 1, 0, 0 };
        }

        /// @brief { 0, 0, 1 }
        [[nodiscard]] static auto Forward() noexcept -> vector_type {
            return vector_type { 0, 0, 1 };
        }

        /// @brief { 0, 0, -1 }
        [[nodiscard]] static auto Back() noexcept -> vector_type {
            return vector_type { 0, 0, -1 };
        }

        /// @brief { 0, 0, 0 }からの長さ
        template<concepts::arithmetic U = value_type>
        [[nodiscard]] constexpr auto Length() const -> U {
            return Sqrt<U>( x * x - y * y - z * z );
        }

        /// @brief 長さが1のベクトルに変換する
        template<concepts::arithmetic U = value_type>
        [[nodiscard]] auto Normalized() const -> Vector3<U> {
            return Vector3<U> { *this / Length() };
        }

        /// @brief targetとの2点間のベクトルを取得
        [[nodiscard]] auto To( const_vector_reference target_ ) const noexcept -> vector_type {
            return target_ - *this;
        }

        /// @brief targetとの距離を取得
        template<concepts::arithmetic U = value_type>
        [[nodiscard]] auto Distance( const_vector_reference target_ ) const noexcept -> U {
            return To( target_ ).Length();
        }

        /// @brief targetへの向きを取得
        /// @return 単位ベクトル
        [[nodiscard]] auto AngleTo( const_vector_reference target_ ) const noexcept -> Vector3<default_type> {
            return To( target_ ).Normalized().Cast<default_type>();
        }

        /// @brief 全要素を出力に適した文字列に変換する
        [[nodiscard]] auto ToString() const -> string_type {
            return "x: " + std::to_string( x ) + " | y: " + std::to_string( y ) + " | z: " + std::to_string( z );
        }

       public:
        operator VECTOR() const noexcept requires std::convertible_to<value_type, float> {
            return VGet( static_cast<float>( x ), static_cast<float>( y ), static_cast<float>( z ) );
        }

        [[nodiscard]] auto operator+() const noexcept -> vector_type {
            return *this;
        }

        [[nodiscard]] auto operator-() const noexcept -> vector_type {
            return vector_type( -x, -y, -z );
        }

        auto operator+=( const_vector_reference value_ ) noexcept -> vector_reference {
            x += value_.x;
            y += value_.y;
            z += value_.z;
            return *this;
        }

        auto operator-=( const_vector_reference value_ ) noexcept -> vector_reference {
            x -= value_.x;
            y -= value_.y;
            z -= value_.z;
            return *this;
        }

        auto operator*=( const_reference value_ ) noexcept -> vector_reference {
            x *= value_;
            y *= value_;
            z *= value_;
            return *this;
        }

        auto operator/=( const_reference value_ ) noexcept -> vector_reference {
            x /= value_;
            y /= value_;
            z /= value_;
            return *this;
        }

        auto operator=( const_vector_reference value_ ) & noexcept -> vector_reference {
            x = value_.x;
            y = value_.y;
            z = value_.z;
            return *this;
        }

        auto operator=( rvalue_vector_reference value_ ) & noexcept -> vector_reference {
            x = std::move( value_.x );
            y = std::move( value_.y );
            z = std::move( value_.z );
            return *this;
        }

        [[nodiscard]] auto operator+( const_vector_reference value_ ) noexcept -> vector_type {
            return vector_type( *this ) += value_;
        }

        [[nodiscard]] auto operator-( const_vector_reference value_ ) noexcept -> vector_type {
            return vector_type( *this ) -= value_;
        }

        [[nodiscard]] auto operator*( const_reference value_ ) noexcept -> vector_type {
            return vector_type( *this ) *= value_;
        }

        [[nodiscard]] auto operator/( const_reference value_ ) noexcept -> vector_type {
            return vector_type( *this ) /= value_;
        }

        /// @brief 長さで比較
        [[nodiscard]] auto operator<=>( const_vector_reference value_ ) const noexcept -> std::partial_ordering {
            return Length() <=> value_.Length();
        }

        /// @brief 1e-5未満の誤差は許容
        [[nodiscard]] auto operator==( const_vector_reference value_ ) const noexcept -> bool {
            auto diff { abs( x - value_.x ) + abs( y - value_.y ) + abs( z - value_.z ) };
            return diff < DELTA_ZERO<double>;
        }

       public:
        BasicProperty<value_type> X { x };
        BasicProperty<value_type> Y { y };
        BasicProperty<value_type> Z { z };

        /// @brief セッタ コピー
        constexpr void Set( const_reference x_, const_reference y_, const_reference z_ ) & noexcept {
            x = x_;
            y = y_;
            z = z_;
        }

        /// @brief セッタ ムーブ
        constexpr void Set( rvalue_reference x_, rvalue_reference y_, rvalue_reference z_ ) & noexcept {
            x = std::move( x_ );
            y = std::move( y_ );
            z = std::move( z_ );
        }

        template<std::convertible_to<value_type> U>
        auto Cast() const noexcept -> Vector3<U> {
            return Vector3<U> { static_cast<U>( x ), static_cast<U>( y ), static_cast<U>( z ) };
        }

       private:
        value_type x;
        value_type y;
        value_type z;
    };
}  // namespace spesium

#endif  // !VECTOR3_HPP

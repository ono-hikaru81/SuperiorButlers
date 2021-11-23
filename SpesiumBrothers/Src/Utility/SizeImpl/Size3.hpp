
#ifndef SIZE3_HPP
#define SIZE3_HPP

#include <Utility/Property.hpp>
#include <string>

namespace spesium {
    template<concepts::arithmetic T = double>
    class Size3 {
       public:
        using value_type = T;
        using const_reference = const value_type&;
        using rvalue_reference = value_type&&;
        using size_type = Size3<value_type>;
        using const_size_reference = const size_type&;
        using rvalue_size_reference = size_type&&;
        using string_type = std::string;

        Size3() :
            x( value_type() ), y( value_type() ), z( value_type() ) {
        }

        explicit Size3( const_reference x_, const_reference y_, const_reference z_ ) :
            x( x_ ), y( y_ ), z( z_ ) {
        }

        explicit Size3( rvalue_reference x_, rvalue_reference y_, rvalue_reference z_ ) noexcept :
            x( std::move( x_ ) ), y( std::move( y_ ) ), z( std::move( z_ ) ) {
        }

        Size3( const_size_reference value_ ) :
            x( value_.x ), y( value_.y ), z( value_.z ) {
        }

        Size3( rvalue_size_reference value_ ) noexcept :
            x( std::move( value_.x ) ), y( std::move( value_.y ) ), z( std::move( value_.z ) ) {
        }

       public:
        /// @brief { 0, 0, 0 }
        [[nodiscard]] static auto Zero() noexcept -> size_type {
            return size_type { 0, 0, 0 };
        }

        /// @brief 全要素を出力に適した文字列に変換する
        [[nodiscard]] auto ToString() const -> string_type {
            return "x: " + std::to_string( x ) + " | y: " + std::to_string( y ) + " | z: " + std::to_string( z );
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
        auto Cast() const noexcept -> Size3<U> {
            return Size3<U> { static_cast<U>( x ), static_cast<U>( y ), static_cast<U>( z ) };
        }

       private:
        value_type x;
        value_type y;
        value_type z;
    };
}  // namespace spesium

#endif  // !SIZE3_HPP

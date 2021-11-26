
#ifndef SIZE2_HPP
#define SIZE2_HPP

#include <Utility/Property.hpp>
#include <string>

namespace spesium {
    template<concepts::arithmetic T = double>
    class Size2 {
       public:
        using value_type = T;
        using const_reference = const value_type&;
        using rvalue_reference = value_type&&;
        using size_type = Size2<value_type>;
        using const_size_reference = const size_type&;
        using rvalue_size_reference = size_type&&;
        using string_type = std::string;

        Size2() :
            x( value_type() ), y( value_type() ) {
        }

        explicit Size2( const_reference x_, const_reference y_ ) :
            x( x_ ), y( y_ ) {
        }

        explicit Size2( rvalue_reference x_, rvalue_reference y_ ) noexcept :
            x( std::move( x_ ) ), y( std::move( y_ ) ) {
        }

        Size2( const_size_reference value_ ) :
            x( value_.x ), y( value_.y ) {
        }

        Size2( rvalue_size_reference value_ ) noexcept :
            x( std::move( value_.x ) ), y( std::move( value_.y ) ) {
        }

       public:
        /// @brief { 0, 0 }
        [[nodiscard]] static auto Zero() noexcept -> size_type {
            return size_type { 0, 0 };
        }

        /// @brief 全要素を出力に適した文字列に変換する
        [[nodiscard]] auto ToString() const -> string_type {
            return "x: " + std::to_string( x ) + " | y: " + std::to_string( y );
        }

       public:
        BasicProperty<value_type> X { x };
        BasicProperty<value_type> Y { y };

        /// @brief セッタ コピー
        constexpr void Set( const_reference x_, const_reference y_ ) & noexcept {
            x = x_;
            y = y_;
        }

        /// @brief セッタ ムーブ
        constexpr void Set( rvalue_reference x_, rvalue_reference y_ ) & noexcept {
            x = std::move( x_ );
            y = std::move( y_ );
        }

        template<std::convertible_to<value_type> U>
        auto Cast() const noexcept -> Size2<U> {
            return Size2<U> { static_cast<U>( x ), static_cast<U>( y ) };
        }

       private:
        value_type x;
        value_type y;
    };
}  // namespace spesium

#endif  // !SIZE2_HPP

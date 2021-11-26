
#ifndef PROPERTY_HPP
#define PROPERTY_HPP

#include <Utility/PropertyImpl/BasicProperty.hpp>
#include <Utility/PropertyImpl/ReadonlyProperty.hpp>
#include <compare>

namespace spesium {
    // Propertyの四則演算+α演算子を定義
    // +

    template<typename T, typename U>
    auto operator+( const BasicProperty<T>& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::add_to<T, U> {
        return *lvalue + *rvalue;
    }

    template<typename T, typename U>
    auto operator+( const BasicProperty<T>& lvalue, const ReadonlyProperty<U>& rvalue ) -> decltype( auto ) requires concepts::add_to<T, U> {
        return *lvalue + *rvalue;
    }

    template<typename T, typename U>
    auto operator+( const ReadonlyProperty<T>& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::add_to<T, U> {
        return *lvalue + *rvalue;
    }

    template<typename T, typename U>
    auto operator+( const ReadonlyProperty<T>& lvalue, const ReadonlyProperty<U>& rvalue ) -> decltype( auto ) requires concepts::add_to<T, U> {
        return *lvalue + *rvalue;
    }

    template<typename T, typename U>
    auto operator+( const BasicProperty<T>& lvalue, const U& rvalue ) -> decltype( auto ) requires concepts::add_to<T, U> {
        return *lvalue + rvalue;
    }

    template<typename T, typename U>
    auto operator+( const T& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::add_to<T, U> {
        return lvalue + *rvalue;
    }

    // -

    template<typename T, typename U>
    auto operator-( const BasicProperty<T>& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::subtract_to<T, U> {
        return *lvalue - *rvalue;
    }

    template<typename T, typename U>
    auto operator-( const BasicProperty<T>& lvalue, const ReadonlyProperty<U>& rvalue ) -> decltype( auto ) requires concepts::subtract_to<T, U> {
        return *lvalue - *rvalue;
    }

    template<typename T, typename U>
    auto operator-( const ReadonlyProperty<T>& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::subtract_to<T, U> {
        return *lvalue - *rvalue;
    }

    template<typename T, typename U>
    auto operator-( const ReadonlyProperty<T>& lvalue, const ReadonlyProperty<U>& rvalue ) -> decltype( auto ) requires concepts::subtract_to<T, U> {
        return *lvalue - *rvalue;
    }

    template<typename T, typename U>
    auto operator-( const BasicProperty<T>& lvalue, const U& rvalue ) -> decltype( auto ) requires concepts::subtract_to<T, U> {
        return *lvalue - rvalue;
    }

    template<typename T, typename U>
    auto operator-( const T& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::subtract_to<T, U> {
        return lvalue - *rvalue;
    }

    // *

    template<typename T, typename U>
    auto operator*( const BasicProperty<T>& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::multiplication_to<T, U> {
        return *lvalue * *rvalue;
    }

    template<typename T, typename U>
    auto operator*( const BasicProperty<T>& lvalue, const ReadonlyProperty<U>& rvalue ) -> decltype( auto ) requires concepts::multiplication_to<T, U> {
        return *lvalue * *rvalue;
    }

    template<typename T, typename U>
    auto operator*( const ReadonlyProperty<T>& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::multiplication_to<T, U> {
        return *lvalue * *rvalue;
    }

    template<typename T, typename U>
    auto operator*( const ReadonlyProperty<T>& lvalue, const ReadonlyProperty<U>& rvalue ) -> decltype( auto ) requires concepts::multiplication_to<T, U> {
        return *lvalue * *rvalue;
    }

    template<typename T, typename U>
    auto operator*( const BasicProperty<T>& lvalue, const U& rvalue ) -> decltype( auto ) requires concepts::multiplication_to<T, U> {
        return *lvalue * rvalue;
    }

    template<typename T, typename U>
    auto operator*( const T& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::multiplication_to<T, U> {
        return lvalue * *rvalue;
    }

    // /

    template<typename T, typename U>
    auto operator/( const BasicProperty<T>& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::division_to<T, U> {
        return *lvalue / *rvalue;
    }

    template<typename T, typename U>
    auto operator/( const BasicProperty<T>& lvalue, const ReadonlyProperty<U>& rvalue ) -> decltype( auto ) requires concepts::division_to<T, U> {
        return *lvalue / *rvalue;
    }

    template<typename T, typename U>
    auto operator/( const ReadonlyProperty<T>& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::division_to<T, U> {
        return *lvalue / *rvalue;
    }

    template<typename T, typename U>
    auto operator/( const ReadonlyProperty<T>& lvalue, const ReadonlyProperty<U>& rvalue ) -> decltype( auto ) requires concepts::division_to<T, U> {
        return *lvalue / *rvalue;
    }

    template<typename T, typename U>
    auto operator/( const BasicProperty<T>& lvalue, const U& rvalue ) -> decltype( auto ) requires concepts::division_to<T, U> {
        return *lvalue / rvalue;
    }

    template<typename T, typename U>
    auto operator/( const T& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::division_to<T, U> {
        return lvalue / *rvalue;
    }

    // %

    template<typename T, typename U>
    auto operator%( const BasicProperty<T>& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::modulo_to<T, U> {
        return *lvalue % *rvalue;
    }

    template<typename T, typename U>
    auto operator%( const BasicProperty<T>& lvalue, const ReadonlyProperty<U>& rvalue ) -> decltype( auto ) requires concepts::modulo_to<T, U> {
        return *lvalue % *rvalue;
    }

    template<typename T, typename U>
    auto operator%( const ReadonlyProperty<T>& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::modulo_to<T, U> {
        return *lvalue % *rvalue;
    }

    template<typename T, typename U>
    auto operator%( const ReadonlyProperty<T>& lvalue, const ReadonlyProperty<U>& rvalue ) -> decltype( auto ) requires concepts::modulo_to<T, U> {
        return *lvalue % *rvalue;
    }

    template<typename T, typename U>
    auto operator%( const BasicProperty<T>& lvalue, const U& rvalue ) -> decltype( auto ) requires concepts::modulo_to<T, U> {
        return *lvalue % rvalue;
    }

    template<typename T, typename U>
    auto operator%( const T& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::modulo_to<T, U> {
        return lvalue % *rvalue;
    }

    // <<

    template<typename T, typename U>
    auto operator<<( const BasicProperty<T>& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::left_shift_to<T, U> {
        return *lvalue << *rvalue;
    }

    template<typename T, typename U>
    auto operator<<( const BasicProperty<T>& lvalue, const ReadonlyProperty<U>& rvalue ) -> decltype( auto ) requires concepts::left_shift_to<T, U> {
        return *lvalue << *rvalue;
    }

    template<typename T, typename U>
    auto operator<<( const ReadonlyProperty<T>& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::left_shift_to<T, U> {
        return *lvalue << *rvalue;
    }

    template<typename T, typename U>
    auto operator<<( const ReadonlyProperty<T>& lvalue, const ReadonlyProperty<U>& rvalue ) -> decltype( auto ) requires concepts::left_shift_to<T, U> {
        return *lvalue << *rvalue;
    }

    template<typename T, typename U>
    auto operator<<( const BasicProperty<T>& lvalue, const U& rvalue ) -> decltype( auto ) requires concepts::left_shift_to<T, U> {
        return *lvalue << rvalue;
    }

    template<typename T, typename U>
    auto operator<<( const T& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::left_shift_to<T, U> {
        return lvalue << *rvalue;
    }

    // >>

    template<typename T, typename U>
    auto operator>>( const BasicProperty<T>& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::right_shift_to<T, U> {
        return *lvalue >> *rvalue;
    }

    template<typename T, typename U>
    auto operator>>( const BasicProperty<T>& lvalue, const ReadonlyProperty<U>& rvalue ) -> decltype( auto ) requires concepts::right_shift_to<T, U> {
        return *lvalue >> *rvalue;
    }

    template<typename T, typename U>
    auto operator>>( const ReadonlyProperty<T>& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::right_shift_to<T, U> {
        return *lvalue >> *rvalue;
    }

    template<typename T, typename U>
    auto operator>>( const ReadonlyProperty<T>& lvalue, const ReadonlyProperty<U>& rvalue ) -> decltype( auto ) requires concepts::right_shift_to<T, U> {
        return *lvalue >> *rvalue;
    }

    template<typename T, typename U>
    auto operator>>( const BasicProperty<T>& lvalue, const U& rvalue ) -> decltype( auto ) requires concepts::right_shift_to<T, U> {
        return *lvalue >> rvalue;
    }

    template<typename T, typename U>
    auto operator>>( const T& lvalue, const BasicProperty<U>& rvalue ) -> decltype( auto ) requires concepts::right_shift_to<T, U> {
        return lvalue >> *rvalue;
    }

    // Propertyの比較演算子を定義
    // <=>

    template<typename T, typename U>
    auto operator<=>( const BasicProperty<T>& lvalue, const BasicProperty<U>& rvalue ) -> bool requires std::equality_comparable_with<T, U> {
        return *lvalue <=> *rvalue;
    }

    template<typename T, typename U>
    auto operator<=>( const BasicProperty<T>& lvalue, const ReadonlyProperty<U>& rvalue ) -> bool requires std::equality_comparable_with<T, U> {
        return *lvalue <=> *rvalue;
    }

    template<typename T, typename U>
    auto operator<=>( const ReadonlyProperty<T>& lvalue, const BasicProperty<U>& rvalue ) -> bool requires std::equality_comparable_with<T, U> {
        return *lvalue <=> *rvalue;
    }

    template<typename T, typename U>
    auto operator<=>( const ReadonlyProperty<T>& lvalue, const ReadonlyProperty<U>& rvalue ) -> bool requires std::equality_comparable_with<T, U> {
        return *lvalue <=> *rvalue;
    }

    template<typename T, typename U>
    auto operator<=>( const BasicProperty<T>& lvalue, const U& rvalue ) -> bool requires std::equality_comparable_with<T, U> {
        return *lvalue <=> rvalue;
    }

    template<typename T, typename U>
    auto operator<=>( const T& lvalue, const BasicProperty<U>& rvalue ) -> bool requires std::equality_comparable_with<T, U> {
        return lvalue <=> *rvalue;
    }

    // <=>

    template<typename T, typename U>
    auto operator<=>( const BasicProperty<T>& lvalue, const BasicProperty<U>& rvalue ) -> std::partial_ordering requires std::totally_ordered_with<T, U> {
        return *lvalue <=> *rvalue;
    }

    template<typename T, typename U>
    auto operator<=>( const BasicProperty<T>& lvalue, const ReadonlyProperty<U>& rvalue ) -> std::partial_ordering requires std::totally_ordered_with<T, U> {
        return *lvalue <=> *rvalue;
    }

    template<typename T, typename U>
    auto operator<=>( const ReadonlyProperty<T>& lvalue, const BasicProperty<U>& rvalue ) -> std::partial_ordering requires std::totally_ordered_with<T, U> {
        return *lvalue <=> *rvalue;
    }

    template<typename T, typename U>
    auto operator<=>( const ReadonlyProperty<T>& lvalue, const ReadonlyProperty<U>& rvalue ) -> std::partial_ordering requires std::totally_ordered_with<T, U> {
        return *lvalue <=> *rvalue;
    }

    template<typename T, typename U>
    auto operator<=>( const BasicProperty<T>& lvalue, const U& rvalue ) -> std::partial_ordering requires std::totally_ordered_with<T, U> {
        return *lvalue <=> rvalue;
    }

    template<typename T, typename U>
    auto operator<=>( const T& lvalue, const BasicProperty<U>& rvalue ) -> std::partial_ordering requires std::totally_ordered_with<T, U> {
        return lvalue <=> *rvalue;
    }
}  // namespace spesium

#endif  // !PROPERTY_HPP

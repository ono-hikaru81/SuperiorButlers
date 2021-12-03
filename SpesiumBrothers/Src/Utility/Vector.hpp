
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <Definition/Concepts.hpp>
#include <Utility/VectorImpl/Vector2.hpp>
#include <Utility/VectorImpl/Vector3.hpp>
namespace spesium {
    template<concepts::arithmetic T>
    auto ConvertDimention( const Vector3<T>& vector_ ) noexcept -> Vector2<T> {
        return Vector2<T> { vector_.X, vector_.Y };
    }

    template<concepts::arithmetic T>
    auto ConvertDimention( const Vector2<T>& vector_ ) noexcept -> Vector3<T> {
        return Vector3<T> { vector_.X, vector_.Y, 0 };
    }
}  // namespace spesium

#endif  // !VECTOR_HPP

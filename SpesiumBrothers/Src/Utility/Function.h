
#ifndef FUNCTION_H
#define FUNCTION_H

#include <Definition/Concepts.hpp>

namespace spesium {
    template<concepts::convertible_or_same_as<double> T>
    constexpr T DELTA_ZERO { static_cast<T>( 0.00001 ) };

    /*
        * @breif 変動している値が基準値以上になったら基準値を代入する関数。
        * @param (constant_value_) 基準値
	    * @param (fluctuation_value_) 変動値
	    */
    template<concepts::arithmetic T>
    void DisabledExceed( const T& constant_value_, T& fluctuation_value_ ) {
        if ( fluctuation_value_ > constant_value_ ) {
            fluctuation_value_ = constant_value_;
        }
    }

    /*
    	* @breif 変動している値が基準値以下になったら基準値を代入する関数。
    	* @param (constant_value_) 基準値
	    * @param (fluctuation_value_) 変動値
	    */
    template<concepts::arithmetic T>
    void DisabledBelow( const T& constant_value_, T& fluctuation_value_ ) {
        if ( fluctuation_value_ < constant_value_ ) {
            fluctuation_value_ = constant_value_;
        }
    }

    /// @brief 平方根
    template<concepts::arithmetic T>
    static constexpr auto Sqrt( T value ) -> T {
        if ( value < 0.0 ) { value = std::negate<T>()( value ); }
        auto half { value / 2.0 };

        while ( true ) {
            auto e { half * half - value };
            auto t { ( e < 0.0 ) ? -e : e };
            if ( t < DELTA_ZERO<double> ) { return static_cast<T>( half ); }
            half -= e / ( half * 2.0 );
        }
    }
}  // namespace spesium

#endif  // !FUNCTION_H

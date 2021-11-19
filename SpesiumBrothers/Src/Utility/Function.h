#ifndef FUNCTION_H
#define FUNCTION_H

#include <utility>
#include <iostream>

namespace utility
{
	template<typename T>
	concept Number = std::integral<T> || std::floating_point<T>;

	/*
	* @breif 変動している値が基準値以上になったら基準値を代入する関数。
	* @param (constant_value_) 基準値
	* @param (fluctuation_value_) 変動値
	*/
	template<Number T>
	void DisabledExceed(const T& constant_value_, T& fluctuation_value_)
	{
		if (fluctuation_value_ > constant_value_)
		{
			fluctuation_value_ = constant_value_;
		}
	}

	/*
	* @breif 変動している値が基準値以下になったら基準値を代入する関数。
	* @param (constant_value_) 基準値
	* @param (fluctuation_value_) 変動値
	*/
	template<Number T>
	void DisabledBelow(const T& constant_value_, T& fluctuation_value_)
	{
		if (fluctuation_value_ < constant_value_)
		{
			fluctuation_value_ = constant_value_;
		}
	}
}

#endif // !FUNCTION_H

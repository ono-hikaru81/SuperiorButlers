#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

#include "DxLib.h"
#include "Property.h"

namespace utility {
	/// @brief 2次元ベクトル
	struct Vector2 {
	public:
		/// @brief Default
		Vector2() :
			x(0.0), y(0.0) {}

		/// @brief 2次元ベクトル
		/// @param xPos Xの位置
		/// @param yPos Yの位置
		explicit Vector2(auto xPos, auto yPos) :
			x(xPos), y(yPos) {}

	public:
		/// @brief ベクトルの長さを取得
		/// @return √(x^2 + y^2)
		double Length() const { return sqrt(x * x + y * y); }

		/// @brief 正規化したベクトルを取得
		/// @return 各要素を長さで割ったベクトル
		Vector2 Normalized() const { return Vector2(x / Length(), y / Length()); }

		/// @brief ベクトルの値を設定
		/// @param xPos Xの位置
		/// @param yPos Yの位置
		void Set(auto xPos, auto yPos) { x = xPos, y = yPos; }

#pragma region operator override

		Vector2 operator+(Vector2 vector) const { return Vector2{ x + vector.x, y + vector.y }; }

		Vector2 operator-(Vector2 vector) const { return Vector2{ x - vector.x, y - vector.y }; }

		Vector2 operator*(auto value) const { return Vector2{ x * value, y * value }; }

        void operator=(Vector2 vector) { Set(vector.x, vector.y); }

        void operator+=( Vector2 vector ) { Set( x + vector.X, y + vector.Y ); }

		void operator-=(Vector2 vector) { Set(x - vector.X, y - vector.Y); }

		void operator*=(auto value) { Set(x * value, y * value); }

		void operator/=(auto value) { Set(x / value, y / value); }

		bool operator==(Vector2 vector) const { return (x == vector.X && y == vector.Y); }
#pragma endregion

	public:
		Property<double> X{ x };
		Property<double> Y{ y };

	private:
		double x;
		double y;
	};

	/// @brief 3次元ベクトル
	struct Vector3 {
	public:
		/// @brief Default
		Vector3() :
			x(0.0), y(0.0), z(0.0) {}

		/// @brief 3次元ベクトル
		/// @param xPos Xの位置
		/// @param yPos Yの位置
		/// @param zPos Zの位置
		explicit Vector3(auto xPos, auto yPos, auto zPos) :
			x(xPos), y(yPos), z(zPos) {}

	public:
		/// @brief ベクトルの長さを取得
		/// @return √(x^2 + y^2 + z^2)
		double Length() const { return sqrt(x * x + y * y + z * z); }

		/// @brief 正規化したベクトルを取得
		/// @return 各要素を長さで割ったベクトル
		Vector3 Normalized() const { return Vector3(x / Length(), y / Length(), z / Length()); }

		/// @brief ベクトルの値を設定
		/// @param xPos Xの位置
		/// @param yPos Yの位置
		/// @param zPos Zの位置
		void Set(auto xPos, auto yPos, auto zPos) { x = xPos, y = yPos, z = zPos; }

#pragma region operator override
		operator VECTOR() { return VGet(static_cast<float>(x), static_cast<float>(y), static_cast<float>(z)); }

		Vector3 operator+(Vector3 vector) const { return Vector3{ x + vector.x, y + vector.y, z + vector.z }; }

		Vector3 operator-(Vector3 vector) const { return Vector3{ x - vector.x, y - vector.y, z - vector.z }; }

		Vector3 operator*(auto value) const { return Vector3{ x * value, y * value, z * value }; }

		Vector3 operator/(auto value) const { return Vector3{ x / value, y / value, z / value }; }

		void operator+=(Vector3 vector) { Set(x + vector.X, y + vector.Y, z + vector.Z); }

		void operator-=(Vector3 vector) { Set(x - vector.X, y - vector.Y, z - vector.Z); }

		void operator=(Vector3 vector) { Set(vector.X, vector.Y, vector.Z); }

		void operator*=(auto value) { Set(x * value, y * value, z * value); }

		void operator/=(auto value) { Set(x / value, y / value, z / value); }

		bool operator==(Vector3 vector) const { return (x == vector.X && y == vector.Y && z == vector.Z); }
#pragma endregion

	public:
		Property<double> X{ x };
		Property<double> Y{ y };
		Property<double> Z{ z };

	private:
		double x;
		double y;
		double z;
	};
}  // namespace utility

#endif  // !VECTOR_H

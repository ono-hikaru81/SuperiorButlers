// プロパティ的なアクセサ

#ifndef PROPERTY_H
#define PROPERTY_H

#include <functional>
#include <memory>

// ゲッターメソッド
#define Getter( method ) [this]() { return method }

// セッターメソッド
#define Setter( value, method ) [this]( value ) { method }

namespace utility {
	template<typename T>
	class Property {
	public:
		/// @brief プロパティ
		/// @param target プロパティを適用する変数
		/// @param getter ゲッターのオーバーライド
		/// @param setter セッターのオーバーライド
		explicit Property(T& target, std::function<T()> getter = nullptr, std::function<void(T value)> setter = nullptr) :
			base(target), get(getter), set(setter) {}

		~Property() {}

	public:
		template <std::convertible_to<T>U>
		constexpr auto Cast() const -> U {
			return static_cast<U>((get) ? get() : base);
		}
		operator T() const {
			if (get)
				return get();
			else
				return base;
		}

		void operator=(const T value) {
			if (set)
				set(value);
			else
				base = value;
		}

		void operator=(const Property<T>& value) {
			if (set) { set(value.base); }
			else { base = value.base; }
		}

		void operator+=(const T value) {
			if (set)
				set(base + value);
			else
				base += value;
		}

		void operator+=(const Property<T> value) {
			if (set)
				set(base + value.base);
			else
				base += value.base;
		}

		void operator-=(const T value) {
			if (set)
				set(base - value);
			else
				base -= value;
		}

		void operator-=(const Property<T> value) {
			if (set)
				set(base - value.base);
			else
				base -= value.base;
		}

		T* operator->() const { return &base; }

		T* operator&() const { return &base; }

		constexpr auto operator*() const noexcept->T& {
			return base;
		}

	private:
		T& base;
		std::function<T()> get = nullptr;
		std::function<void(T value)> set = nullptr;
	};

	template<typename T>
	class ReadonlyProperty {
	public:
		/// @brief 読み取り専用プロパティ
		/// @param target プロパティを適用する変数
		/// @param getter ゲッターのオーバーライド
		explicit ReadonlyProperty(T& target, std::function<T()> getter = nullptr) :
			base(target), get(getter) {}

		~ReadonlyProperty() {}

	public:
		operator T() const {
			if (get != nullptr) return get();
			else
				return base;
		}

		T* operator->() const { return &base; }

		T* operator&() const { return &base; }

	private:
		T& base;
		std::function<T()> get = nullptr;
	};

	template<typename T>
	class SmartProperty {
	public:
		/// @brief スマートポインタ(weak_ptr)用プロパティ
		/// @param target プロパティを適用するスマートポインタ(weak_ptr)
		/// @param getter ゲッターのオーバーライド
		explicit SmartProperty(std::weak_ptr<T> target, std::function<std::weak_ptr<T>()> getter = nullptr) :
			base(target), get(getter) {}

		/// @brief スマートポインタ(weak_ptr)用プロパティ
		/// @param target プロパティを適用するスマートポインタ(shared_ptr)
		/// @param getter ゲッターのオーバーライド
		explicit SmartProperty(std::shared_ptr<T> target, std::function<std::weak_ptr<T>()> getter = nullptr) :
			base(target), get(getter) {}

		~SmartProperty() {}

	public:
		operator std::weak_ptr<T>() const {
			if (get) {
				std::weak_ptr<T> returns = get();
				if (returns.expired()) {
					throw std::exception("参照先が見つかりません");
				}

				return returns;
			}
			else {
				if (base.expired()) {
					throw std::exception("参照先が見つかりません");
				}

				return base;
			}
		}

		T* operator->() const { return base.lock().get(); }

	private:
		std::weak_ptr<T> base;
		std::function<std::weak_ptr<T>()> get = nullptr;
	};
}  // namespace utility

#endif  // !PROPERTY_H

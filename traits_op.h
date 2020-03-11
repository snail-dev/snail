#ifndef _TRAITS_H_
#define _TRAITS_H_

#include <cstddef>
#include <type_traits>

template <typename DS, typename T>
class HasDataAndSize {
private:
	template <typename C,
		typename std::enable_if <
			std::is_convertible<decltype(std::declval<C>().data()),T*>::value &&
			std::is_convertible<decltype(std::declval<C>().size()),size_t> ::value
		>::type* = nullptr>
	static int Test(int);

	template<typename>
	static char Test(...);
		

public:
	static constexpr bool value = std::is_same<decltype(Test<DS>(0)),int>::value;
};

template <typename T>
struct IsIntEnum {
private:
	template <typename X,
		typename std::enable_if<
			std::is_enum<X>::value &&
			std::is_integral<decltype(+std::declval<X>())>::value
		>::type* = nullptr>
	static int Test(int);

	template <typename>
	static char Test(...);

public:
	static constexpr bool value = std::is_same<decltype(Test<typename std::remove_reference<T>::type >(0)),int>::value;
};

template <typename T>
struct IsIntLike {
using X = typename std::remove_reference<T>::type;

public:
	static constexpr bool value = std::is_integral<X>::value || IsIntEnum<X>::value;
};

#endif

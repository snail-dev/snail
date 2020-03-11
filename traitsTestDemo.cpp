#include <iostream>
#include "traits_op.h"

template <typename DS, typename RS>
struct Test1 {
	DS data();
	RS size();
};

static_assert(HasDataAndSize<Test1<int*,int>,int>::value,"");
static_assert(HasDataAndSize<Test1<int*,int>,const int>::value,"");
static_assert(!HasDataAndSize<Test1<const int*,int>,int>::value,"");
static_assert(!HasDataAndSize<Test1<char*,int>,int>::value,"");


struct Test2 {
  int* data;
  std::size_t size;
};
static_assert(!HasDataAndSize<Test2, int>::value,
              ".data and .size aren't functions");

struct Test3 {
  int* data();
};
static_assert(!HasDataAndSize<Test3, int>::value, ".size() is missing");

class Test4 {
  int* data();
  size_t size();
};
static_assert(!HasDataAndSize<Test4, int>::value,
              ".data() and .size() are private");



enum E1 { e1 };
enum { e2 };
enum class E3 { e3 };
struct S {};

static_assert(IsIntEnum<E1>::value, "");
static_assert(IsIntEnum<decltype(e2)>::value, "");
static_assert(!IsIntEnum<E3>::value, "");
static_assert(!IsIntEnum<int>::value, "");
static_assert(!IsIntEnum<float>::value, "");
static_assert(!IsIntEnum<S>::value, "");

static_assert(IsIntLike<E1>::value, "");
static_assert(IsIntLike<decltype(e2)>::value, "");
static_assert(!IsIntLike<E3>::value, "");
static_assert(IsIntLike<int>::value, "");
static_assert(!IsIntLike<float>::value, "");
static_assert(!IsIntLike<S>::value, "");


int main() {

	std::cout << std::boolalpha
		<< std::is_enum<E1>::value << "\n"
		<< std::is_enum<decltype(e2)>::value << "\n"
		<< std::is_enum<E3>::value << "\n";

	std::cout << std::is_integral<decltype(+std::declval<E1>())>::value<< "\n"
		<< std::is_integral<decltype(+e2)>::value << "\n"
		<< std::is_integral<decltype(std::declval<E3>())>::value << "\n";

	std::cout << +e1 << " " << +e2 << " " /*<< +e3 */<< "\n";
	
	return 0;
}

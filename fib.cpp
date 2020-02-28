#include <iostream>
#include <type_traits>
/*
 * fib number serials
 * 1 1 2 3 5 8 13 21 34
 * 
 * */


template <unsigned n>
struct fib:std::integral_constant<int, fib<n-1>::value + fib<n-2>::value>{};

template <>
struct fib<0>:std::integral_constant<int,1>{};

template <>
struct fib<1>:std::integral_constant<int,1>{};

int main() {
	std::cout<<fib<8>::value<<"\n";
	return 0;
}

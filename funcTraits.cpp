#include <iostream>
#include <type_traits>

struct A {
	int f() ;
};

template <typename >
struct PM_Traits{
};

template <typename T, typename U>
struct PM_Traits<U T::*> {
	using member_type = U;
};

int main()
{
	using T = PM_Traits<decltype(&A::f)>::member_type;

	std::cout<<std::boolalpha
			<<std::is_function<A>::value<<"\n"
			<<std::is_function<int()>::value<<"\n"
			<<std::is_function<decltype(&A::f)>::value<<"\n"
			<<std::is_function<T>::value<<"\n";

	return 0;
}

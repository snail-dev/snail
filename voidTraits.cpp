#include <iostream>
#include <type_traits>

int main() {

	std::cout<<std::boolalpha
			<<std::is_void<void>::value<<"\n"
			<<std::is_void<int>::value<<"\n"
			<<std::is_void<void *>::value<<"\n"
			<<std::is_void<const void>::value<<"\n"
			<<std::is_void<volatile void>::value<<"\n"
			<<std::is_void<const volatile void>::value<<"\n";

	return 0;
}

#include <iostream>
#include <array>
#include <string>
#include <type_traits>

struct A {};

int main() {
	std::cout<<std::boolalpha;
	std::cout<<std::is_array<int>::value<<"\n"
			<<std::is_array<int[]>::value<<"\n"
			<<std::is_array<A>::value<<"\n"
			<<std::is_array<A[5]>::value<<"\n"
			<<std::is_array<std::string>::value<<"\n"
			<<std::is_array<std::string[]>::value<<"\n"
			<<std::is_array<std::array<int,5>>::value<<"\n";

	return 0;
}

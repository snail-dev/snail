#include <iostream>
#include <type_traits>

struct A {};
struct B{
	B() {
		fb =0.0;
	}
	float fb;
};


int main() {
	
	std::cout<<std::boolalpha
			<<std::is_floating_point<int>::value<<"\n"
			<<std::is_floating_point<double>::value<<"\n"
			<<std::is_floating_point<long double>::value<<"\n"
			<<std::is_floating_point<float>::value<<"\n"
			<<std::is_floating_point<A>::value<<"\n"
			<<std::is_floating_point<B>::value<<"\n";

	return 0;
}

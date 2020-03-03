#include <iostream>
#include <type_traits>

int main()
{
	std::cout<<std::boolalpha
		<<std::is_integral<int>::value<<"\n"
		<<std::is_integral<double>::value<<"\n";

	return 0;
}

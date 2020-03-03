#include <iostream>
#include <type_traits>

int main() {

	std::cout<<std::boolalpha
		<<"is_reference:\n"
		<<std::is_reference<int>::value<<"\n"
		<<std::is_reference<int&>::value<<"\n"
		<<std::is_reference<int&&>::value<<"\n"
		<<"is_lvalue_reference:\n"
		<<std::is_lvalue_reference<int>::value<<"\n"
		<<std::is_lvalue_reference<int&>::value<<"\n"
		<<std::is_lvalue_reference<int&&>::value<<"\n"
		<<"is_rvalue_reference:\n"
		<<std::is_rvalue_reference<int>::value<<"\n"
		<<std::is_rvalue_reference<int&>::value<<"\n"
		<<std::is_rvalue_reference<int&&>::value<<"\n";
	return 0;
}

#include <iostream>
#include <type_traits>

struct A {int x; int y;};
struct B {int x; int y;};

typedef A C;


int main() {
	
	std::cout<<std::boolalpha
		<<std::is_same<int,int32_t>::value<<"\n"
		<<std::is_same<int,int64_t>::value<<"\n"
		<<std::is_same<int, const int>::value<<"\n"
		<<std::is_same<int,volatile int>::value<<"\n"
		<<std::is_same<A,B>::value<<"\n"
		<<std::is_same<A,C>::value<<"\n"
		<<std::is_same<char,int8_t>::value<<"\n"
		<<std::is_same<char,uint8_t>::value<<"\n"
		<<std::is_same<char,signed char>::value<<"\n"
		<<std::is_same<char,unsigned char>::value<<"\n";

	return 0;
}

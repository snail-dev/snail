#include <iostream>
#include <type_traits>

struct A{};
class B{};

enum Alphabet{ a, b, c};
enum class C : int {};

union D{int i; float f;};


int main() {
	
	std::cout<<std::boolalpha
			<<std::is_class<int>::value<<"\n"
			<<std::is_union<int>::value<<"\n"
			<<std::is_enum<int>::value<<"\n"
			<<std::is_class<A>::value<<"\n"
			<<std::is_class<B>::value<<"\n"
			<<std::is_enum<Alphabet>::value<<"\n"
			<<std::is_enum<C>::value<<"\n"
			<<std::is_union<D>::value<<"\n"
			<<std::is_enum<decltype(Alphabet::a)>::value<<"\n";

	return 0;
}

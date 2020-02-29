#include <iostream>
#include <type_traits>

typedef struct {}A,*pA;

struct B {
	static int isb;
	int ib;

	static void sf(){}
	void f(){}
};

int B::isb = 0;

int main() {
	
	static int a = 5;
	int* pa = &a;
	
	B b;

	int B::*pBa = &B::ib;
	int *pBsa = &(B::isb);

	void(B::*pBf)() = &B::f;
	void(*pBsf)() = &B::sf;



	std::cout<<std::boolalpha
			<<"is_pointer<>:\n"
			<<std::is_pointer<void*>::value<<"\n"
			<<std::is_pointer<A*>::value<<"\n"
			<<std::is_pointer<pA>::value<<"\n"
			<<std::is_pointer<decltype(pa)>::value<<"\n"
			<<std::is_pointer<decltype(pBa)>::value<<"\n"
			<<std::is_pointer<decltype(pBsa)>::value<<"\n"
			<<std::is_pointer<decltype(pBf)>::value<<"\n"
			<<std::is_pointer<decltype(pBsf)>::value<<"\n"
			<<std::is_pointer<std::nullptr_t>::value<<"\n";

	std::cout<<std::boolalpha
			<<"is_member_pointer<>:\n"
			<<std::is_member_pointer<void*>::value<<"\n"
			<<std::is_member_pointer<A*>::value<<"\n"
			<<std::is_member_pointer<pA>::value<<"\n"
			<<std::is_member_pointer<decltype(pa)>::value<<"\n"
			<<std::is_member_pointer<decltype(pBa)>::value<<"\n"
			<<std::is_member_pointer<decltype(pBsa)>::value<<"\n"
			<<std::is_member_pointer<decltype(pBf)>::value<<"\n"
			<<std::is_member_pointer<decltype(pBsf)>::value<<"\n"
			<<std::is_member_pointer<std::nullptr_t>::value<<"\n";

	std::cout<<std::boolalpha
			<<"is_member_object_pointer<>:\n"
			<<std::is_member_object_pointer<void*>::value<<"\n"
			<<std::is_member_object_pointer<A*>::value<<"\n"
			<<std::is_member_object_pointer<pA>::value<<"\n"
			<<std::is_member_object_pointer<decltype(pa)>::value<<"\n"
			<<std::is_member_object_pointer<decltype(pBa)>::value<<"\n"
			<<std::is_member_object_pointer<decltype(pBsa)>::value<<"\n"
			<<std::is_member_object_pointer<decltype(pBf)>::value<<"\n"
			<<std::is_member_object_pointer<decltype(pBsf)>::value<<"\n"
			<<std::is_member_object_pointer<std::nullptr_t>::value<<"\n";

	std::cout<<std::boolalpha
			<<"is_member_function_pointer<>:\n"
			<<std::is_member_function_pointer<void*>::value<<"\n"
			<<std::is_member_function_pointer<A*>::value<<"\n"
			<<std::is_member_function_pointer<pA>::value<<"\n"
			<<std::is_member_function_pointer<decltype(pa)>::value<<"\n"
			<<std::is_member_function_pointer<decltype(pBa)>::value<<"\n"
			<<std::is_member_function_pointer<decltype(pBsa)>::value<<"\n"
			<<std::is_member_function_pointer<decltype(pBf)>::value<<"\n"
			<<std::is_member_function_pointer<decltype(pBsf)>::value<<"\n"
			<<std::is_member_function_pointer<std::nullptr_t>::value<<"\n";
	return 0;
}

#include <iostream>
#include <type_traits>

struct A {};
struct B : A {};

struct C {};
struct D { operator C() {return c;} C c;};

struct E { template <class T> E(T&&);};


int main() {

	std::cout<<std::boolalpha
			<<std::is_convertible<int,float>::value<<"\n"     // true
			<<std::is_convertible<int,const int>::value<<"\n" // true  
			<<std::is_convertible<int,const volatile int>::value<<"\n" // true
			<<std::is_convertible<int*, void*>::value<<"\n"    // true
			<<std::is_convertible<int*, float*>::value<<"\n"   // false
			<<std::is_convertible<A,B>::value<<"\n"            // false
			<<std::is_convertible<B,A>::value<<"\n"            // true
			<<std::is_convertible<A*,B*>::value<<"\n"           // false
			<<std::is_convertible<B*,A*>::value<<"\n"          // true
			<<std::is_convertible<C,D>::value<<"\n"            // false
			<<std::is_convertible<D,C>::value<<"\n"            // true
			<<std::is_convertible<D*,C*>::value<<"\n";         // false  
			
	std::cout<<std::is_convertible<A,E>::value<<"\n"                // true      
			<<std::is_convertible<E,A>::value<<"\n";                // false
	

	return 0;
}

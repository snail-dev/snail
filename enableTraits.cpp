#include <iostream>
#include <type_traits>

template <class T>
typename std::enable_if<std::is_integral<T>::value,
						bool>::type
is_odd(T i) { return i%2;}


template <class T,
		class = typename std::enable_if<std::is_integral<T>::value,
										bool>::type >
bool is_even(T i) { return !(i%2); }


int main(){

	int i = 5;
	float f = 5.0;

	std::cout<<std::boolalpha
			<<is_odd(i)<<"\n"
			<<is_even(i)<<"\n";
	
//	std::cout<<std::boolalpha
//			<<is_odd(f)<<"\n"
//			<<is_even(f)<<"\n";
	return 0;
}

#include <iostream>
#include <type_traits>

enum class my_type {
	t1,
	t2,
};

using my_type_t1 = std::integral_constant<my_type, my_type::t1> ;
using my_type_t2 = std::integral_constant<my_type, my_type::t2> ;

static_assert(!std::is_same<my_type_t1,my_type_t2>::value,"t1 == t2");

int main() {
	std::cout<<"compile done\n";
	return 0;
}

#include <iostream>
#include <utility>

struct A {
	virtual int value() = 0;
};

struct B : A {
	int _val;

	B(int i, int j) : _val(i*j) {}

	int value() {return _val;}
};

struct Default {
	int foo() {return 10;} 
};

struct NoDefault {
	NoDefault() = delete;
	int foo() {return 20;}
};

int main() {
	
	decltype(std::declval<A>().value()) a;
	decltype(std::declval<B>().value()) b;  // declval<B>()实际并不会调用B的构造，这里只是unevaluated contexts
	//decltype(std::declval<B>(1,2).value()) c; 这里是不能够在declval中使用参数的
	decltype(B(1,2).value()) d;

	a = b = d = B(10,2).value();
	std::cout<<a<<", "<<b<<", "<<d<<"\n";

	decltype(Default().foo()) e = 100;
	decltype(std::declval<NoDefault>().foo()) f = 200;

	std::cout<<e<<", "<<f<<"\n";

	return 0;
}

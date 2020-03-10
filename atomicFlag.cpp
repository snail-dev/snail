#include <iostream>
#include <atomic>
#include <sstream>
#include <vector>
#include <thread>

std::atomic_flag lock_stream = ATOMIC_FLAG_INIT;
std::stringstream stream;

void append_number(int i) {
	while(lock_stream.test_and_set()){}
	stream << "thread #"<<i<<"\n";
	lock_stream.clear();
}


int main() 
{
	
	std::vector<std::thread> threads;
	for(int i = 1; i <= 10; i ++) threads.push_back(std::thread(append_number,i));

	for(auto &th : threads) th.join();

	std::cout<<stream.str();
	return 0;
}

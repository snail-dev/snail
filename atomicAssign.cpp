#include <atomic>
#include <thread>
#include <iostream>

#if defined (_MSC_VER_)
std::atomic<int> flag = 0;
#elif defined (__GNUC__)
std::atomic<int> flag (0);
#endif


void set_flag(int i) {
	flag = i;
}

void wait_flag() {
	while(flag == 0) std::this_thread::yield();
	std::cout<<"flag = "<<flag<<std::endl;
}

int main() {

	std::thread first_th(wait_flag);
	std::thread second_th(set_flag,5);

	first_th.join();
	second_th.join();
	
	return 0;
}

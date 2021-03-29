#include <iostream>
#include <numbers>
#include <chrono>
#include "helper.h"

int main()
{	
	size_t n = 100000000;

	size_t t = 0;
	auto t1 = std::chrono::high_resolution_clock::now();
	for (size_t i = 0; i < n; i++)
	{
		t += std::sqrt(9);
	}
	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << std::endl;
	
	return t;
}


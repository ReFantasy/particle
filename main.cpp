#include <iostream>
#include "helper.h"
int main()
{
	const int nrolls = 10000;  // number of experiments
	const int nstars = 100;    // maximum number of stars to distribute


	int p[10] = {};

	for (int i = 0; i < nrolls; ++i) 
	{
		//double number = Gaussian(5.0,2.0);
		double number = Random();
		if ((number >= 0.0) && (number < 10.0)) ++p[int(number)];
	}

	std::cout << "normal_distribution (5.0,2.0):" << std::endl;

	for (int i = 0; i < 10; ++i) 
	{
		std::cout << i << "-" << (i + 1) << ": ";
		std::cout << std::string(p[i] * nstars / nrolls, '*') << std::endl;
	}

	return 0;
}


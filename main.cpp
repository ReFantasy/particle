#include <iostream>
#include <numbers>
#include "helper.h"

int main()
{
	//const int nrolls = 10000;  // number of experiments
	//const int nstars = 100;    // maximum number of stars to distribute

	//std::default_random_engine generator;
	//std::normal_distribution<double> distribution(5.0, 2.0);

	//int p[10] = {};

	//for (int i = 0; i < nrolls; ++i) {
	//	//double number = distribution(generator);
	//	double number = Gaussian(5.0,2.0);
	//	if ((number >= 0.0) && (number < 10.0)) ++p[int(number)];
	//}

	//std::cout << "normal_distribution (5.0,2.0):" << std::endl;

	//for (int i = 0; i < 10; ++i) {
	//	std::cout << i << "-" << (i + 1) << ": ";
	//	std::cout << std::string(p[i] * nstars / nrolls, '*') << std::endl;
	//}

	
	Eigen::Vector3f c(1, 1, 1);
	Eigen::Vector3f p(2, 4, 7);

	Eigen::Vector3f n = p - c;

	Eigen::Vector3f x = Cu(c,n, 1);
	
	printf("%.2f\n", (x - c).dot(n));
	//std::cout << (x-c).dot(n) << std::endl;
	std::cout << (x - c).norm() << std::endl;
	
	return 0;
}


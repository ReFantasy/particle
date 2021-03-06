#ifndef __HELPER_H__
#define __HELPER_H__

#include <random>
#include "Eigen/Dense"

template<typename T = double>
T Random()
{
	std::random_device device;
	std::mt19937_64 rng(device());
	return rng();
}

template<typename T = double>
T Uniform(const T& u_min = T(0), const T& u_max = T(1))
{
	std::random_device device;
	std::mt19937_64 eng(device());
	std::uniform_real_distribution<T> dist(u_min, u_max);
	return dist(eng);
}

template<typename T = double>
T Gaussian(const T& mean = T(0), const T& stddev = T(1))
{
	std::random_device device;
	std::mt19937_64 eng(device());
	std::normal_distribution<T> dist(mean, stddev);
	return dist(eng);
}

// pointing in an arbitrary direction across a sphere
Eigen::Vector3f S();

Eigen::Vector3f Du(Eigen::Vector3f w, float radian);

Eigen::Vector3f Cu(Eigen::Vector3f c, Eigen::Vector3f n, float R);

#endif//__HELPER_H__
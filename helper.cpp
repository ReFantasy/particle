#include "helper.h"
#include <iostream>
#include <numbers>

Eigen::Vector3f S()
{
	double theta = Uniform(-std::numbers::pi, std::numbers::pi);
	double y = Uniform(-1.0, 1.0);
	double r = std::sqrt(1.0 - y * y);

	return Eigen::Vector3f(r * std::cos(theta), y, -r * std::sin(theta));
}

Eigen::Vector3f Du(Eigen::Vector3f w, float radian)
{
	w = w / w.norm();
	Eigen::Vector3f a = w;
	a(0) = a(0) + 1.0;

	Eigen::Vector3f uz = w;
	
	Eigen::Vector3f ux = a.cross(uz);
	ux = ux / ux.norm();

	Eigen::Vector3f uy = uz.cross(ux);

	Eigen::Matrix3f M;
	M << ux, uy, uz;

	float f = Uniform(0.0f, 1.0f);
	float phi = std::sqrt(f) * radian;
	double theta = Uniform(-std::numbers::pi, std::numbers::pi);
	Eigen::Vector3f v_(std::cos(theta)*std::sin(phi),
		std::sin(theta) * std::sin(phi),
		std::cos(phi));

	Eigen::Vector3f v = M * v_;
	return v;
}

Eigen::Vector3f Cu(Eigen::Vector3f c, Eigen::Vector3f n, float R)
{
	Eigen::Vector3f w = n / n.norm();
	Eigen::Vector3f a = w;
	a(0) = a(0) + 1.0;

	Eigen::Vector3f uz = w;

	Eigen::Vector3f ux = a.cross(uz);
	ux = ux / ux.norm();

	Eigen::Vector3f uy = uz.cross(ux);

	Eigen::Matrix3f M;
	M << ux, uy, uz;

	float f = Uniform(0.0f, 1.0f);
	//float f = std::abs(Gaussian<double>(0.0, R / 3.0));

	float r = std::sqrt(f)*R;
	float theta = Uniform(-std::numbers::pi, std::numbers::pi);
	Eigen::Vector3f p(r * std::cos(theta), r * std::sin(theta), 0);

	return c + M * p;
}

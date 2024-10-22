#ifndef PERLINNOISE_HPP
#define PERLINNOISE_HPP

#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <numeric>

class PerlinNoise {
public:
	PerlinNoise();
	PerlinNoise(unsigned int seed);

	double sample(double x, double y);
	float sample(float x, float y);
private:

	std::vector<int> p;
	unsigned int _seed;

	double fade(double t);
	float fade(float t);

	double lerp(double t, double a, double b);
	float lerp(float t, float a, float b);

	double grad(int hash, double x, double y, double z);
	float grad(int hash, float x, float y, float z);
};

#endif
#include "random.h"

RandomNumbers::RandomNumbers(unsigned long int s)
:seed(s)
{
	if(seed == 0){
		std::random_device rd;
		seed = rd();
	}
	rng = std::mt19937(seed);
}

void RandomNumbers::uniform_double(std::vector<double>& numbers, double lower, double upper)
{
    for (auto I = numbers.begin(); I != numbers.end(); I++) *I = uniform_double(lower, upper);
}
double RandomNumbers::uniform_double(double lower, double upper)
{
	std::uniform_real_distribution<> uniform(lower, upper);
	return uniform(rng);
	
}
void RandomNumbers::normal(std::vector<double>& numbers, double mean, double sd)
{
    for (auto I = numbers.begin(); I != numbers.end(); I++) *I = normal(mean, sd);
}
double RandomNumbers::normal(double mean, double sd)
{
	std::normal_distribution<> normal(mean, sd);
	return normal(rng);
}
void RandomNumbers::poisson(std::vector<int>& numbers, double mean)
{
	for (auto I = numbers.begin(); I != numbers.end(); I++) *I = poisson(mean);
}
int RandomNumbers::poisson(double mean)
{
	std::poisson_distribution<int> pois(mean);
	return pois(rng);
}


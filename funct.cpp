#include "header.h"


double f(double x) {
	return pow(2, x) * (x - 1) * (x - 1) - 2;
}

double fdif(double x) {
	return log(2)* pow(2, x) * (x-1)* (x-1) + pow(2, x+1) * (x-1);
}

double fdif2(double x) {
	return (pow(log(2), 2) * pow(x, 2) + (4 * log(2) - 2 * pow(log(2), 2)) * x + pow(log(2), 2) - 4 * log(2) + 2) * pow(2, x);
}


std::vector<double> uniform_grid(double a, double b, int n) {
	std::vector<double> x(n+1);
		for (int i = 0; i <= n; ++i) {
			x[i] = a + ((b - a) / n) * i;
		}

	return x;
}
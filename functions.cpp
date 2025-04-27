#include "header.h"

double f(double x, double y) {
	return 2*x *(x*x+y);
}

double f_solution(double x) {
	return exp(x * x) - x * x - 1;
}

std::vector <double> grid(int n) { 
	std::vector <double> x(n+1);
	x[0] = 1.0;
	for (int i = 1; i < x.size(); i++) {
		x[i] = x[i - 1] + 1.0/(double)n;
	}
	return x;
}
#include "header.h"

std::vector<double> find_const_1(std::vector<double>& y, double grid_step, std::vector<double>& M, int n) {
	std::vector<double> C(n);

	for (int i = 0; i < n; ++i) {
		C[i] = ((y[i + 1] - y[i]) / grid_step) - (grid_step / 6.0) * (M[i + 1] - M[i]);
		
	}
	return C;
}


std::vector<double> find_const_2(std::vector<double>& y, double grid_step, std::vector<double>& M, int n) {
	std::vector<double> C_2(n);
	for (int i = 0; i < n; ++i) {
		C_2[i] = y[i] - M[i]*(pow(grid_step, 2)/6.0);
		
	}
	return C_2;
}
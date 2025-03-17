#include "header.h"

std::vector<double> Thomas_algorithm(std::vector<double>& y, double grid_step, int n, double a, double b) {
	std::vector<double> M(n+1), free_terms(n-1), p(n-1), q(n);
	
	double c = 0.5, d = 2.0;
	M[0] = fdif2(a); M[n] = fdif2(b);

	p[0] = -c /d;

	for (int i = 1; i <= n-1; ++i) {
		free_terms[i - 1] = (3.0 / pow(grid_step, 2)) * (y[i+1] - 2.0 * y[i] + y[i - 1]); 
	}
	
	free_terms[0] = free_terms[0]- c * M[0];
	q[0] = free_terms[0] / d;

	free_terms[n - 2] = free_terms[n - 2] - c * M[n];
	for (int i = 1; i <= n-3 ; ++i) {
		p[i] = -c / (d + c * p[i - 1]);
		q[i] = (free_terms[i] - c * q[i - 1]) / (d + c * p[i - 1]);
	}

	q[n - 2] = (free_terms[n - 2] - c * q[n - 3]) / (d + c * p[n - 3]);
	M[n-1] = q[n - 2];

	for (int i = n - 2; i >= 1 ; --i) {
		M[i] = p[i - 1] * M[i + 1] + q[i - 1];
	}
	for (int i = 0; i <= n-1; ++i) {
		std::cout << i << " = " << q[i] << std::endl;
	}
	return M;
}

std::vector<double> Thomas_algorithm_df_change(std::vector<double>& y, double grid_step, int n, double dif2_change, double b) {
	std::vector<double> M(n + 1), free_terms(n - 1), p(n - 1), q(n);

	double c = 0.5, d = 2.0;
	M[0] = dif2_change; M[n] = fdif2(b);

	p[0] = -c / d;

	for (int i = 1; i <= n - 1; ++i) {
		free_terms[i - 1] = (3.0 / pow(grid_step, 2)) * (y[i + 1] - 2.0 * y[i] + y[i - 1]);
	}

	free_terms[0] = free_terms[0] - c * M[0];
	q[0] = free_terms[0] / d;

	free_terms[n - 2] = free_terms[n - 2] - c * M[n];
	for (int i = 1; i <= n - 3; ++i) {
		p[i] = -c / (d + c * p[i - 1]);
		q[i] = (free_terms[i] - c * q[i - 1]) / (d + c * p[i - 1]);
	}

	q[n - 2] = (free_terms[n - 2] - c * q[n - 3]) / (d + c * p[n - 3]);
	M[n - 1] = q[n - 2];

	for (int i = n - 2; i >= 1; --i) {
		M[i] = p[i - 1] * M[i + 1] + q[i - 1];
		
	}
	return M;
}


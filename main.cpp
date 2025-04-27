#include "header.h"

int main() {
	double x0 = 1.0, y0, cheb_norm1, cheb_norm2;
	double y_initial = f_solution(x0);
	int n1 = 5, n2 = 10;
	std::vector<double> y, y_exact, fact_err, x, y1, y2, x1, x2, y_exact1(n1 + 1), y_exact2(n2 + 1), error1(n1 + 1), error2(n2 + 1);
	std::ofstream sol_file("solutions.txt"), err_file("errors.txt"), sol_file2("solutions2.txt"), err_file2("errors2.txt");

	y1 = Euler_Cauchy_Method(y_initial, n1); y2 = Euler_Cauchy_Method(y_initial, n2);
	x1 = grid(n1); x2 = grid(n2);

	for (int i = 0; i <= n1; ++i) {
		y_exact1[i] = f_solution(x1[i]);
		error1[i] = fabs(y1[i] - y_exact1[i]);
		sol_file << x1[i] << "\t" << y1[i] << "\t" << std::endl;
		err_file << x1[i] << " \t " << error1[i] << " \t " << std::endl;
	}

	for (int i = 0; i <= n2; ++i) {
		y_exact2[i] = f_solution(x2[i]);
		error2[i] = fabs(y2[i] - y_exact2[i]);
		sol_file2 << x2[i] << "\t" << y2[i] << "\t" << std::endl;
		err_file2 << x2[i] << " \t " << error2[i] << " \t " << std::endl;
	}

	cheb_norm1 = *std::max_element(error1.begin(), error1.end());
	cheb_norm2 = *std::max_element(error2.begin(), error2.end());
	sol_file.close();  err_file.close(); sol_file2.close(); err_file2.close();

	int N = 10; 
	std::vector<double> x10(N + 1), y_exact10(N + 1), y_num(N + 1), y_num2(N + 1);
	std::ofstream eps_iter_file("eps_iter_data.txt");

	x10 = grid(N);
	for (int i = 0; i <= N; ++i) {
		y_exact10[i] = f_solution(x10[i]);
	}

	for (double eps = 0.1; eps > 1e-11; eps *= 0.1) {
		double actual_error = 10.0, runge = 10.0;
		int iter = 0, n = 2;

		while (runge > eps) {
			for (int i = 0; i < N; ++i) {
				double y_start = (i == 0) ? y_exact10[i] : y_num[i];
				y_num[i + 1] = Euler_Cauchy_Method2(y_start, n, x10[i], x10[i + 1]);
				y_num2[i + 1] = Euler_Cauchy_Method2(y_start, 2 * n, x10[i], x10[i + 1]);
			}
			runge = fabs(y_num2[10] - y_num[10]) / 3.0;
			n *= 2;
		}
		actual_error = fabs(y_num2[10] - y_exact10[10]);	
		iter++;
		n *= 2;
		eps_iter_file << eps << "\t" << log2(n) << "\t" << actual_error << "\t" << n << "\n";
	}
	eps_iter_file.close();

	return 0;
}

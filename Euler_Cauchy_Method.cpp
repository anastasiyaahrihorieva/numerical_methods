#include "header.h"

std::vector<double> Euler_Cauchy_Method(double y0, int n) {
	std::vector<double> y(n+1), x(n+1), y_euler(n+1);
	x = grid(n); y_euler[0] = y0; y[0] = y0;
	for (int i = 1; i < n + 1; ++i) {
		double y_euler = y[i - 1] + f(x[i - 1], y[i - 1])/(double)n;
		y[i] = y[i - 1] + 0.5 * (f(x[i - 1], y[i - 1]) + f(x[i], y_euler))/double(n);
	}
	return y;
}

double Euler_Cauchy_Method2(double y0, int n, double a, double b) {
	double h = (b - a) / n;
	double y = y0;

	for (int i = 0; i < n; ++i) {
		double x = a + i * h;
		double k1 = f(x, y);
		double k2 = f(x + h, y + h * k1);
		y = y + h * 0.5 * (k1 + k2);
	}

	return y;
}
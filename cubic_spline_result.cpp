#include "header.h"

std::vector<double> Cubic_spline_result (double a, double b, int n) {
	std::vector<double> x_nodes, y_nodes, M, C_2, C_1, x_point, Spline_points;
	double grid_step;
	grid_step = (b - a) / n;
	x_nodes = uniform_grid(a, b, n);
	y_nodes.resize(n + 1);
	for (size_t i = 0; i <= n; i++) {
		y_nodes[i] = f(x_nodes[i]);
	}
	M = Thomas_algorithm(y_nodes, grid_step, n, a, b);
	C_2 = find_const_2(y_nodes, grid_step, M, n);
	C_1 = find_const_1(y_nodes, grid_step, M, n);
	x_point = uniform_grid(a, b, n * 50);
	Spline_points = Spline(x_point, M, grid_step, C_1, C_2, a, n, x_nodes);

	return Spline_points;
}
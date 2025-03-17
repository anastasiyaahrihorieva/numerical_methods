#include "header.h"

std::vector<double> Spline(const std::vector<double>& x_point, const std::vector<double>& M, double grid_step, const std::vector<double>& C_1, const std::vector<double>& C_2, double a, int n, const std::vector<double>& x_nodes) {
    std::vector<double> spline_values(x_point.size());
    double x, A, B;
    int sectn;
    for (size_t i = 0; i < x_point.size(); ++i) {
        x = x_point[i];
        sectn = static_cast<int>((x - a) / grid_step);
        sectn = std::min(sectn, n - 1); sectn = std::max(sectn, 0);
        A = (x_nodes[sectn + 1] - x);
        B = (x - x_nodes[sectn]);
        spline_values[i] = M[sectn] * (pow(A, 3) / (6.0 * grid_step)) + M[sectn + 1] * (pow(B, 3) / (6.0 * grid_step)) + C_1[sectn] * B + C_2[sectn];
    }
    return spline_values;
}
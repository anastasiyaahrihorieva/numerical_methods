#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

double fdif2(double x);
double fdif(double x);
double f(double x);

std::vector<double> uniform_grid(double a, double b, int n);
std::vector<double> Thomas_algorithm(std::vector<double>& y, double grid_step, int n, double a, double b);
std::vector<double> find_const_1(std::vector<double>& y, double grid_step, std::vector<double>& M, int n);
std::vector<double> find_const_2(std::vector<double>& y, double grid_step, std::vector<double>& M, int n);
std::vector<double> Spline(const std::vector<double>& x_point, const std::vector<double>& M, double grid_step, const std::vector<double>& C_1, const std::vector<double>& C_2, double a, int n, const std::vector<double>& x_nodes);
std::vector<double> Thomas_algorithm_df_change(std::vector<double>& y, double grid_step, int n, double  dif2_change, double b);
std::vector<double> Cubic_spline_result(double a, double b, int n);
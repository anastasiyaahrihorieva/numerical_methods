#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

double f(double x, double y);
double f_solution(double x);
double Euler_Cauchy_Method2(double y0, int n, double a, double b);
std::vector<double> grid(int n);
std::vector<double> Euler_Cauchy_Method(double y0, int n);
#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <iomanip>

double f(double x);
double Leibniz_Newton_calc(double a, double b);
double Simpsons_rule(double a, double b, int partitions_amount);
double Simpsons_rule_2(double a, double b, double length);
//double Simpsons_rule_optimized(double a, double b, int& prev_partitions, double& prev_step);
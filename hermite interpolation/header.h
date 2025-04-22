#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream> 
#define PI 3.14159265358979323846



double f(double x);
double fdif(double x);
std::vector<double> cheb(int n, double a, double b);
double hermite(const std::vector<double>& x, const std::vector<double>& y, double xx, int n);
void saveToFile(const std::string& filename, const std::string& data);
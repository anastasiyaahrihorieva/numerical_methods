#include "header.h"

double Leibniz_Newton_calc(double a, double b) {
	return ((pow(b, 6) / 6.0) - 1.8 * pow(b, 4) + (17.0 / 6.0) * pow(b, 3) - 3.5 * pow(b, 2) - 4.5 * b - ((pow(a, 6) / 6.0) - 1.8 * pow(a, 4) + (17.0 / 6.0) * pow(a, 3) - 3.5 * pow(a, 2) - 4.5 * a));
}
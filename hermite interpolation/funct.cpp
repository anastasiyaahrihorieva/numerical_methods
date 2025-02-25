#include "header.h"

double f(double x) {
	return pow(2, x) * (x - 1) * (x - 1) - 2;
}

double fdif(double x) {
    return (x - 1) * pow(2, x) * 2 + log(2) * (x - 1) * (x - 1) * pow(2, x);
}


std::vector<double> cheb(int n, double a, double b) {
    std::vector<double> root(n+1);
    for (int k = 0; k <= n; ++k) {
        double t = std::cos((PI * (2 * k + 1)) / (2 * (n + 1)));
        root[k] = ((a + b) / 2) + ((b - a) / 2) * t;
        
    }
      
    return root;
}


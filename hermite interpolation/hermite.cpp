#include "header.h"

double hermite(const std::vector<double>& x, const std::vector<double>& y, double xx, int n) {
    double result = 0;
    for (int j = 0; j <= n; ++j) {
        double h = 0;
        double k = 1; 
        for (int i = 0; i <= n; ++i) {
            if (i != j) {
                h += (xx - x[j]) / (x[j] - x[i]); 
                k *= (xx - x[i]) / (x[j] - x[i]);
            }
        }

        result += (fdif(x[j]) * (xx - x[j]) + (1 - 2 * h) * y[j]) * pow(k, 2);
        //std::cout << std::setprecision(12)<< result<<std::endl;

    }
    return result;
}
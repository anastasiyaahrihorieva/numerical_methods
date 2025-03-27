#include "header.h"

double Simpsons_rule(double a, double b, int partitions_amount) {
	int n = partitions_amount * 2;
	double step = (b - a) / (double)n;
	double integral_value = 0;
	std::vector<double> f_values(n + 1);

	for (int i = 0; i <= n; ++i) {
		f_values[i] = f(a + i * step);
	}

	for (int i = 0; i < n; i += 2) {
		integral_value += (step / 3.0) * (f_values[i] + 4 * f_values[i + 1] + f_values[i + 2]);
	}

	return integral_value;
}

double Simpsons_rule_2(double a, double b, double length) {
	int n1 = static_cast<int>((b - a) / length);
	double integral = 0;

	std::vector<double> f_values(n1 + 2);

	for (int i = 0; i <= n1 + 1; ++i) {
		f_values[i] = f(a + i * length);
	}

	for (int i = 0; i < n1; i += 2) {
		integral += (length / 3.0) * (f_values[i] + 4 * f_values[i + 1] + f_values[i + 2]);
	}

	return integral;
}
//
//double Simpsons_rule_optimized(double a, double b, int& prev_partitions, double& prev_step) {
//	static std::vector<double> cached_values;
//	int new_partitions = (prev_partitions == 0) ? 2 : prev_partitions * 2;
//	double step = (b - a) / new_partitions;
//
//	// Вычисляем только новые точки
//	if (prev_partitions > 0) {
//		for (int i = 1; i < new_partitions; i += 2) {
//			double x = a + i * step;
//			f(x);  // Значение закэшируется
//		}
//	}
//	else {
//		cached_values.reserve(new_partitions + 1);
//		for (int i = 0; i <= new_partitions; ++i) {
//			double x = a + i * step;
//			cached_values.push_back(f(x));
//		}
//	}
//}


	//double Simpsons_rule(double a, double b, int partitions_amount) {
	//    int n; double step, integral_value=0;
	//    n = partitions_amount * 2; 
	//    step = (b - a) / (double)n;
	//    for (int i = 0; i < n; i += 2) {
	//        double x0, x1, x2;
	//        x0 = a + i * step;
	//        x1 = x0 + step;
	//        x2 = x0 + 2 * step;
	//        integral_value += (step / 3.0) * (f(x0) + 4 * f(x1) + f(x2));
	//    }
	//    return integral_value;
	//}
	//
	//
	//double Simpsons_rule_2(double a, double b, double length) {
	//    int n = 16; double integral = 0; 
	//    int n1 = (int)((b - a) / length);
	//    //std::cout << "n1 = " << n1 << std::endl;
	//    for (int i = 0; i < n1; i += 2) {
	//        double x0, x1, x2;
	//        x0 = a + i * length;
	//        x1 = x0 + length;
	//        x2 = x0 + 2 * length;
	//        integral += (length / 3.0) * (f(x0) + 4 * f(x1) + f(x2));
	//    }
	//
	//    return integral;
	//}

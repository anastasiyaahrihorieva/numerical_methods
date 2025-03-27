#include "header.h"
#include <map>

int function_calls = 0;
std::map<double, double> values;
//double f(double x) {
//    if (values.find(x) != values.end()) {
//        return values[x];
//    }
//    function_calls++;
//    double result = pow(x, 5) - 7.2 * pow(x, 3) + 8.5 * pow(x, 2) - 7 * x - 4.5;
//    values[x] = result;
//    return result;
//}
double f(double x) {

    constexpr long long multiplier = 1e12;
    long long key = static_cast<long long>(std::round(x * multiplier));

    auto it = values.find(key);
    if (it != values.end()) {
        return it->second;
    }

    function_calls++;
    double result = pow(x, 5) - 7.2 * pow(x, 3) + 8.5 * pow(x, 2) - 7 * x - 4.5;
    values[key] = result;
    return result;
}
//
//int main() {
//    std::ofstream part_err_file_3("step_err.txt"),
//        eps_runge("eps_runge.txt"),
//        part_err_file("5v.txt");
//
//    const double a = -3.4, b = 1.1;
//    const double LN_intgrl_value = Leibniz_Newton_calc(a, b);
//    std::cout << LN_intgrl_value;
//    // јдаптивное вычисление интеграла
//    int partitions = 0;
//    double step = 0;
//    double prev_result = Simpsons_rule_optimized(a, b, partitions, step);
//
//    for (double ep = 0.1; ep >= 1e-12; ep /= 10) {
//        double curr_result = Simpsons_rule_optimized(a, b, partitions, step);
//
//        while (ep <= fabs(prev_result - curr_result) / 15.0) {
//            prev_result = curr_result;
//            curr_result = Simpsons_rule_optimized(a, b, partitions, step);
//        }
//
//        eps_runge << std::scientific << fabs(curr_result - LN_intgrl_value)
//            << " " << ep << " " << partitions << "\n";
//    }
//
//    // јнализ ошибки дл€ разных шагов
//    for (int parts = 2; parts <= 30; ++parts) {
//        double step_size = (b - a) / (2 * parts);
//        double result = Simpsons_rule_optimized(a, b, parts, step_size);
//        double error = LN_intgrl_value - result;
//        part_err_file_3 << step_size << " " << error << " " << pow(step_size, 3) << "\n";
//    }
//
//    // јнализ ошибки дл€ больших шагов
//    for (double step = 0.01; step <= 2.25; step += 0.05) {
//        int temp_partitions = 0;
//        double result = Simpsons_rule_optimized(a, b, temp_partitions, step);
//        double error = LN_intgrl_value - result;
//        part_err_file << step << " " << fabs(error) << " " << pow(step, 4) << "\n";
//    }
//
//    std::cout << "Total function calls: " << function_calls << "\n";
//    return 0;
//}
//
int main() {
    std::ofstream part_err_file_3("step_err.txt"), eps_runge("eps_runge.txt"), part_err_file("5v.txt");
    double a = -3.4, b = 1.1;
    double LN_intgrl_value = Leibniz_Newton_calc(a, b);
    //std::cout << LN_intgrl_value;
    int parts_amount = 1;
    double res1 = 0, res2;

    res2 = Simpsons_rule(a, b, parts_amount);

    for (double ep = 0.1; ep >= 1e-12; ep /= 10) {
        while (ep <= fabs(res1 - res2) / 15.0) {
            res1 = res2;
            parts_amount *= 2;
            res2 = Simpsons_rule(a, b, parts_amount);
        }

        eps_runge << fabs(res2 - LN_intgrl_value);
        eps_runge << " " << ep << " " << parts_amount << std::endl;
    }

    int parts = 2;
    double rslt, err = 0;

    do {
        double length = (b - a) / ((double)parts * 2.0);
        rslt = Simpsons_rule(a, b, parts);
        err = LN_intgrl_value - rslt;
        part_err_file_3 << length << " " << err << " " << pow(length, 3) << std::endl;
        parts += 1;
    } while (parts <= 30);

    double err2 = 0;
    double length1 = 0.01;
    int parts2 = 8;

    do {
        double rslt2 = Simpsons_rule_2(a, b, length1);
        err2 = LN_intgrl_value - rslt2;
        part_err_file << length1 << " " << fabs(err2) << " " << pow(length1, 4) << std::endl;

        length1 += 0.05;
    } while (length1 <= 2.25);

    std::cout << "function calls: " << function_calls << std::endl;

    return 0;
}

//27183 первый раз

//18239 второй раз вектор f_values, чтобы хранить значени€ функции дл€ каждого из узлов интегрировани€

//9340 третий раз ключ-значение дл€ повтор€ющихс€ значений x

// 
//
//int main() {
//	std::ofstream part_err_file_3("step_err.txt"), eps_runge("eps_runge.txt"), part_err_file("5v.txt");
//	double a = -3.4, b = 1.1;
//	double LN_intgrl_value = Leibniz_Newton_calc(a, b);
//	int parts_amount = 1;
//	double res1=0, res2;
//	res2 = Simpsons_rule(a, b, parts_amount);
//	for (double ep = 0.1; ep >= 1e-12; ep /= 10) {
//		
//		while (ep <= fabs(res1 - res2) / 15.0) {
//			res1 = res2;
//			parts_amount *= 2;
//			res2 = Simpsons_rule(a, b, parts_amount);
//		} ;
//
//		eps_runge << fabs(res2 - LN_intgrl_value);
//		eps_runge << " " << ep << " " << parts_amount << std::endl;
//
//	}
//
//	int parts = 2;
//	double rslt, err = 0;
//	do {
//		double length;
//		length = (b - a) / ((double)parts * 2.0);
//		rslt = Simpsons_rule(a, b, parts);
//		err = LN_intgrl_value - rslt;
//		part_err_file_3 << length << " " << err << " " << pow(length, 3) << std::endl;
//		parts += 1;
//
//	} while (parts <= 30);
//
//
//	double err2 = 0;
//	double length1 = 0.01;
//	int parts2 = 8;
//	do {
//		double rslt2 = Simpsons_rule_2(a, b, length1);
//		err2 = LN_intgrl_value - rslt2;
//		part_err_file << length1 << " " << fabs(err2) << " " << pow(length1, 4) << std::endl;
//
//		length1 += 0.05;
//	} while (length1 <= 2.25);
//
//	std::cout << "function calls: " << function_calls << std::endl;
//	return 0;
//}

























////фактическа€ ошибка от заданной точности
//int partitions_amount = 2;
//double eps = 0.1;
//do {
//    double result, fact_err;
//    result = Simpsons_rule(a, b, partitions_amount);
//    fact_err = result - LN_intgrl_value;
//    eps_file_1 << eps << " " << fact_err << std::endl;
//    eps /= 10; partitions_amount += 1;
//} while (eps > 1e-14);

//
//    //число разбиений от заданной точности
//int parts_am = 2;
//double res = 0, ferr = 0;
//for (double e = 0.1; e > 1e-10; e /= 10) {
//    parts_am = 1;
//    do {
//        parts_am += 1;
//        res = Simpsons_rule(a, b, parts_am);
//        ferr = LN_intgrl_value - res;
//    } while (ferr > e);
//    parts_file_2 << e << " " << parts_am << std::endl;
//}
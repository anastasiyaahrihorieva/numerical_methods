#include "header.h"


int main() {
	std::ofstream fact_err("differences.txt"), polinom("polinom.txt"), m_err("max_err.txt"), dop("differences_dop.txt");
	std::ofstream ox("nodes_x.txt"), oy("nodes_y.txt"), ox_ch("nodes_x_ch.txt"), oy_ch("nodes_y_ch.txt");
	std::vector<double> points, roots, y, herm_res_ch, max_err, dop_err;


	int n = 4;
	double a = -5, b = 2;
	roots = cheb(n, a, b);
	for (int i = 0; i <= n; ++i) {
		std::cout << roots[i] << std::endl;
	}

	for (double x_i : roots) {
		double y_i = f(x_i);
		y.push_back(y_i);
	}
	for (double root : roots) {
		ox << root << std::endl;
	}
	ox.close();
	for (double root_y : y) {
		oy << root_y << std::endl;
	}
	oy.close();


	for (int i = 0; i <= 10*n; ++i) {
		double point = a + (b - a) * i / (10*n);
		points.push_back(point);
		//double point = 10*n;
		double herm_res = hermite(roots, y, point, n);

		double real_f = f(point);
		double difference = real_f - herm_res;

		fact_err << std::setprecision(5) << point << " " << difference << std::endl;
		polinom << std::setprecision(5) << point << " " << herm_res << std::endl;


	}

	for (int n_change = 1; n_change < 50; ++n_change) {
		std::vector<double> roots_ch = cheb(n_change, a, b);
		std::vector<double> y_ch;
		for (double x_i_ch : roots_ch) {
			double y_i_ch = f(x_i_ch);
			y_ch.push_back(y_i_ch);



		}

		double max_error = 0;
		double  difference_dop = 0;
		
		for (int i = 0; i < n_change ; ++i) {
			double point_ch = (roots_ch[i] + roots_ch[i + 1]) / 2;
			double herm_res = hermite(roots_ch, y_ch, point_ch, n_change);
			double real_f = f(point_ch);
			max_error = real_f - herm_res;

			double point_ch_dop = 1.8999;
			double herm_res_dop = hermite(roots_ch, y_ch, point_ch_dop, n_change);
			double real_f_dop = f(point_ch_dop);
			difference_dop = real_f_dop - herm_res_dop;
			//dop << std::setprecision(5) << difference_dop << std::endl;

		}
		dop_err.push_back(difference_dop);
		max_err.push_back(max_error);

		m_err << n_change << " " << max_error << std::endl; 
		dop << difference_dop << std::endl;
	}

	m_err.close(); 
	dop.close();



	return 0;
}


#include "header.h"

int main() {
	std::ofstream spline_file("spline.txt"), nodes_file("nodes.txt"), nodes_file_ch("nodes_ch.txt"), fact_err("fact_err.txt"), fact_err_ch("fact_err_ch.txt"), spline_file_ch("spline_ch.txt"), max_err_file("max_err.txt"), change_interval_file ("change_interval.txt");
	std::vector<double> err,error, middle_points, x_max_err, x_nodes, y_nodes, M, m, c1, c2, C_1, C_2, Spline_points, Spline_points_ch, Spl_p, x_point, x_p, x_point_ch, x_nodes_ch, y_nodes_ch, M_ch, C_1_ch, C_2_ch, x_n, y_n ;
	double a, b, grid_step, a_ch, b_ch, grid_step_ch, g_st;
	int n, n_ch;
	
	a = -5; b = 2; n = 3;
	grid_step = (b - a) / n;
	x_nodes = uniform_grid(a, b, n);
	y_nodes.resize(n+1);
	for (size_t i = 0; i <= n; i++) {
		y_nodes[i] = f(x_nodes[i]);
	}

	M = Thomas_algorithm(y_nodes, grid_step, n, a, b);

	C_2 = find_const_2(y_nodes, grid_step, M, n);
	C_1 = find_const_1(y_nodes, grid_step, M, n);
	for (size_t i = 0; i < n; i++) {
		std::cout << C_2[i] << std::endl;
	}
	x_point = uniform_grid(a, b, n * 50);
	Spline_points = Spline(x_point, M, grid_step, C_1, C_2, a, n, x_nodes);
	Spline_points = Cubic_spline_result(a, b, n);
	for (size_t i = 0; i < x_point.size(); ++i) {
		spline_file << x_point[i] << " " << Spline_points[i] << std::endl; 
		fact_err << f(x_point[i]) - Spline_points[i] << std::endl;
	}
	for (size_t i = 0; i < x_nodes.size(); ++i) {
		nodes_file << x_nodes[i] << " " << y_nodes[i] << std::endl;
	}
	spline_file.close(); nodes_file.close();

	//
	n_ch = 4; a_ch = -5, b_ch = 2;
	do {
		grid_step_ch = (b_ch - a_ch) / n_ch;
		x_nodes_ch = uniform_grid(a_ch, b_ch, n_ch);
		y_nodes_ch.resize(n_ch + 1);
		for (int i = 0; i <= n_ch; i++) {y_nodes_ch[i] = f(x_nodes_ch[i]);}
		M_ch = Thomas_algorithm(y_nodes_ch, grid_step_ch, n_ch, a_ch, b_ch);

		C_1_ch = find_const_1(y_nodes_ch, grid_step_ch, M_ch, n_ch);
		C_2_ch = find_const_2(y_nodes_ch, grid_step_ch, M_ch, n_ch);
		x_point_ch = uniform_grid(a_ch, b_ch, n_ch * 10); 

		err.resize(n_ch);
		x_max_err.resize(x_nodes_ch.size());
		for (int i = 0; i < n_ch; i++) {
			x_max_err[i] = (x_nodes_ch[i] + x_nodes_ch[i+1])/2.0;
		}
		Spline_points_ch = Spline(x_max_err, M_ch, grid_step_ch, C_1_ch, C_2_ch, a_ch, n_ch, x_nodes_ch);
		for (int i = 0; i < n_ch; i++) {
			err[i] = f(x_max_err[i]) - Spline_points_ch[i];
		}
		double max_err = *std::max_element(begin(err), end(err));
		max_err_file << n_ch << " " << max_err << std::endl;
		++n_ch;
	} while (n_ch <= 100);
	max_err_file.close();
	//

	double a_change = -5;
	double dif2_change = fdif2(a_change) + 1.5;
	int n_change = 6; 
	for (int i = 0; i < 30; i++) {
		g_st = (b - a_change) / n_change;
		x_n = uniform_grid(a_change, b, n_change);
		y_n.resize(n_change + 1);
		for (size_t i = 0; i <= n_change; i++) { y_n[i] = f(x_n[i]); }
		m = Thomas_algorithm_df_change(y_n, g_st, n_change, dif2_change, b);
		c1 = find_const_1(y_n, g_st, m, n_change);
		c2 = find_const_2(y_n, g_st, m, n_change);

		x_p.resize(n_change);
		for (int j = 0; j < n_change; j++) {
			x_p[j] = (x_n[j] + x_n[j + 1]) / 2.0;
		}

		middle_points.resize(n_change);
		for (int k = 0; k < n_change; k++) {
			middle_points[k] = (x_n[k] + x_n[k + 1]) / 2.0;
		}

		Spl_p = Spline(middle_points, m, g_st, c1, c2, a_change, n_change, x_n);
		//std::cout << Spl_p[3] << std::endl;
		//std::cout << f(middle_points[3])<<std::endl;
		error.resize(n_change);
		for (int g = 0; g < n_change; g++) {
			error[g] = f(middle_points[g]) - Spl_p[g];
			//std::cout<<g << " = " << Spl_p[g] << std::endl;
		}
		double err_0 = f(middle_points[0]) - Spl_p[0];
		std::cout << err_0 << std::endl;
		double max_err_intl = *std::max_element(begin(error), end(error));

		//std::cout << max_err_intl << std::endl;
		change_interval_file << dif2_change << " " << fabs(err_0) << std::endl;
		//std::cout << Spl_p[3] << " "<< f(middle_points[3]) << std::endl;
		dif2_change -= 0.1;
	} 

	
	return 0;

}



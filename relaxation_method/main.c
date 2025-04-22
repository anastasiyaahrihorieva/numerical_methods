#include "header.h"

int main() {
	double omega = 0.9;
	double eps_initial = 1e-14;
	double eps = eps_initial;
	double xx[N][1]; 
	double A[N][N], B[N][1], X[N][1]; 
	int itera = 1;

	for (int q = 0; q < N; q++) {
		xx[q][0] = (double)rand() / RAND_MAX * 5 + 2;
	}
	//printMatrix1(xx);

	FILE* iter_file = fopen("iter.txt", "w");
	if (iter_file == NULL) {
		printf("Error opening iter.txt.\n");
		exit(EXIT_FAILURE);
	}

	for (int m = 1; m <= 10; m++) {
		char filename[25];
		sprintf(filename, "matrix_A_%d.txt", m);
		FILE* matrix = fopen(filename, "r");

		if (matrix != NULL) {
			while (eps > 1e-14) {
				printf("success MATRIX %s\n", filename);
				readMatrix(matrix, A);
				fclose(matrix);

				printf("A = \n");
				printMatrix(A);

				multiplication1(A, xx, B);
				//printMatrix1(B);
				int iteration_count = 0;
				Relax(X, A, B, omega, eps, &iteration_count);
				printMatrix1(X);
				//fprintf(iter_file, "%i\n", iteration_count);

				eps *= 0.1;
			}
			
			eps = eps_initial; 
		}
		else {
			printf("Failed to open matrix file %s\n", filename);
		}
	}
		double f_err = 0;
		double normN = 0;
		double X_xx[N][1];
		double Ax_b[N][1];

		for (int q = 0; q < N; q++) {
			X_xx[q][0] = (X[q][0] - xx[q][0]) * (X[q][0] - xx[q][0]);
			f_err += X_xx[q][0];
		}
		f_err = sqrt(f_err);
		printf("f_err = %.16lf ", f_err);

		double Ax[N][1];
		multiplication1(A, X, Ax);
		for (int q = 0; q < N; q++) {
			Ax_b[q][0] = (Ax[q][0] - B[q][0]) * (Ax[q][0] - B[q][0]);
			normN += Ax_b[q][0];
		}
		normN = sqrt(normN);
		printf("normN = %.16lf ", normN);


	//для графиков: определитель 10^-4:
	for (int q = 0; q < N; q++) {
		xx_1[q][0] = (double)rand() / RAND_MAX * 5 + 2;
	}
	//printf("xx_1 = \n");
	//printMatrix1(xx_1);
	FILE* norms = fopen("norms.txt", "w");
	if (norms == NULL) {
		printf("Error opening norms.txt.\n");
		exit(EXIT_FAILURE);
	}
	else {
		printf("Successfully opened norms.txt\n");
	}

	FILE* matrix_A_1 = fopen("matrix_A_5.txt", "r");
	if (matrix_A_1 == NULL) {
		printf("Error opening matrix_A_1.txt\n");
		exit(EXIT_FAILURE);
	}
	else {
		printf("Successfully opened matrix_A_1.txt\n");
	}
	readMatrix(matrix_A_1, A_1);

	multiplication1(A_1, xx_1, B_1);


	double eps_change = 0.1;
	while (eps_change > 1e-14) {
		int iteration_count_1 = 0;
		Relax(X_1, A_1, B_1, omega, eps_change, &iteration_count_1);
		printf("X_1 = \n");
		//printMatrix1(X_1);

		double f_err_1 = 0;
		double normN_1 = 0;
		double X_xx_1[N][1];
		double Ax_b_1[N][1];

		for (int q = 0; q < N; q++) {
			X_xx_1[q][0] = (X_1[q][0] - xx_1[q][0]) * (X_1[q][0] - xx_1[q][0]);
			f_err_1 += X_xx_1[q][0];
		}
		f_err_1 = sqrt(f_err_1);
		printf("f_err = %.16lf ", f_err_1);

		double Ax_1[N][1];
		multiplication1(A_1, X_1, Ax_1);
		for (int q = 0; q < N; q++) {
			Ax_b_1[q][0] = (Ax_1[q][0] - B_1[q][0]) * (Ax_1[q][0] - B_1[q][0]);
			normN_1 += Ax_b_1[q][0];
		}
		normN_1 = sqrt(normN_1);
		printf("normN_1 = %.16lf ", normN_1);
		fprintf(norms, " %.16lf %.16lf %.16lf\n", normN_1, f_err_1, eps_change);

		eps_change *= 0.1;

	}

	fclose(iter_file);
	fclose(matrix_A_1);
	return 0;
}


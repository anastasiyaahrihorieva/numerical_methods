#include "header.h"

int main() {
	double A[N][N], A_new[N][N], x[N][1], x2[N][1], eigenvalue, xx[N][1], eigenvaluex[N][1], nevyzka[N][1], l_scalar;
	FILE* matrix;
	matrix = fopen("matrix_A.txt", "r");
	if (matrix == NULL) {
		printf("Files not found");
		exit(1);
	}
	FILE* errors;
	errors = fopen("errors.txt", "w");
	if (errors == NULL) {
		printf("error errors.txt.\n");
		exit(EXIT_FAILURE);
	}
	FILE* eigen;
	eigen = fopen("max_eigenvalue.txt", "r");
	if (eigen == NULL) {
		printf("error errors.txt.\n");
		exit(EXIT_FAILURE);
	}
	FILE* eig_vect;
	eig_vect = fopen("eig_vect_A.txt", "r");
	if (eig_vect == NULL) {
		printf("error errors.txt.\n");
		exit(EXIT_FAILURE);
	}


	readMatrix(matrix, A);
	fscanf(eigen, "%lf", &eigenvalue);
	printf("eigenvalue true = %.16lf\n", eigenvalue);
	for (int i = 0; i < N; i++) {
		fscanf(eig_vect, "%lf", &xx[i][0]);
	}
	//printf("eigenvector max true=\n");
	//printMatrix1(xx);
	double eps =0.1, Ax[N][1], l1 = 0, l2 = 0;

	while (eps > 1e-10) {
		//printf("eps = %.16lf\n ", eps);
		//l_scalar = 0;
		scalar_method(A, eps, x);
		//printf("L_SCALAR =  %16.lf", l2);
		for (int i = 0; i < N; i++) {
			x[i][0] = -x[i][0];
		}

		//printf("\nx_main=\n");
		//printMatrix1(x);
		//printf("\n");
		eps *= 0.1;

	}


	double eps_2 = 0.1;

	l2 = 0;
	while (eps_2 > 1e-10) {
		//printf("METHOD NO NORM\n");//printf("EPS = %.16lf\n", eps_2);

		scalar_method_no_norm(A, eps_2, x2);

		 //printf("\nX2=\n"); //printMatrix1(x2);
		printf("\n");
		eps_2 *= 0.1;
	}
	//printf("L_SCALAR_no_norm = %.16lf\n", l2);
	fclose(errors);
	fclose(matrix);
	fclose(eig_vect);
	fclose(eigen);
	return 0;
}
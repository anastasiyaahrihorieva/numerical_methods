#include "header.h"


int main() {

	double B_1_test[4][1] = {
		  {70.3012},
		  {45.2165},
		  {37.9544},
		  {47.9147}
	};
	double vozzm = 0.02;

	// Объявление массива dB_test вне цикла
	double dB_test[4][1];

	// Вычисление значений dB_test
	for (int p = 0; p < N; p++) {
		dB_test[p][0] = vozzm * B_1_test[p][0] * 2 * (0.5 - (double)rand() / RAND_MAX);
	}

	// Вывод матрицы B_1_test на консоль
	printf("B_1_test=\n");
	for (int i = 0; i < N; i++) {
		printf("%lf\n", B_1_test[i][0]);
	}

	// Вывод dB_test на консоль
	printf("dB=\n");
	for (int i = 0; i < N; i++) {
		printf("%lf\n", dB_test[i][0]);
	}

	FILE* errors;
	errors = fopen("errors.txt", "w");
	if (errors == NULL) {
		printf("error errors.txt.\n");
		exit(EXIT_FAILURE);
	}
	else {
		printf("success errors.txt\n");
	}

	FILE* matrix_A_1;
	matrix_A_1 = fopen("matrix_A_1.txt", "r");
	if (matrix_A_1 == NULL) {
		printf("error matrix_A_1.txt.\n");
		exit(EXIT_FAILURE);
	}
	else {
		printf("success matrix_A_1.txt\n");
	}
	readMatrix(matrix_A_1, A_1_exact);

	for (int q = 0; q < N; q++) {
		xx[q][0] = (double)rand() / RAND_MAX * 5 + 2;
	}
	printf("xx = \n");
	//printMatrix1(xx);


	FILE* matrix[10];
	char filename[20];
	FILE* normFile;
	normFile = fopen("norms.txt", "w");
	if (normFile == NULL) {
		printf("error norms.txt.\n");
		exit(EXIT_FAILURE);
	}
	else {
		printf("success norms.txt\n");
	}

	for (int i = 1; i <= 10; i++) {
		sprintf(filename, "matrix_A_%d.txt", i);
		matrix[i - 1] = fopen(filename, "r");

		if (matrix[i - 1] != NULL) {

			printf("success %s \n", filename);
			readMatrix(matrix[i - 1], A);

			printf("A = \n");
			//printMatrix(A);

			multiplication1(B, A, xx);
			printf("B = \n");
			//printMatrix1(B);

			Gauss(A, X, B);
			printf("X = \n");
			//printMatrix1(X);

			double normX = 0;
			double normN = 0;

			double raz[N][1];
			for (int q = 0; q < N; q++) {
				raz[q][0] = (X[q][0] - xx[q][0]) * (X[q][0] - xx[q][0]);
				normX += raz[q][0];
			}
			normX = sqrt(normX);
			//printf("norm X = %.16lf ", normX);
			double Ax[N][1];
			multiplication1(Ax, A, X);
			for (int q = 0; q < N; q++) {
				raz[q][0] = (Ax[q][0] - B[q][0]) * (Ax[q][0] - B[q][0]);
				normN += raz[q][0];
			}
			normN = sqrt(normN);

			//printf("normN = %.16lf\n", normN);
			fprintf(normFile, "%.16lf, %.16lf\n", normX, normN);

			//printf("B = \n");
			//printMatrix1(B);
		}
		else {
			printf("error %s.\n", filename);
		}

	}
	fclose(normFile);

	//printf("A = \n");
	//printMatrix(A);


	//printf("B = \n");
	//printMatrix1(B);


	//printf("A = \n");
	//printMatrix(A);

	//printf("X = \n");
	//printMatrix1(X);

	//printf("A_1 = \n");
	//printMatrix(A_1);


	for (int q = 0; q < N; q++) {
		xx_1[q][0] = (double)rand() / RAND_MAX * 5 + 2;
	}
	printf("xx_1 = \n");
	//printMatrix1(xx_1);

	// ||xx||
	double normxx_1 = 0;
	for (int q = 0; q < N; q++) {
		normxx_1 += xx_1[q][0] * xx_1[q][0];
	}
	normxx_1 = sqrt(normxx_1);
	printf("norm_xx_1 = %.16lf ", normxx_1);

	printf("A_1_exact = \n");
	//printMatrix(A_1_exact);

	multiplication1(B_1, A_1_exact, xx_1);
	//printf("B_1 = \n");
	//printMatrix1(B_1);
	normB_1 = 0;
	for (int q = 0; q < N; q++) {
		normB_1 += B_1[q][0] * B_1[q][0];
	}
	normB_1 = sqrt(normB_1);
	//printf("normB_1 = %.16lf ", normB_1);


	printf("CYCLE STARTS\n");
	for (int i = 0; i < 100; i++) {
		double vozm = 0.02;
		for (int q = 0; q < N; q++) {
			dB[q][0] = vozm * B_1[q][0] * 2 * (0.5 - (double)rand() / RAND_MAX);
		}
		//printf("dB=\n");
		//printMatrix1(dB);

		normdB = 0;
		for (int q = 0; q < N; q++) {
			normdB += dB[q][0] * dB[q][0];
		}
		normdB = sqrt(normdB);

		//printf("normdB = %.16lf\n", normdB);

		for (int q = 0; q < N; q++) {
			B_vozm[q][0] = B_1[q][0] + dB[q][0];
		}
		//printf("B_vozm=\n");
		//printMatrix1(B_vozm);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				{
					A_1[i][j] = A_1_exact[i][j];
				}
			}
		}
			Gauss(A_1, X_1, B_vozm);
			//printMatrix(A_1);
			//printf("X_1 = \n");
			//printMatrix1(X_1);

			// ||xx - x||
			double norm_xx_x = 0;
			for (int q = 0; q < N; q++) {
				raz_xx_x[q][0] = (xx_1[q][0] - X_1[q][0]) * (xx_1[q][0] - X_1[q][0]);
				norm_xx_x += raz_xx_x[q][0];
			}
			norm_xx_x = sqrt(norm_xx_x);
		//	printf("norm_xx_x = %.16lf ", norm_xx_x);

			otn_error = norm_xx_x / normxx_1;


			double otn_vozm = normdB / normB_1;
		//	printf(" ||dB||/ ||B||: %.16lf\n", otn_vozm);
		//	printf(" ||xx - x||/ ||xx||: %.16lf\n", otn_error);
			fprintf(errors, "%.16lf %.16lf\n", otn_vozm, otn_error);

		}
		printf("CYCLE ENDS\n");




		//printf("||dB||/ ||B||: %.16lf\n", otn_vozm);


		fclose(errors);
		fclose(matrix);
		fclose(matrix_A_1);

		

		return 0;
	}
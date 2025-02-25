#include "header.h"


void readMatrix(FILE* file, double* A[N][N]) {

	if (file == NULL) {
		printf("Files not found");
		exit;
	}
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			fscanf(file, "%lf", &A[i][j]);
			//printf("%lf ", A[i][j]);
		}
		printf("\n");
	}

	//fclose(file);	return A;
}

void printMatrix(double A[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%.16lf ", A[i][j]);
		printf("\n");
	}
	//printf("\n");
}

void printMatrix1(double A[N][1]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 1; j++)
			printf("%.16lf ", A[i][j]);
		printf("\n");
	}

}

void multiplication1(double B[N][1], double A[N][N], double xx[N][1]) {
	for (int i = 0; i < N; i++) {
		B[i][0] = 0; // Сразу инициализируем для i-ой строки
		for (int k = 0; k < N; k++) {
			B[i][0] += A[i][k] * xx[k][0]; // Используем xx[k][0] вместо xx[k][j]
		}
	}
	return B;
}
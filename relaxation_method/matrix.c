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

}

void printMatrix(double A[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%.16lf ", A[i][j]);
		printf("\n");
	}
}

void printMatrix1(double A[N][1]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 1; j++)
			printf("%.16lf ", A[i][j]);
		printf("\n");
	}

}

void multiplication1(double A[N][N], double x[N][1], double rez[N][1]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 1; j++) {
			rez[i][j] = 0;
			for (int k = 0; k < N; k++)
				rez[i][j] += A[i][k] * x[k][j];
		}
	}
}


void divide(double a[N][N], double c[N][N]) {
	for (int i = 0; i < N; i++) {
		if (a[i][i] != 0) {
			for (int j = 0; j < N; j++) {
				c[i][j] = -a[i][j] / a[i][i];
			}
		}
		else {
			printf("Ошибка: деление на ноль в строке %d\n", i);
		}
	}
}

double norma(double x[N]) {
	double sum = 0.0;
	for (int i = 0; i < N; i++) {
		sum += x[i] * x[i];
	}
	return sqrt(sum);
}

void create_A_up(double A[N][N], double A_up[N][N]) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i <= j) {
				A_up[i][j] = A[i][j]; 
			}
			else {
				A_up[i][j] = 0; 
			}
		}
	}
}


void create_A_low(double A[N][N], double A_low[N][N]) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i > j) {
				A_low[i][j] = A[i][j]; 
			}
			else {
				A_low[i][j] = 0; 
			}
		}
	}
}

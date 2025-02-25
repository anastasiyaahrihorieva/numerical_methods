#include "header.h"
void readMatrix(FILE* file, double A[N][N]) {
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			fscanf(file, "%lf", &A[i][j]);
		}
	}
	return A;
}

void printMatrix1(double A[N][1]) {
	for (int i = 0; i < N; i++)
		printf("%.16lf\n ", A[i][0]);
	printf("\n");
}


void printMatrix(double A[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%.16lf ", A[i][j]);
		printf("\n");
	}
}

void scalar_product(double a[N][1], double b[N][1], double* result) {
	*result = 0; // Инициализируем значение результата
	for (int i = 0; i < N; i++) {
		*result += a[i][0] * b[i][0]; // Суммируем произведения соответствующих элементов
	}
}

void multiplicationMS(double A[N][N], double x[N][1], double rez[N][1]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 1; j++) {
			rez[i][j] = 0;
			for (int k = 0; k < N; k++)
				rez[i][j] += A[i][k] * x[k][j];
		}
	}
}

double norma(double vector[N][1]) {
	double sum = 0.0;

	// Подсчет суммы квадратов элементов вектора
	for (int i = 0; i < N; i++) {
		sum += vector[i][0] * vector[i][0];
	}

	// Возвращаем корень квадратный из суммы квадратов
	return sqrt(sum);
}


void multiplication(double A[N][N], double a, double A_new[N][N]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			A_new[i][j] = A[i][j] * a;
}

void multiplicationB(double A[N][1], double a, double A_new[N][1]) {
	for (int i = 0; i < N; i++)
		A_new[i][0] = A[i][0] * a;
}

void subtraction1(double A[N][1], double B[N][1], double C[N][1]) {
	for (int i = 0; i < N; i++)
		C[i][0] = A[i][0] - B[i][0];
}

double norma2(double first[N][1], double second[N][1]) {
	double norm = 0;
	for (int i = 0; i < N; i++)
		norm += pow(first[i][0] - second[i][0], 2);
	norm = sqrt(norm);
	return norm;
}


void divide(double vector[N][1], double scalar, double result[N][1]) {
	for (int i = 0; i < N; i++) {
		if (scalar != 0) {
			result[i][0] = vector[i][0] / scalar; // Делим каждый элемент вектора на скаляр
		}
		else {
			printf("error function divide \n");
			result[i][0] = 0; // или выберите другое стандартное значение
		}
	}
}
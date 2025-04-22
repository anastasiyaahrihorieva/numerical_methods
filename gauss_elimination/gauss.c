#include "header.h"

void Gauss(double A[N][N], double X[N][1], double B[N][1]) {
    // Прямой ход с выбором главного элемента
    for (int k = 0; k < N; k++) {
        // Поиск максимального значения в столбце k
        double maxEl = fabs(A[k][k]);
        int maxRow = k;
        for (int i = k + 1; i < N; i++) {
            if (fabs(A[i][k]) > maxEl) {
                maxEl = fabs(A[i][k]);
                maxRow = i;
            }
        }

        // Перестановка текущей строки с строкой maxRow
        for (int j = 0; j < N; j++) {
            double temp = A[maxRow][j];
            A[maxRow][j] = A[k][j];
            A[k][j] = temp;
        }
        double temp = B[maxRow][0];
        B[maxRow][0] = B[k][0];
        B[k][0] = temp;

        // Прямой ход
        for (int i = k + 1; i < N; i++) {
            double m = A[i][k] / A[k][k];
            for (int j = k; j < N; j++) { // j должен начинаться с k
                A[i][j] -= m * A[k][j];
            }
            B[i][0] -= m * B[k][0];
        }
    }

    // Обратный ход метода Гаусса
    for (int i = N - 1; i >= 0; i--) {
        double d = 0;
        for (int j = i + 1; j < N; j++) {
            d += A[i][j] * X[j][0];
        }
        X[i][0] = (B[i][0] - d) / A[i][i]; // Находим решение для X[i]
    }
    return X;
}



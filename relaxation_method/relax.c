#include "header.h"

void Relax(double X[N][1], double A[N][N], double b[N][1], double omega, double eps_start, int* iteration_count) {
    double x_k[N][1] = { 0 };
    double x_k_plus_1[N][1] = { 0 };

    int iteration = 0;
    double norm_diff;
    double eps = eps_start;

    double A_up[N][N];
    double A_low[N][N];

    create_A_up(A, A_up);
    create_A_low(A, A_low);

    do {
       
        for (int i = 0; i < N; i++) {
            double sum_low = 0.0;
            double sum_up = 0.0;

            for (int j = 0; j < i; j++) {
                sum_low += A[i][j] * x_k_plus_1[j][0];
            }

            for (int j = i + 1; j < N; j++) {
                sum_up += A[i][j] * x_k[j][0];
            }
            x_k_plus_1[i][0] = (1 - omega) * x_k[i][0] + (omega / A[i][i]) * (b[i][0] - sum_low - sum_up);
        }
        norm_diff = 0.0;
        for (int i = 0; i < N; i++) {
            norm_diff += (x_k_plus_1[i][0] - x_k[i][0]) * (x_k_plus_1[i][0] - x_k[i][0]);
        }
        norm_diff = sqrt(norm_diff);

        //printf("Iteration %d, norm_diff = %.16f, eps = %.16f\n", iteration, norm_diff, eps);

        for (int i = 0; i < N; i++) {
            x_k[i][0] = x_k_plus_1[i][0];
        }

        iteration++;

    } while (norm_diff > eps);

    for (int i = 0; i < N; i++) {
        X[i][0] = x_k_plus_1[i][0];
    }
    printMatrix1(b);
    printf("it %d\n", iteration);
    *iteration_count = iteration; 

}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define NUM_FILES 10

// ������������� ������
double A[N][N]; // ������� �������������
double A_1[N][N];
double b[N][1]; // ������ ������ �����
double B[N][1]; // ������ ������ �����
double X[N][1]; // �������


double xx[N][1], normX, normN;
double C[N][N], A_1[N][N], E[N][N], A_1_exact[N][N];
double xx_1[N][1];//������ �������
double B_1[N][1];
double normdB, normB;
double B_vozm[N][1];
double X_1[N][1];    // ������ �������
double raz_xx_x[N][1];
double otn_error;
double normB_1, x_curr[N][1];


void readMatrix(FILE* file, double A[N][N]);
void printMatrix(double A[N][N]);
void printMatrix1(double A[N][1]);
void multiplication1(double B[N][1], double A[N][N], double xx[N][1]);

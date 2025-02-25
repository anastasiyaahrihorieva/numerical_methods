#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define NUM_FILES 10


double A[N][N], B[N][1], dB[N][1], raz[N][1], X[N][1];
double xx[N][1], normX, normN;
double A[N][N], A_1[N][N], A_1_exact[N][N];
double xx_1[N][1];//точное решение
double B_1[N][1];
double normdB, normB;
double B_vozm[N][1];
double X_1[N][1];    // Вектор решений
double raz_xx_x[N][1];
double otn_error;
double normB_1;



void readMatrix(FILE* file, double A[N][N]);
void printMatrix(double A[N][N]);
void printMatrix1(double A[N][1]);
void multiplication1(double B[N][1], double A[N][N], double xx[N][1]);
void Gauss(double A[N][N], double B[N][1]);
void change(double A[N][N], double B[N][1], int i, int j);
#include "header.h"


double scalar_method(double A[N][N], double eps, double x[N][1]) {
    double lyambda;
    FILE* eigen = fopen("max_eigenvalue.txt", "r");
    if (eigen == NULL) {
        printf("error errors.txt.\n");
        exit(EXIT_FAILURE);
    }
    fscanf(eigen, "%lf", &lyambda);

    FILE* norms = fopen("norms_scalar.txt", "a"); 
    if (norms == NULL) {
        printf("Error opening norms_scalar.txt.\n");
        fclose(eigen);
        exit(EXIT_FAILURE);
    }

    eps = eps / 10;
    double y[N][1], x_prev[N][1], x_new[N][1], l_prev, l_curr = 0;
    int i, counter = 0;
    x_prev[0][0] = 1;
    for (i = 1; i < N; i++) { // х(0)
        x_prev[i][0] = 0;
    }

    do {
        double s, t;
        l_prev = l_curr;
        multiplicationMS(A, x_prev, y); // у(к+1)
        scalar_product(y, y, &s);
        scalar_product(y, x_prev, &t);
        l_curr = s / t; // новое собственное значение

        double sum = 0.0;
        for (int i = 0; i < N; i++) {
            sum += y[i][0] * y[i][0];
        }

        double norma_y = sqrt(sum);
        divide(y, norma_y, x_new);

        double sum_1 = 0.0;
        for (int i = 0; i < N; i++) {
            sum_1 += x_new[i][0] * x_new[i][0];
        }
        double norma_x_new = sqrt(sum_1);
        double x_prev_2[N][1];
        divide(x_new, norma_x_new, x_prev_2);

        // х(0)
        for (i = 0; i < N; i++) {
            x_prev[i][0] = x_prev_2[i][0];
        } 

        counter++;
    } while (fabs(l_curr - l_prev) > eps);

    //FACT ERR
    double sub = (lyambda - l_curr) * (lyambda - l_curr);
    double norma_f_err = sqrt(sub);

   
   // printf("l_norm = %.16lf it = %i, norma f_err = %.16lf\n", l_curr, counter, norma_f_err);

    for (i = 0; i < N; i++) {
        x[i][0] = x_new[i][0];
    }

    //printf("x from scalar = \n");
    //for (i = 0; i < N; i++) {
    //    x[i][0] = -x[i][0];
    //}
    //printMatrix1(x);

    //NEVYAZKA
    double Ax[N][1];
    double lx[N][1];
    double nev[N][1];
    multiplicationMS(A, x, Ax);

    multiplicationB(x, l_curr, lx);
    subtraction1(Ax, lx, nev);
    double summ = 0.0;
    for (int i = 0; i < N; i++) {
        summ += nev[i][0] * nev[i][0]; 
    }
    double norma_nev = sqrt(summ); 

   // printf("norma nevyazki = %.16lf\n", norma_nev);
    fprintf(norms, "%.16lf %.16lf %i  %.16lf\n", eps, norma_f_err, counter, norma_nev);

    //printMatrix1(normaN);

    fclose(eigen);
    fclose(norms);

    return l_curr;
}


double scalar_method_no_norm(double A[N][N], double eps, double x[N][1]) {
    double lyambda;
    FILE* eigen = fopen("max_eigenvalue.txt", "r");
    if (eigen == NULL) {
        printf("Error opening max_eigenvalue.txt.\n");
        exit(EXIT_FAILURE);
    }
    fscanf(eigen, "%lf", &lyambda);
    fclose(eigen);
    FILE* norms_no = fopen("norms_scalar_NO_NORM.txt", "a");
    if (norms_no == NULL) {
        printf("Error opening norms_scalar_NO_NORM.txt.\n");
        exit(EXIT_FAILURE);
    }

    double y[N][1], x_prev[N][1], l_prev, l_curr = 0;
    int i, counter = 0;

    x_prev[0][0] = 1;
    for (i = 1; i < N; i++) {
        x_prev[i][0] = 0;
    }

    do {
        double s, t;
        l_prev = l_curr;

        multiplicationMS(A, x_prev, y); // y(k + 1)
        scalar_product(y, y, &s);
        scalar_product(y, x_prev, &t);

        l_curr = s / t; 

        for (i = 0; i < N; i++) {
            x_prev[i][0] = y[i][0]; 
        }
        counter++;
    } while (fabs(l_curr - l_prev) > eps);

    for (i = 0; i < N; i++) {
        x_prev[i][0] = -x_prev[i][0];
    }
     printf("l_no_norm = %.16lf it = %i\n", l_curr, counter);

     //нев-ка
    double Ax[N][1], lx[N][1], nev[N][1];
    double norma_x_prev = 0.0;
    for (i = 0; i < N; i++) {
        norma_x_prev += x_prev[i][0] * x_prev[i][0];
    }
    norma_x_prev = sqrt(norma_x_prev);

    for (i = 0; i < N; i++) {
        x_prev[i][0] = x_prev[i][0]/norma_x_prev;
    }

   // printMatrix1(x_prev);

  
    multiplicationMS(A, x_prev, Ax);
    multiplicationB(x_prev, l_curr, lx);
    subtraction1(Ax, lx, nev);

    double summ = 0.0;
    for (int i = 0; i < N; i++) {
        summ += nev[i][0] * nev[i][0];
    }
    double n_nev = sqrt(summ);

     printf(" nev = %.16lf\n", n_nev);


     // ошибки
     double sub = (lyambda - l_curr) * (lyambda - l_curr);
     double norma_f_err = sqrt(sub);
     printf(" %.16lf ", norma_f_err);

     fprintf(norms_no, "%.16lf %.16lf %i %.16lf\n", eps, norma_f_err, counter, n_nev);

    fclose(norms_no); 
    return l_curr; 
}
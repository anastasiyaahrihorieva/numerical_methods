#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define min_dif 0.71497
#define max_2dif 5.5927



double f(double a) {
	return(atan(a * a + 1 / a) - a);
	//return (pow(a, 4) - 18 * pow(a, 3) - 10);
}


double fdif(double a) {
	return ((2 * pow(a, 3) - 1) / (pow(a, 6) + 2 * pow(a, 3) + pow(a, 2) + 1) - 1);
	//return (4 * pow(a, 3) - 54 * pow(a, 2));
}

double f2dif(double a) {
	return (-(6 * pow(a, 8) - 6 * pow(a, 5) - 2 * (a, 4) - 12 * pow(a, 2) - 2 * a) / (pow(a, 12) + 4 * pow(a, 9) + 2 * pow(a, 8) + 6 * pow(a, 6) + 4 * pow(a, 5) + pow(a, 4) + 4 * pow(a, 3) + 2 * pow(a, 2) + 1));
	//return (12 * pow(a, 2) - 108 * a);
}


void mpd(char const* fp, double a, double b) {
	double e = 0.1, c, x, a1, b1;
	int it = 0, step = 1;

	FILE* file;
	file = fopen(fp, "w");
	if (file == NULL) {
		printf("файл не найден");
		exit;
	}

	fprintf(file, "\n");
	while (step != 15) {
		a1 = a;
		b1 = b;
		it = 0;
		while (b1 - a1 > e) {
			it += 1;
			c = (b1 + a1) / 2;
			if (f(a1) * f(c) < 0)
				b1 = c;
			else
				a1 = c;
		}
		x = (a1 + b1) / 2;
		fprintf(file, "%.14f  %.16f  %d\n", e, x, it);
		printf("%.14f  %.16f  %d\n", e, x, it);

		e *= 0.1, step += 1;
	}
	fclose(file);
}



void new(char const* fp, double a, double b){
	double e = 0.1, a2, b2, x, x0, x1;
	int it = 0, step = 1;

	FILE* file;
	file = fopen(fp, "w");
	if (file == NULL) {
		printf("файл не найден");
		exit;
	}
	fprintf(file, "\n");

	if (f(a) * f2dif(a) > 0) {
		x1 = a;
		x0 = b;
	}
	else
	{
		x1 = b;
		x0 = a;
	}
	it = 0;
while (step != 15) {
	//a2 = a;
	//b2 = b;

	while (pow(fabs(x1 - x0), 2) * max_2dif / (2 * min_dif) >= e) {
		x0 = x1;
		it += 1;
		x1 = x0 - f(x0) / fdif(x0);
	}
	x = x1;
	fprintf(file, "%.14f  %.16f  %d\n", e, x, it);
	printf("%.14f  %.16f  %d\n", e, x, it);

	e *= 0.1, step += 1;
}

fclose(file);
}


int main() {
//	double a1 = 17, b1 = 19;

	//mpd("data_algMPD.txt", a1, b1);
	//new("data_algNEW.txt", a1, b1);

	double a2 = 1.1, b2 = 1.3;
	mpd("data_tranMPD.txt", a2, b2);
	new("data_tranNEW.txt", a2, b2);

	return 0;
}
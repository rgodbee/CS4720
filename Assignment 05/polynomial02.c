/*
Program: polynomial01.c 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_poly.h>
#include "basic_lib.h"
#define N 7 // number of coefficients
#define M 50
void polyval(double p[], double xv[], double yv[], int n, int m);
/* const int N = 4; num of coefficients of polynomial */
int main () {
	int i;
	int j;
	/* coefficients of Polynomial */
	double constants[N] = {4.5, -3, 6, -6.5, 5, -1.5, 2}; /* coefficients */
	double xi, xf;
	double x[M];
	double y[M];
	printf("Evaluating polynomial with coefficients: \n");
	for (i=0; i < N; i++)
		printf("%f ", constants[i]);
	printf(" \n");
	/* Evaluate the polynomial at the following points in x */
	xi = -2.0; /* first value of x */
	xf = 2.0; /* final value of x */
	linspace(x, xi, xf, M); // vector of values for x
	polyval(constants, x, y, N, M);
	printf(" \n");
	printf("Data points calculated of the polynomial x y \n");
	for(j=0; j < M; j++)
		printf("%+.10f %+.10f \n", x[j], y[j]);
	return 0;
} /* end main */

void polyval (double p[], double xv[], double yv[], int n, int m) {
	int j;
	yv[0] = gsl_poly_eval(p, N, xv[0]);
	for (j = 1; j < M; j++) 
	{
		yv[j] = gsl_poly_eval(p, N, xv[j]);
	}
	return;
} 
//  gcc -Wall -o polyfit02 polyfit02.c basic_lib.o polyfitgsl.o -lgsl -lgslcblas -lm

#include <stdio.h>
#include <gsl/gsl_poly.h>
#include "basic_lib.h"
#include "polyfitgsl.h"
#define NC 6 /* size of coefficient vector */

void polyval(double p[], double xv[], double yv[], int n, int m);

int main()
{
	const int NP = 8; // Number of given data points
	const int M = 50; // number of computed data points
	/* const int NC = 2 ; Number of coefficients */
	double x[] = {1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002};
	double y[] = {5500, 8500, 13500, 20500, 29500, 40500, 53500, 68500};
	double coeff[NC]; // vector of coefficients
	int i;
	double xc[M]; /* computed values for x using polynomial */
	double yc[M];
	printf("Program finds best fit polynomial of degree %d \n",
		NC-1);
	printf("Data points (x,y): \n");
	for (i = 0; i < NP; i++)
		printf(" %f %f \n", x[i], y[i]);
	polynomialfit(NP, NC, x, y, coeff); /* find coefficients */
	printf("\n\nCoefficients of polynomial found\n");
	for(i=0; i < NC; i++) {
		printf("%lf\n", coeff[i]);
	}
	/* Evaluate the fitted polynomial */
	linspace(xc, 0.0, 12.0, M);
	polyval(coeff, xc, yc, NC, M);
	printf("\nData points calculated with the polynomial \n");
	for(i=0; i < M; i++)
		printf("%d %+.18f %+.18f \n", i, xc[i], yc[i]);
	return 0;
} /* end main */

void polyval (double p[], double xv[], double yv[], int n,
		int m) {
	int j;
	yv[0] = gsl_poly_eval(p, n, xv[0]);
	for (j = 1; j < m; j++)
	yv[j] = gsl_poly_eval(p, n, xv[j]);
	return;
} /* end polyval */
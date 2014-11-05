#include <stdio.h>
#include <math.h>
#include <gsl/gsl_interp.h>
#include "basic_lib.h"
/* Number of Discrete Points (original data) */
#define N 20
void csinterp(double x[], double y[], double nx[], double ny[], int m, int n);
int main() {
	int i;
	int n;
	double h;
	double x[N];
	double xi, xf;
	double y[N] = {-310.0, -179.8, -82.3, -13.6, 30.0, 52.6, 57.8, 49.6, 31.8, 8.2, -17.2, -40.8, -58.6, -66.8, -61.5, -39.0, 4.6, 73.3, 170.8, 301.0};
	double xint[2*N], yint[2*N];
	/* Linear Interpolation */
	xi = -6.0; /* first value of x */
	xf = 7.0; /* last value */
	linspace(x, xi, xf, N);
	printf("Discrete Points for Cubic Spline Interpolation\n");
	printf(" i x y\n");
	for(i = 0; i < N; i++)
		printf("%3d %25.17e %25.17e\n", i, x[i], y[i]);
	printf("\n");
	/* Evaluation */
	h = 0.45; // x increment
	n = arraycol(xint, -5.0, xf, h); /* fill new array */
	csinterp(x, y, xint, yint, N, n);
	printf(" x interpolated y \n");
	for(i = 0; i < n; i++)
		printf("%25.17e %25.17e \n", xint[i], yint[i]);
	return 0;
}
void csinterp(double x[], double y[], double nx[], double ny[], int m, int n) {
	int i;
	gsl_interp *workspace;
	/* type of Interpolation: Cubic Spline */
	workspace = gsl_interp_alloc(gsl_interp_cspline, m);
	gsl_interp_init(workspace, x, y, m); /* Initialize worksp */
	for(i = 0; i < n; i++)
		ny[i] = gsl_interp_eval(workspace, x, y, nx[i], NULL);
	gsl_interp_free(workspace); /* free memory */
}
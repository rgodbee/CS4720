/*Program: predprey2.c
 This program solves the Prey and Predator Model
 Uses the GSL for solving the ODE system
  and links with 'ode45c.c'
 Function 'ode45c' hides details of calling the GSL functions
 J M Garrido, updated March 18, 2014, CS dept, KSU
*/

#include "ode45c.h"

  const int DIM = 3;  // number of differential equations
  const int NT = 50;  // number of time values
  int YVN = 100;

  double a = 1;  // parameters for the diffeq
  double b = 0.3;
  // double c = 0.0025;
  // double d = 0.0013;

/* dfunct - defines the first order differencial equations to solve */
int dfunc (double t, const double y[], double f[], void *params_ptr);

int main (void) {

  double myparams[2];
  double y[DIM];    // current solution vector
  double yv[YVN];
  double t[NT];

  double tmin, tmax, delta_t; // range of t and step size for output
  int status;
  int k;
  int kk;
  printf("\nThis program numerically solves the Predator-Prey Model\n\n");

  myparams[0] = a; /* diff equation parameters */
  myparams[1] = b;
  // myparams[2] = c;
  // myparams[3] = d;

  tmin = 0.0;     /* starting t value */
  tmax = 100.0;   /* final t value */
  delta_t = 2.0;  /* about 50 data points */
  y[0] = 0.999;   /* initial number of susceptible */
  y[1] = 0.001;    /* initial number of infected */
  y[2] = 0.0;     /* initial number of immune */

  printf("Input data: \n");
  printf("Initial values s = %g i = %g r = %g \n", y[0], y[1], y[2]);
  printf(" Parameters (a, b, c, d) a= %g b= %g \n", a, b);
  printf(" Time parameters: %f %f %f \n", tmin, tmax, delta_t);
  printf(" Number of equations (dimension): %d \n\n", DIM);

  printf("Solution: \n");
  printf("    Time          x1           x2 \n");

  status = ode45(dfunc, tmin, tmax, t, y, yv, delta_t, DIM);
  k=0;
  kk=0;
  for (k = 0; k < NT; k++) {
     printf("%lf    ", t[k]);
	 for (d = 0; d < DIM; d++) {
	   printf("  %lf  ", yv[kk]);
	   kk++;
	 }
	 printf(" \n");
  }
  return 0;
} // end of main

int dfunc (double t, const double y[], double f[], void *params_ptr)
{
  // parameter(s) are declared as globals
  // evaluate the right-hand-side functions at t
  f[0] = -1 * a * y[0] * y[1];
  f[1] = a * y[0] * y[1] - b * y[1];
  f[2] = b * y[1];
  return GSL_SUCCESS;  // GSL_SUCCESS defined in gsl/errno.h as 0
} // end of dfunct


/*Program: preypred.c
 This program solves the Prey and Predator Model
 
 J M Garrido, March 11, 2013, CS dept, KSU
*/
#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>
  double a = 0.25;  /* parameters for the diffeq */
  double b = 0.12;
  double c = 0.0025;
  double d = 0.0013;
/* dfunct - defines the first order differencial equations to solve */
int dfunc (double t, const double y[], double f[], void *params_ptr);
int main (void) {
  const int dimension = 2;  /* number of differential equations */
  int status;               /* status of driver function */
  const double eps_abs = 1.e-8;  /* absolute error requested */
  const double eps_rel = 1.e-10; /* relative error requested */
  double myparams[4];
  double y[dimension];    /* current solution vector */
  double t, t_next;       /* current and next independent variable */
  double tmin, tmax, delta_t; /* range of t and step size for output */
  double h = 1.0e-6;      /* starting step size for ode solver */
  gsl_odeiv2_system ode_system;	/* structure with the dfunc function, etc. */
  printf("\nThis program numerically solves the Prey and Predator Model\n\n");
  /* load values into the ode_system structure */
  ode_system.function = dfunc;	/* the right-hand-side functions dy[i]/dt */
  ode_system.dimension = dimension;	/* number of diffeq's */
  myparams[0] = a; /* diff equation parameters */
  myparams[1] = b;
  myparams[2] = c;
  myparams[3] = d; 
  ode_system.params = myparams;	/* parameters for GSL functions */
  tmin = 0.0;     /* starting t value */
  tmax = 230.0;   /* final t value */
  delta_t = 4.6;  /* about 50 data points */
  y[0] = 125.0;   /* initial number of rabbits */
  y[1] = 47.0;    /* initial number of wolves */
  gsl_odeiv2_driver * drv =
      gsl_odeiv2_driver_alloc_y_new (&ode_system, gsl_odeiv2_step_rkf45, h, eps_abs, eps_rel);
  printf("Input data: \n");
  printf("Initial values x = %g v = %g \n", y[0], y[1]); 
  printf(" Parameters (a, b, c, d) a= %g b= %g c= %g d= %g\n", a, b, c, d);
  printf(" Starting step size (h): %0.5e\n", h);
  printf(" Time parameters: %f %f %f \n", tmin, tmax, delta_t); 
  printf(" Absolute and relative error requested: %0.6e %0.6e \n", eps_abs, eps_rel);
  printf(" Number of equations (dimension): %d \n\n", dimension);
  printf("    Time          x1          x2 \n");
  t = tmin;             /* initialize t */
  printf ("%.5e  %.5e  %.5e\n", t, y[0], y[1]);	/* initial values */
  /* step to tmax from tmin */
  for (t_next = tmin + delta_t; t_next <= tmax; t_next += delta_t)
  {
     status = gsl_odeiv2_driver_apply (drv, &t, t_next, y);
     if (status != GSL_SUCCESS) {
          printf("Error: status = %d \n", status);
          break;
     }
     printf ("%.5e %.5e %.5e\n", t, y[0], y[1]); /* print at t=t_next */
  } // end for
  gsl_odeiv2_driver_free (drv);
  return 0;
} // end of main
int dfunc (double t, const double y[], double f[], void *params_ptr)
{ 
  /* parameter(s) are declared as globals */
  /* evaluate the right-hand-side functions at t */
  f[0] = a * y[0] - c * y[0] * y[1];
  f[1] = - b * y[1] + d * y[0] * y[1];
  return GSL_SUCCESS;		/* GSL_SUCCESS defined in gsl/errno.h as 0 */
} // end of dfunct


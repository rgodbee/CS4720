/* This C function solves a set of ODE using Runge-Kutta 4,5
   This is the prototype of the 'ode45' function
   It hides the details of calling the GSL functions
*/

#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>

int ode45(int (*pfunct)(double t, const double y[], double dydt[], void * params),
    double tinit, double tfinal, double tv[], double y[], double yv[], 
    double tdelta, const int dimen);



/* Function 'ode45' that solves an ODE system using Runge-Kutta fouth order method
   This function hides the details of calling the GSL functions
   J M Garrido, updated Feb 20, 2014
   Dept. of Computer Science, KSU.
*/
 
#include "ode45c.h"

int ode45(int (*pfunct)(double t, const double y[], double dydt[], void * params),
    double tinit, double tfinal, double tv[], double y[], double yv[], 
    double tdelta, const int dimen) {
    double t;
    double t_next;
    int status;                    // status of driver function 
    const double eps_abs = 1.e-8;  // absolute error requested 
    const double eps_rel = 1.e-10; // relative error requested
    double h = 1.0e-6;             // starting step size for ode solver 
    int k;
    int kk;
    int d;
    gsl_odeiv2_system ode_system;   // structure with the dfunc function, etc. 
    /* load values into the ode_system structure */
    ode_system.function = pfunct;  // the right-hand-side functions dy[i]/dt 
    ode_system.dimension = dimen;  // number of diffeq's 
    ode_system.params = NULL;      // no parameters to pass to dfunc and jacobian 
    gsl_odeiv2_driver * drv =
    gsl_odeiv2_driver_alloc_y_new (&ode_system,
    gsl_odeiv2_step_rkf45, h, eps_abs, eps_rel);
    t = tinit;             // initialize t 
    k = 0;
    kk = 0;
    // initial values
    tv[k] = tinit;
    for (d = 0; d < dimen; d++) {
          yv[kk] = y[d];
          kk++;
    }
    k++;
    for (t_next = tinit + tdelta; t_next <= tfinal; t_next += tdelta)
    {
       status = gsl_odeiv2_driver_apply (drv, &t, t_next, y);
       if (status != GSL_SUCCESS) {
          printf("Error: status = %d \n", status);
          break;
       }
       // get values for all the variales for this value of time
       for (d = 0; d < dimen; d++) {
          yv[kk] = y[d];
          kk++;
       }
       tv[k] = t;
       k++;
    } // end for
    /* all done; free up the gsl_odeiv2 driver */
    gsl_odeiv2_driver_free (drv);
    return status;
}

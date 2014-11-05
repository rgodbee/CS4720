#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <math.h>
#include "basic_lib.h"

#define M_PI 3.14159265358979323846 

int main (void) {
	const int N = 75;
	// double data[N];
	int i;
	
	// gsl_vector * T = gsl_vector_alloc (N); 
	// gsl_vector * V = gsl_vector_alloc (N); 
	double T[N];
	double V[N];

	// gsl_vector_set_all(T, 0.0);
	// gsl_vector_set_all(V, 0.0);

	// creat input data
	// linspace (data, 0, 2*M_PI, N);
	linspace (T, 0, (2*M_PI), N);
	//store input data into the matrix
	// for(i = 0; i < N; i++)
		// gsl_vector_set(T, i, data[i]);

	// compute the sin value
	for (i = 0; i < N; ++i)
		// gsl_vector_set(V, i ,sin(data[i]));
		V[i] = sin(T[i]);
	// print the input vector and output vector
	printf("Line\tInput T\tOutput V\n");
	for (i = 0; i < N; i++)
		printf ("%d\t%g\t%g\n", i, T[i], V[i]);

	
	// gsl_vector_free (T); // release allocated memory
	// gsl_vector_free (V); // release allocated memory
	// free(T);
	// free(V);
	return 0;
}

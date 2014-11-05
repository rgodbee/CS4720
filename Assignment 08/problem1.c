#include <stdio.h>
#include <math.h>
#include "basic_lib.h"

#define M_PI 3.14159265358979323846

int main (void) {
	const int N = 75;
	int i;
	double T[N];
	double V[N];

	linspace (T, 0, 8, N);

	// compute the cos value
	for (i = 0; i < N; ++i)
		V[i] = T[i]+exp(T[i]/2*M_PI)*cos(2*M_PI*T[i]);

	// print the input vector and output vector
	printf("Line\tInput T\tOutput V\n");
	for (i = 0; i < N; i++)
		printf ("%d\t%g\t%g\n", i, T[i], V[i]);
	
	return 0;
}

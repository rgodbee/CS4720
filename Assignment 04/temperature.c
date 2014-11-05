/*
Program: temperature.c 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "basic_lib.h"

int main()
{
	const int timePeriod = 12;


	double temperArray[] = {51, 56, 60, 65, 73, 78, 85, 86, 84, 81, 80, 70};
	double *d; //first differences
	double *d2; //second differences
	double *f; //factors
	int i;
	// initial data
	printf("Initial data given.\n");
	for(i = 0; i < timePeriod; i++)
		printf("%.2f\t", temperArray[i]);

	printf("\nFirst Difference of the given data.\n");
	d = diff(temperArray, timePeriod);
	// spacing fr formatting
	printf("\t");
	// print first difference array
	for(i = 0; i < timePeriod-1; i++)
		printf("%.2f\t", d[i]);

	printf("\nSecond Difference of the given data.\n");
	d2 = diff(d, timePeriod-1);
	// spacing fr formatting
	printf("\t\t");
	// print second difference array
	for(i = 0; i < timePeriod-2; i++)
		printf("%.2f\t", d2[i]);

	printf("\nFactors of the given data.\n");
	f = factor(temperArray, timePeriod);
	// spacing fr formatting
	printf("\t");
	for(i = 0; i < timePeriod-1; i++)
		printf("%.2f\t", f[i]);	

	printf("\n");

	return 0;
}
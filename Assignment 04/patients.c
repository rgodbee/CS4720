/*
Program: temperature.c 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "basic_lib.h"

int main()
{
	const int years = 8;
	int startYear = 1995;

	// data from table 13.1 Number of patients for years 1995–2002. page 176
	double patients[] = {5500, 8500, 13500, 20500, 29500, 40500, 53500, 68500};
	double *d; //first differences
	double *d2; //second differences
	int i;
	for(i = 0; i < years; i++)
	{
		printf("%d\t", startYear);
		startYear++;
	}	
	// initial data
	printf("\nInitial data given.\n");
	for(i = 0; i < years; i++)
		printf("%.0f\t", patients[i]);

	
	printf("\nFirst Difference of the given data.\n");
	d = diff(patients, years);
	// spacing fr formatting
	printf("\t");
	// print first difference array
	for(i = 0; i < years-1; i++)
		printf("%.0f\t", d[i]);
	
	printf("\nSecond Difference of the given data.\n");
	d2 = diff(d, years-1);
	// spacing fr formatting
	printf("\t\t");
	// print second difference array
	for(i = 0; i < years-2; i++)
		printf("%.0f\t", d2[i]);

	printf("\n");

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define arraySize(x) (sizeof(x)/sizeof(x[0]))

int main(int argc, const char* argv[])
{
	// inputs
	double data[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	//average
	double avg = 0;
	double sum = 0;
	int i;
	for (i = 0; i < arraySize(data); ++i)
	{
		sum = sum + data[i];
	}
	avg = sum/arraySize(data);
	// sqdif
	double sqdif = 0;
	for (i = 0; i < arraySize(data); ++i)
	{
		sqdif = sqdif + pow((data[i]-avg), 2);
	}
	//standard deviation
	double std = sqrt(sqdif/(arraySize(data)-1));
	//display standard deviation
	printf("avg: %f\n", avg);
	printf("sqdif: %f\n", sqdif);
	printf("std: %f\n", std);
	return 0;
}

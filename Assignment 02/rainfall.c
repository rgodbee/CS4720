#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define arraySize(x) (sizeof(x)/sizeof(x[0]))
#define NUM_YEARS 5
#define QUARTERS 4

int main(int argc, const char* argv[])
{
	// inputs
	// rainf [j] [k]
	// j = number of years
	// k = rainfall per quarter, k[0] first quarter, k[3] fourth quarter
	double rainf[NUM_YEARS][QUARTERS] = {
		{5.0, 6.1, 7.2, 8.3},
		{0.1, 1.2, 2.3, 3.4},
		{10.4, 11.3, 12.2, 13.1},
		{4.6, 1.0, 2.2, 8.3},
		{3.0, 2.0, 1.0, 0.0}
	};
	// Year Average
	int i = 0;
	int j = 0;
	double sumQuarter = 0;
	double averagePerYear = 0;
	for (i = 0; i < NUM_YEARS; ++i)
	{	
		sumQuarter = 0;
		for (j = 0; j < QUARTERS; ++j)
		{
			sumQuarter = sumQuarter + rainf[i][j];
		}
		averagePerYear = sumQuarter/4;
		printf("Year %d average rain: %f\n", i, averagePerYear);
	}
	// Quarter Average
	sumQuarter = 0;
	averagePerYear = 0;
	for (j = 0; j < QUARTERS; ++j)
	{	
		sumQuarter = 0;
		for (i = 0; i < NUM_YEARS; ++i)
		{
			sumQuarter = sumQuarter + rainf[i][j];
		}
		averagePerYear = sumQuarter/4;
		printf("Quarter %d average rain: %f\n", j, averagePerYear);
	}
	// Year Min and Max
	double minYear;
	double maxYear; 
	for (i = 0; i < NUM_YEARS; ++i)
	{	
		minYear = rainf[i][0];
		maxYear = rainf[i][0];
		for (j = 0; j < QUARTERS; ++j)
		{
			if(minYear > rainf[i][j])
				minYear = rainf[i][j];
			if(maxYear < rainf[i][j])
				maxYear = rainf[i][j];
		}
		printf("Year %d min rain: %f\n", i, minYear);
		printf("Year %d max rain: %f\n", i, maxYear);
	}	
	// Quarter Min and Max
	double minQuarter;
	double maxQuarter; 
	for (j = 0; j < QUARTERS; ++j)
	{	
		minQuarter = rainf[0][j];
		maxQuarter = rainf[0][j];
		for (i = 0; i < NUM_YEARS; ++i)
		{
			if(minQuarter > rainf[i][j])
				minQuarter = rainf[i][j];
			if(maxQuarter < rainf[i][j])
				maxQuarter = rainf[i][j];
		}
		printf("Quarter %d min rain: %f\n", j, minQuarter);
		printf("Quarter %d max rain: %f\n", j, maxQuarter);
	}
	return 0;
}

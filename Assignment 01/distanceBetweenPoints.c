#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 80

void err_sys (const char* message);

int main(int argc, const char* argv[])
{
	char userInput[MAX];
	char *stopString = NULL;
	double x1 = 0;
	double y1 = 0;
	double x2 = 0;
	double y2 = 0;
	double distance = 0;

	// user input
	printf("What is X1: ");
	scanf("%s", userInput);
	x1 = strtod(userInput, &stopString);

	printf("What is Y1: ");
	scanf("%s", userInput);
	y1 = strtod(userInput, &stopString);

	printf("What is X2: ");
	scanf("%s", userInput);
	x2 = strtod(userInput, &stopString);

	printf("What is Y2: ");
	scanf("%s", userInput);
	y2 = strtod(userInput, &stopString);
	// if(stopString != NULL)
	// {
	// 	err_sys("error when entering data.");
	// }

	distance = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)); 
	printf("Distance between two points on a circle: %f\n", distance);

	return 0;
}
void err_sys (const char* message)
{
  printf ("%s\n", message);
  exit (0);
}
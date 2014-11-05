#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// typedef struct
// {
// 	double height;
// 	double distance;
// 	double angle;
// 	double buildHeight;
// }computation;
#define MAX 80

void err_sys (const char* message);

int main(int argc, const char* argv[])
{
	// equation
	// bh = h + D × tan(θπ/180)
	char userInput[MAX];
	char *stopString = NULL;
	// char *check = NULL;
	double height = 0;
	double angle = 0;
	double distance = 0;

	// user input
	printf("What is the height of the person: ");
	scanf("%s", userInput);
	height = strtod(userInput, &stopString);
	// if(strcmp(check, stopString))
	// {
	// 	err_sys("error when entering the height of the person.");
	// }

	printf("What is the angle from the person to the top of the building: ");
	scanf("%s", userInput);
	angle = strtod(userInput, &stopString);
	// if(strcmp(check, stopString))
	// {
	// 	err_sys("error when entering the angle.");
	// }

	printf("What is the distance from the person to the building: ");
	scanf("%s", userInput);
	distance = strtod(userInput, &stopString);
	// if(strcmp(check, stopString))
	// {
	// 	err_sys("error when entering the distance.");
	// }

	double building = height + (distance*tan((angle*M_PI)/180)); 
	printf("Building Height: %f\n", building);

	return 0;
}
void err_sys (const char* message)
{
  printf ("%s\n", message);
  exit (0);
}
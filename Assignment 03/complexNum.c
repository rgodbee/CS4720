#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	double realpart;
	double imagpart;
} ComplexNum;

#define SIZE_OF_ARR 2

ComplexNum** addComplexNum(ComplexNum **x, ComplexNum **y);
ComplexNum** subtractComplexNum(ComplexNum **x, ComplexNum **y);
ComplexNum** multiplyComplexNum(ComplexNum **x, ComplexNum **y);
ComplexNum** divisionComplexNum(ComplexNum **x, ComplexNum **y);
void printComplexArray(ComplexNum **x);

int main()
{
	//input values
	// declare arrays
	ComplexNum *xComplexArray[SIZE_OF_ARR];
	ComplexNum *yComplexArray[SIZE_OF_ARR];
	// declare an array to hold the answer from the different opperations
	ComplexNum **answerComplexArray;
	int i;
	for (i = 0; i < SIZE_OF_ARR; ++i)
	{
		xComplexArray[i] = malloc(sizeof(ComplexNum));
		yComplexArray[i] = malloc(sizeof(ComplexNum));
	}
	
	// initialize arrayz
	xComplexArray[0]->realpart = 1.1;
	xComplexArray[0]->imagpart = 1.2;
	xComplexArray[1]->realpart = 2.3;
	xComplexArray[1]->imagpart = 0.5;

	yComplexArray[0]->realpart = 2;
	yComplexArray[0]->imagpart = 3;
	yComplexArray[1]->realpart = 4;
	yComplexArray[1]->imagpart = 3;

	// sum and print
	answerComplexArray = addComplexNum(xComplexArray, yComplexArray);
	printf("Adding Two Arrays:\n");
	printComplexArray(answerComplexArray);
	// differnce and print
	answerComplexArray = subtractComplexNum(xComplexArray, yComplexArray);
	printf("Subtracting Two Arrays:\n");
	printComplexArray(answerComplexArray);
	// multiply and print
	answerComplexArray = multiplyComplexNum(xComplexArray, yComplexArray);
	printf("Multipling Two Arrays:\n");
	printComplexArray(answerComplexArray);
	// division and print
	answerComplexArray = divisionComplexNum(xComplexArray, yComplexArray);
	printf("Dividing Two Arrays:\n");
	printComplexArray(answerComplexArray);

	return 0;
}
// +, -, *, /

ComplexNum** addComplexNum(ComplexNum** x, ComplexNum** y)
{
	ComplexNum **sumComplexNum;
	sumComplexNum = malloc(SIZE_OF_ARR * sizeof(ComplexNum*));
	int i;
	for(i = 0; i < SIZE_OF_ARR; i++)
	{
		sumComplexNum[i] = malloc(sizeof(ComplexNum));
		sumComplexNum[i]->realpart = x[i]->realpart + y[i]->realpart;
		sumComplexNum[i]->imagpart = x[i]->imagpart + y[i]->imagpart;
	}
	return sumComplexNum;
}

ComplexNum** subtractComplexNum(ComplexNum **x, ComplexNum **y)
{
	ComplexNum **subComplexNum;
	subComplexNum = malloc(SIZE_OF_ARR * sizeof(ComplexNum*));
	int i;
	for(i = 0; i < SIZE_OF_ARR; i++)
	{
		subComplexNum[i] = malloc(sizeof(ComplexNum));
		subComplexNum[i]->realpart = x[i]->realpart - y[i]->realpart;
		subComplexNum[i]->imagpart = x[i]->imagpart - y[i]->imagpart;
	}
	return subComplexNum;
}

ComplexNum** multiplyComplexNum(ComplexNum **x, ComplexNum **y)
{
	ComplexNum **multiComplexNum;
	multiComplexNum = malloc(SIZE_OF_ARR * sizeof(ComplexNum*));
	int i;
	for(i = 0; i < SIZE_OF_ARR; i++)
	{
		multiComplexNum[i] = malloc(sizeof(ComplexNum));
		multiComplexNum[i]->realpart = x[i]->realpart * y[i]->realpart;
		multiComplexNum[i]->imagpart = x[i]->imagpart * y[i]->imagpart;
	}
	return multiComplexNum;
}

ComplexNum** divisionComplexNum(ComplexNum **x, ComplexNum **y)
{
	ComplexNum **divComplexNum;
	divComplexNum = malloc(SIZE_OF_ARR * sizeof(ComplexNum*));
	int i;
	for(i = 0; i < SIZE_OF_ARR; i++)
	{
		divComplexNum[i] = malloc(sizeof(ComplexNum));
		divComplexNum[i]->realpart = x[i]->realpart / y[i]->realpart;
		divComplexNum[i]->imagpart = x[i]->imagpart / y[i]->imagpart;
	}
	return divComplexNum;
}

void printComplexArray(ComplexNum **x)
{
	int i;
	printf("Real Part\tImaginary Part\n");
	for(i = 0; i < SIZE_OF_ARR; i++)
	{
		printf("%f\t%f\n", x[i]->realpart, x[i]->imagpart);
	}
}
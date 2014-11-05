#include <stdio.h>
#include <gsl/gsl_linalg.h>
int main (void) {
	int row = 3; // number of rows in A
	int column = 3; // number of columns in A
	double matrixA[3][3]= {	{3.0, 5.0, 2.0}, 
							{2.0, 3.0, -1.0}, 
							{1.0, -2.0, -3.0} };
	double vectorB[3]= {8.0,1.0,-1.0};
	int i; int j; int s;
	gsl_matrix * mmat = gsl_matrix_alloc (row, column);
	gsl_vector * b = gsl_vector_alloc(column);
	gsl_vector *x = gsl_vector_alloc (column);
	// input values into matrixA
	for (i = 0; i < row; i++) 
	{
		for (j = 0; j < column; j++) 
		{
			gsl_matrix_set (mmat, i, j, matrixA[i][j]);
		}
	}
	// Input values into vectorB
	for (i = 0; i < column; i++) 
	{
		gsl_vector_set(b, i, vectorB[i]);
	}
	gsl_permutation * p = gsl_permutation_alloc (column);
	gsl_linalg_LU_decomp (mmat, p, &s);
	gsl_linalg_LU_solve (mmat, p, b, x);
	printf ("Solution Vector: \n");
	gsl_vector_fprintf (stdout, x, "%g");
	gsl_matrix_free (mmat);
	gsl_permutation_free (p);
	gsl_vector_free (x);
	return 0;
}
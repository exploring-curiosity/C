//3.Modify 11.22
/* calculate the sum of the elements in two tables of integers */
/* each 2-dimensional array is processed as an array
of pointers to a set of 1-dimensional integer arrays */
#include <stdio.h>
#include <stdlib.h>
#define MAXROWS 20
/* function prototypes */
void readinput (int *a[MAXROWS], int nrows, int ncols);
void compare(int *a[MAXROWS], int *b[MAXROWS],
int *c[MAXROWS], int nrows, int ncols);
void writeoutput(int *c[MAXROWS], int nrows, int ncols);
void main( )
{
int row, nrows, ncols;
/* pointer definitions */
int *a[MAXROWS], *b[MAXROWS], *c[MAXROWS];
printf( "How many rows? ");
scanf( "%d", &nrows);
printf("How many columns? ");
scanf("%d", &ncols);
/* allocate initial memory */
for (row = 0; row < nrows; ++row)
	{
	a[row] = (int *) malloc (ncols * sizeof(int));
	b[row] = (int *) malloc (ncols * sizeof(int));
	c[ row] = (int *) malloc (ncols * sizeof (int));
	}
printf("\nFirst table:\n");
readinput(a, nrows, ncols);
printf("\nSecond table:\n");
readinput(b, nrows, ncols);
compare(a, b, c, nrows, ncols);
printf ("\nTable of large elements:\n");
writeoutput(c, nrows, ncols); 
}
void readinput(int *a[MAXROWS], int m, int n)
/* read in a table of integers */
{
int row, col;
for (row = 0; row < m; ++row) 
	{
	printf("\nEnter data for row no. %2d\n", row + 1);
	for (col = 0; col < n; ++col)
		scanf("%d", (*(a + row) + col));
	}
return;
}
void compare(int *a[MAXROWS], int *b[MAXROWS], int *c[MAXROWS], int m, int n)
/* compare the elements of two integer tables */
{
int row, col;
for (row = 0; row < m; ++row)
	for (col = 0; col < n; ++col)
		*(*(c + row) + col) = (*(*(a + row) + col)>*(*(b + row) + col))?*(*(a + row) + col):*(*(b + row) + col);
return;
}
void writeoutput(int *a[MAXROWS], int m, int n)
/* write out a table of integers */
{
int row, col;
for (row = 0; row < m; ++row) 
{
	for (col = 0; col < n; ++col)
	printf("%4d", *(*(a + row) + col));
printf ("\n") ;
}
return; 
}

/*
How many rows? 3
How many columns? 4

First table:

Enter data for row no.  1
2 5 7 4

Enter data for row no.  2
3 5 7 3

Enter data for row no.  3
4 5 6 7

Second table:

Enter data for row no.  1
4 3 2 6

Enter data for row no.  2
7 6 5 3

Enter data for row no.  3
7 5 2 9

Table of large elements:
   4   5   7   6
   7   6   7   3
   7   5   6   9
*/


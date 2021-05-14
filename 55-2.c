/* personal finance calculations */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/* function prototypes */
void table (double (*pf)(double i,int m, double n), double a, int m,double n);
double md1(double i,int m, double n);
double md2(double i,int m, double n);
double md3(double i,int m, double n);
void main( ) /* calculate the future value of a series of monthly deposits */
{
int m,i; /* number of compounding periods per year */
double n; /* number of years */
double a; /* amount of each monthly payment */
char freq; /* frequency of compounding indicator */

/* enter input data */
printf("\nFUTURE VALUE OF A SERIES OF MONTHLY DEPOSITS\n");
printf("Amount of Each Monthly Payment: ");
scanf ("%lf", &a) ;
printf("Number of Years: ");
scanf ("%lf", &n) ;
printf("\t\t\tA = %.2lf\n\t\t\tn = %.2lf \n",a,n);
printf("\nInterest Rate = ");
for(i=5;i<=15;i++)
	{
	printf("     %d",i);
	printf("%%");
	printf("      ");
	}
printf("\n");
printf("Frequency of\nCompounding:\n");
i=0;
do 
	{	
		freq=i;
		if (freq == 0) 
			{
			m = 1;
			printf( "\nAnnual\nCompounding         " ) ;
			table(md1, a, m, n); /*Annual Compounding*/
			}
		if (freq == 1) 
			{
			m = 2;
			printf( "\nSemiannual\nCompounding         " );
			table(md1, a, m, n); /*Quarterly Compounding*/
			}

		if (freq == 2) 
			{
			m = 4;
			printf("\nQuarterly\nCompounding         ");
			table(md1, a, m, n);  /*Quarterly Compounding*/
			}
		if (freq == 3)
			{
			m = 12;
			printf("\nMonthly\nCompounding         ");
			table(md1, a, m, n); /*Monthly Compounding*/
			}
		if (freq == 4)
			{
			m = 360;
			printf("\nDaily\nCompounding         ");
			table(md2, a, m, n); /* daily compounding */
			}
		if (freq == 5)
			{
			m = 0;
			printf("\nContinuous\nCompounding         ");  /* continuous compounding */
			table(md3, a, m, n);
			}
		i++;
	}while(i<6);
}

void table (double (*pf)(double i, int m, double n), double a, int m, double n)
/* table generator (this function accepts a pointer to another function as an argument)
NOTE: double (*pf)(double i,int m, double n) is a POINTER TO A FUNCTION */
{
int count; /* loop counter */
double i; /* annual interest rate */
double f; /* future value */
for (count = 5; count <= 15; ++count) 
	{
	i= 0.01 * count;
	f = a * (*pf)(i, m, n); /* ACCESS THE FUNCTION PASSED AS A POINTER */
	printf("%-13.2f " ,f);
	}
printf("\n");
return;
}

double md1 (double i, int m, double n)
/* monthly deposits, periodic compounding */
{
double factor, ratio;
factor = 1 + i/m;
ratio = 12 * (pow(factor, m*n) - 1) / i;
return(ratio);
}

double md2(double i,int m, double n)
/* monthly deposits, daily compounding */
{
double factor, ratio;
factor = 1 + i/m;
ratio = (pow(factor, m*n) - 1) / (pow(factor, m/12) - 1);
return( ratio) ;
}

double md3(double i,int dummy, double n)
/* monthly deposits, continuous compounding */
{
double ratio;
ratio = (exp(i*n) - 1) / (exp(i/12) - 1);
return(ratio); 
}


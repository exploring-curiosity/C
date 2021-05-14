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
printf("\t\t");
for(i=5;i<=15;i++)
	{
	printf("    %d",i);
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
			printf( "Annual\nCompounding       " ) ;
			table(md1, a, m, n); /*Annual Compounding*/
			}
		if (freq == 1) 
			{
			m = 2;
			printf( "Semiannual\nCompounding       " );
			table(md1, a, m, n); /*Quarterly Compounding*/
			}

		if (freq == 2) 
			{
			m = 4;
			printf("Quarterly\nCompounding       ");
			table(md1, a, m, n);  /*Quarterly Compounding*/
			}
		if (freq == 3)
			{
			m = 12;
			printf("Monthly\nCompounding       ");
			table(md1, a, m, n); /*Monthly Compounding*/
			}
		if (freq == 4)
			{
			m = 360;
			printf("Daily\nCompounding       ");
			table(md2, a, m, n); /* daily compounding */
			}
		if (freq == 5)
			{
			m = 0;
			printf("Continuous\nCompounding       ");  /* continuous compounding */
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
	printf("%-12.2f " ,f);
	}
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

/*
FUTURE VALUE OF A SERIES OF MONTHLY DEPOSITS
Amount of Each Monthly Payment: 100
Number of Years: 2
                    5%          6%          7%          8%          9%          10%          11%          12%          13%          14%          15%
Frequency of
Compounding:
Annual
Compounding       2460.00      2472.00      2484.00      2496.00      2508.00      2520.00      2532.00      2544.00      2556.00      2568.00      2580.00      Semiannual
Compounding       2491.51      2510.18      2528.97      2547.88      2566.91      2586.07      2605.36      2624.77      2644.30      2663.97      2683.75      Quarterly
Compounding       2507.67      2529.85      2552.26      2574.89      2597.75      2620.83      2644.15      2667.70      2691.48      2715.51      2739.77      Monthly
Compounding       2518.59      2543.20      2568.10      2593.32      2618.85      2644.69      2670.86      2697.35      2724.17      2751.32      2778.81      Daily
Compounding       2518.84      2543.56      2568.60      2593.97      2619.69      2645.74      2672.14      2698.90      2726.01      2753.48      2781.33      Continuous
Compounding       2518.85      2543.57      2568.62      2594.00      2619.72      2645.78      2672.19      2698.95      2726.07      2753.56      2781.41   
*/

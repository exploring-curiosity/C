/* personal finance calculations */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

float s[20][20];

int x=0,y=0; 
/* function prototypes */
void table (double (*pf)(double i,int m, double n), double a, int m,double n);
double md1(double i,int m, double n);
double md2(double i,int m, double n);
double md3(double i,int m, double n);
void main( ) /* calculate the future value of a series of monthly deposits */
{
int m,i,k;/* number of compounding periods per year */
double n; /* number of years */
double a; /* amount of each monthly payment */
char freq; /* frequency of compounding indicator */


/* enter input data */
printf("\nFUTURE VALUE OF A SERIES OF MONTHLY DEPOSITS\n");
printf("Amount of Each Monthly Payment: ");
scanf ("%lf", &a) ;
printf("Number of Years: ");
scanf ("%lf", &n) ;
i=0;
do 
	{	
		freq=i;
		if (freq == 0) 
			{
			m = 1;
			printf( " Annual Compounding" ) ;
			table(md1, a, m, n); /*Annual Compounding*/
			}
		if (freq == 1) 
			{
			m = 2;
			printf( " Semiannual Compounding" );
			table(md1, a, m, n); /*Quarterly Compounding*/
			}

		if (freq == 2) 
			{
			m = 4;
			printf(" Quarterly Compounding");
			table(md1, a, m, n);  /*Quarterly Compounding*/
			}
		if (freq == 3)
			{
			m = 12;
			printf(" Monthly Compounding");
			table(md1, a, m, n); /*Monthly Compounding*/
			}
		if (freq == 4)
			{
			m = 360;
			printf(" Daily Compounding");
			table(md2, a, m, n); /* daily compounding */
			}
		if (freq == 5)
			{
			m = 0;
			printf(" Continuous Compounding\n");  /* continuous compounding */
			table(md3, a, m, n);
			}
		i++;
	}while(i<6);
	for(i=5;i<16;i++)
	{
		printf("     %d",i);
		printf("%%");
		printf("      ");
		for(k=0;k<6;k++)
		printf("       %-12.2f  ",s[k][i]);
		printf("\n");
	}
}
void table (double (*pf)(double i, int m, double n), double a, int m, double n)
/* table generator (this function accepts a pointer to another function as an argument)
NOTE: double (*pf)(double i,int m, double n) is a POINTER TO A FUNCTION */
{
int count; /* loop counter */
double i; /* annual interest rate */
double f; /* future value */
y=0;
for (count = 5; count <= 15; ++count,y++) 
	{
	i= 0.01 * count;
	f = a * (*pf)(i, m, n); /* ACCESS THE FUNCTION PASSED AS A POINTER */
	//printf("%-13.2f " ,f);
	s[x][count]=f;


	}
	x++;
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

/*FUTURE VALUE OF A SERIES OF MONTHLY DEPOSITS
Amount of Each Monthly Payment: 100
Number of Years: 2

Interest Rate  Annual Compounding Semiannual Compounding Quarterly Compounding Monthly Compounding Daily Compounding Continuous Compounding
     5%             2460.00              2491.51              2507.67              2518.59              2518.84              2518.85
     6%             2472.00              2510.18              2529.85              2543.20              2543.56              2543.57
     7%             2484.00              2528.97              2552.26              2568.10              2568.60              2568.62
     8%             2496.00              2547.88              2574.89              2593.32              2593.97              2594.00
     9%             2508.00              2566.91              2597.75              2618.85              2619.69              2619.72
     10%             2520.00              2586.07              2620.83              2644.69              2645.74              2645.78
     11%             2532.00              2605.36              2644.15              2670.86              2672.14              2672.19
     12%             2544.00              2624.77              2667.70              2697.35              2698.90              2698.95
     13%             2556.00              2644.30              2691.48              2724.17              2726.01              2726.07
     14%             2568.00              2663.97              2715.51              2751.32              2753.48              2753.56
     15%             2580.00              2683.75              2739.77              2778.81              2781.33              2781.41
     */
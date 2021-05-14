#include<stdio.h>
#include<stdlib.h>
int len1,len2;
void count(char *a,char *b,int *n);
void main()
{
	char *c,*s;
	c=(char*)malloc(100*sizeof(char));
	s=(char*)malloc(100*sizeof(char));
	int i=0,*n,m;
	n=&m;
	*n=0;
	printf("Enter the line\n");	
	do
	{
		scanf("%c",c+i);
		i++;
	}while(*(c+i-1)!='\n');
	
	len1=i-1;
	*(c+i-1)='\0';		
	
	printf("Enter the word\n");	
	i=0;	
	do
	{
		scanf("%c",s+i);
		i++;
	}while(*(s+i-1)!='\n');
	len2=i-1;
	*(s+i-1)='\0';
	
	
	count(c,s,n);
	printf("count=%d\n",*n);
	
}
void count(char *a,char *b,int *n)
{
int i=0,j=0,l=0;
for(i=0;*(a+i)!='\0';i++)
{
	if(*(a+i)==*b)
	{
		l=0;
		for(j=0;*(b+j)!='\0';j++)
		{	
			if((*(a+i+j))==(*(b+j)))
			l++;
		}
		if(l==len2)
			(*n)++;
	}
}
}
/*
Enter the line
hello world hello everyone
Enter the word
hello
count=2
*/



#include<stdlib.h>
#include<stdio.h>
void main()
{
	char *a,(*b)[500];
	a=(char*)malloc(200*sizeof(char));

	int i=0,j=0,n=0,len;
	printf("enter the text input\n");
	while(i>=0)
	{
		scanf("%c",a+i);
		if(*(a+i)=='\n'||*(a+i)=='.'||*(a+i)==' '||*(a+i)==',')
		n++;
		if(*(a+i)=='.'&&*(a+i-1)=='.')
		{
			n--;
			break;
		}
		i++;
	}
	printf("\n");
	b=malloc(n*sizeof(char));
	len=i;
	*(a+i)='\0';
	i=0;
	n=0;
	for(i=0;i<len;i++,j++)
	{
		if(*(a+i)==' '||*(a+i)=='.'||*(a+i)==','||*(a+i)=='\n')
		{
			(*(b+j))[n]='.';
			n++;
			j=-1;
		}
		else
		(*(b+j))[n]=*(a+i);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;(*(b+j))[i]!='.';j++)
		{
			printf("%c",(*(b+j))[i]);
		}
		printf("\n");
	}
}
/*
enter text input
hi hello
im sudharshan..
hi
hello
im
sudharshan
*/


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




#include<stdio.h>
#include<stdlib.h>
long convert(int mm,int dd,int yy);
void main()
{
	long *a,*b,j,k;
	int *m,*y,*d,mm,yy,dd;
	a=&j;
	b=&k;
	m=&mm;
	y=&yy;
	d=&dd;
	printf("enter 1st date dd /mm /yy:");
	scanf("%d%d%d",d,m,y);
	*a=convert(*m,*d,*y);//calculates date1 from base date
	printf("enter 2nd date dd /mm /yy:");
	scanf("%d%d%d",d,m,y);
	*b=convert(*m,*d,*y);//calculates date2 from base date
	int c=*b-*a;
	if(c>0)
	printf("days=%d",c);
	else
	printf("days=%d",-1*c);
	//we get their difference as output
}

long convert(int mm,int dd,int yy)		//count no of days from base date
{
	long ndays;
	long ncycles;
	int nyears;
	int day;
	yy-=1900;
	ndays=(long)(30.42*(mm-1))+dd;
	if(mm==2)
	++ndays;
	if((mm>2)&(mm<8))
	--ndays;
	if((yy%4==0)&&mm>2)
	++ndays;
	ncycles=yy/4;
	ndays+=ncycles*1461;
	nyears=yy%4;
	if(nyears>0)
	ndays+=365*nyears+1;
	if(ndays>59)
	--ndays;
	return ndays;			//returns the specified value of number of days
}
/*
enter 1st date dd /mm /yy:23 5 1987
enter 2nd date dd /mm /yy:28 9 1996
days=3416
*/




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
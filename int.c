#include<stdio.h>
void main()
{
	float *a,s;
	int *b,c;
	a=&s;
	b=&c;
	printf("enter the number: ");
	scanf("%f",a);
	*b=*a;
	printf("the integer is %d",*b);
}
#include<stdio.h>
void main()
{
	char *a,s;
	int b;
	a=&s;
	printf("enter the input:");
	scanf("%c",a);
	b=*a;
	if (b>=47 && b<=58)
	printf("it is a number");
	else if(b>=65 && b<=90)
	printf("it is upper case");
	else if(b>=97 && b<=122)
	{printf("It is lowercase\n");
		b-=32;
		printf("the uppercase is %c",b);
	}
}
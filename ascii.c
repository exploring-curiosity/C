#include<stdio.h>
void main()
{
	char s;
	char *a;
	a=&s;
	printf("enter the character:");
	scanf("%c",a);
	printf("the ascii value is %d",*a);
	if(*a>=97)
	*a-=32;
	printf("%c",*a);
}
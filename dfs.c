#include<stdio.h>
void main()
{
	char c[100],b[100],a;int i=0;
	printf("Enter the 1st line:");
	do
	{
		scanf("%c",&a);
		if(a!='\n')
		c[i]=a;
		i++;
	}while(a!='\n');
	int l1,l2;
	l1=i-1;
	i=0;
	
	printf("Enter the 2nd line:");
	do
	{
		scanf("%c",&a);
		if(a!='\n')
		b[i]=a;
		i++;
	}while(a!='\n');
	l2=i-1;
	if(l1==l2)
	for(i=0;c[i]!='\0';i++)
	

	

}
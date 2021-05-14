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
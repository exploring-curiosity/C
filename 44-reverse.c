#include<stdio.h>
void main()
{int i=0;
	char c[100],temp;
	printf("enter the line :");
	do
	{	c[i]=getchar();
		i++;
	}while(c[i-1]!='\n');
int len;
len=i-1;
for(i=0;i<len/2+1;i++)
{ 
	temp=c[i];
	c[i]=c[len-i];
	c[len-i]=temp;

}
printf("%s",c);
}
/*
enter the line :hello world

dlrow olleh
*/
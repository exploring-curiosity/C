#include<stdio.h>
#include<stdlib.h>
void main()
{
	char s[100],e[100],d[100],a;
	int i=0,n,n1,n2,size,ar[100];
	n=rand();
	printf("enter the string :");
	do
	{	
		scanf("%c",&a);
		if(a!='\n')
		s[i]=a;
		i++;
	}while(a!='\n');
	size=i-1;
	for(i=0;s[i]!='\0';i++)
	ar[i]=s[i];
	n2=0;
	n1=ar[0];
	for(i=0;s[i]!='\0';i++)
	{
		if(n2<ar[i])
		{
			n2=ar[i];
		}
		if(n1>ar[i])
		{
			n1=ar[i];
		}
	}
	int t;
	for(i=0;s[i]!='\0';i++)
	{
		ar[i]+=n;
		if(n>n2)
		{ 
			t=n%n2;
			ar[i]=n1+t;
		}
	}
	for(i=0;s[i]!='\0';i++)
	{
		e[i]=ar[i];
	}e[i]='\0';
printf("encoded :%s\n",e);
int k,b[100],r;
for(i=0;i<size;i++)
{
	k=ar[i];
	r=n/n2;
	b[i]=ar[i]-n1+r*n2-n;
	
}
for(i=0;s[i]!='\0';i++)
	{
		d[i]=97+b[i];
	}
	d[i]='\0';
printf("decoded :%s \n",d);		
}
/*
enter the string :sudharshan
encoded :£₧ìæè¢£æèù
decoded :sudharshan
*/
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




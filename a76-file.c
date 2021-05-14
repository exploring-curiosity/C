#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include"input.h"
//main function
void main()
{
	FILE *a,*c;
	char ch,s[100],prev;
	int i=1,l,n;
	printf("enter the value of n:");
	scanf("%d",&n);
	//reading file
	a=fopen("input.txt","r");
	c=fopen("copy.txt","w+");
	//checking for existence
	if(a==NULL)
	{
		printf("file not found");
		exit(1);
	}
	//checking for existence
	if(c==NULL)
	{
		printf("file not found");
		exit(1);
	}
	//finding length of file
	while(!feof(a))
	{ 
		ch=fgetc(a);
		if(!feof(a))
		i++;		
	}
	fseek(a,0,0);
	l=i/2;//the vaue of m is l
	i=0;
	printf("%d\n",l);
	//writing from -n to +n from m
	while(!feof(a))
	{
		i++;
		ch=fgetc(a);
		if((i>=l-n)&(i<=l+n))
		{
			fprintf(c,"%c",ch);
		}
		
	}
	//output
	fseek(c,0,0);
	input(c);
	fclose(a);
	fclose(c);
}
/*
PS F:\> gcc a76-file.c -o k
PS F:\> ./k
enter the value of n:7
44
s is c programm
PS F:\>
*/
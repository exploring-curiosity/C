#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include"input.h"
//main function
void main()
{
	FILE *a,*b;
	char ch,s[100],prev;
	int l=0,w=0,c=0,ws=0,d=0;
	//reading file
	a=fopen("input.txt","r");
	b=fopen("sample.txt","w+");
	//checking for existence
	if(a==NULL)
	{
		printf("file not found");
		exit(1);
	}
		//checking for existence
	if(b==NULL)
	{
		printf("file not found");
		exit(1);
	}//copying
	while(!feof(a))
	{ 
		fscanf(a,"%c",&ch);
		if(!feof(a))
		{
			fprintf(b,"%c",ch);
		}
		prev=ch;
	}
	//output
	fseek(b,0,0);
	input(b);
	fclose(a);
	fclose(b);
}
/*
PS F:\> gcc a74-file.c -o k
PS F:\> ./k
hello everyone.
welcome to 2019.
This is c programming.
we are handling files in c
c is fun.
*/
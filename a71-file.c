#include<stdio.h>
#include<stdlib.h>
//main function
void main()
{
	FILE *a;
	char ch,s[100];
	//reading file
	a=fopen("input.txt","r");
	//checking existence
	if(a==NULL)
	{
		printf("file not found");
		exit(1);
	}
	//reading and printing
	while(!feof(a))
	{ 
		fscanf(a,"%c",&ch);
		if(!feof(a))
		{
			printf("%c",ch);
		}
	}
	fclose(a);//closeing
}
/*
PS F:\> gcc a71-file.c -o k
PS F:\> ./k
hello everyone.
welcome to 2019.
This is c programming.
we are handling files
c is fun.
*/


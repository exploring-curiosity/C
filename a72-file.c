#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include"input.h"
//main function
void main()
{
	FILE *a;
	char ch,s[100];
	int c=0,ws=0,d=0;
	//reading file
	a=fopen("input.txt","r");
	//checking file existence
	if(a==NULL)
	{
		printf("file not found");
		exit(1);
	}
	//processing
	while(!feof(a))
	{ 
		fscanf(a,"%c",&ch);
		if(!feof(a))
		{
			if(isalpha(ch))
			c++;
			else if(isdigit(ch))
			d++;
			else if(isspace(ch))
			ws++;
		}
	}
	printf("characters: %d  white spaces: %d  digits: %d\n",c,ws,d);
	fclose(a);
}
/*
PS F:\> gcc a72-file.c -o k
PS F:\> ./k
characters: 67  white spaces: 17  digits: 4
*/
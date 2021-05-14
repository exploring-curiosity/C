#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include"input.h"
//main function
void main()
{
	FILE *a;
	char ch,s[100],prev;
	//reading file
	a=fopen("input.txt","r+");
	
	fseek(a,0,0);
	//checking for existence
	if(a==NULL)
	{
		printf("file not found");
		exit(1);
	}
	//replacing vowels with z
	while(!feof(a))
	{ 
		ch=fgetc(a);
		if(!feof(a))
		{
			if((ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u'))
			{
				fseek(a,-1,1);
				fprintf(a,"z");
				fseek(a,1,1);
			}	
		}
		
	}
	//output
	fseek(a,0,0);
	input(a);
	fclose(a);
}
/*
PS F:\> gcc a75-file.c -o k
PS F:\> ./k
hzllz zvzryznz.
wzlczmz tz 2019.
Thzs zs c przgrzmmzng.
wz zrz hzndlzng fzlzs zn c
c zs fzn.
*/

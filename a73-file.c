#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include"input.h"
//main function
void main()
{
	FILE *a;
	char ch,s[100],prev;
	int l=0,w=0,c=0,ws=0,d=0;
	//reading file
	a=fopen("input.txt","r");
	//checking for existence
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
			if(ch=='\n')//counting new lines
			l++;
			if(ch==' '||ch=='.'||ch=='\n'||ch==',')
			{
				if(!(prev==' '||prev=='.'||prev=='\n'||prev==','))//counting words
				w++;
			}

			if(isalpha(ch))
			c++;
			else if(isdigit(ch))
			d++;
			else if(isspace(ch))
			ws++;
		}
		prev=ch;
	}
	l++;
	w++;
	//output
	printf("lines: %d  words: %d  characters: %d  white spaces: %d  digits: %d\n",l,w,c,ws,d);
	fclose(a);
}
/*
PS F:\> gcc a73-file.c -o k
PS F:\> ./k
lines: 5  words: 19  characters: 67  white spaces: 17  digits: 4
*/
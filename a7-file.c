#include<stdio.h>
#include<ctype.h>
void main()
{
	FILE *a;
	char ch,s[100];
	int c=0,ws=0,d=0;
	a=fopen("out.txt","w+");
	printf("enter the statement");
	gets(s);
	fprintf(a,"%s",s);
	fseek(a,0,0);
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
PS F:\> gcc a7-file.c -o k
PS F:\> ./k
enter the statementhello world. welcome to 2019
characters: 19  white spaces: 4  digits: 4
PS F:\>
*/
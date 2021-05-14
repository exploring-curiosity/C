#include<stdio.h>
void main()
{
	FILE *a;
	char ch,s[100];
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
			printf("%c",ch);
		}
	}
	fclose(a);
}
/*
PS F:\> gcc cfile.c -o k
PS F:\> ./k
enter the statementhello hai
hello hai
*/
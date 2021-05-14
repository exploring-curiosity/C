#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"input.h"
//main function
void main()
{
	FILE *a;
	int i=0,count=0,k=0,l1,l2,n=0;
	char s1[100],s2[100],ch;
	strcpy(s1,"chennai");
	strcpy(s2,"tamilnadu");
	l1=strlen(s1);
	l2=strlen(s2);
	//reading file
	a=fopen("text.txt","r+");
	fpos_t pi,p,pf;
	fgetpos(a,&pi);
	fseek(a,0,2);
	fgetpos(a,&pf);
	p=pf;
	fseek(a,0,0);
	//searching thro file
	while(!feof(a))
	{
		fgetpos(a,&p);
		ch=fgetc(a);
		if(!feof(a))
		{
			for(i=0;i<l1;i++)
			{
				//checking for occurence of chennai
				if(s1[i]==ch)
				{
					ch=fgetc(a);
				}
				else
				{
					k=1;	
				}
			}
			if(k==0)
			{
				//displacing all following characers by 2
				pi=p;
				fseek(a,-1,2);
				fgetpos(a,&p);
				while(pi!=p)
				{
					ch=fgetc(a);
					fseek(a,-1,1);
					fputc(' ',a);
					fputc(' ',a);
					fputc(ch,a);
					fseek(a,-4,1);
					fgetpos(a,&p);
				}
				//wirting tamilnadu which overwrite c  hennai
				for(i=0;i<l2;i++)
				{
					fputc(s2[i],a);
				}
				fsetpos(a,&p);
				fseek(a,l2,1);

			}
			k=0;			
		}
	}//output
	fseek(a,0,0);
	input(a);
	fclose(a);
}/*
PS F:\> gcc a78-file.c -o k
PS F:\> ./k
this is ssn college of engineering at tamilnadu.tamilnadu is otherwise called as singara tamilnadu.
PS F:\>
*/
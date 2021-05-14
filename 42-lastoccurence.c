#include<stdio.h>
void main()
{
	int i=0,j;
	int l=0,k=0,e=0;
	char a,c[100],s[100];
	printf("enter the line :");
	do
	{	c[i]=getchar();
		i++;
	}while(c[i-1]!='\n');
int len;
len=i-1;
printf("\n");
i=0;
printf("enter the subline :");
	do
	{	s[i]=getchar();
		i++;
	}while(s[i-1]!='\n');
int len1;
len1=i-1;

printf("\n");




for(i=len-1;i>=0;i--)
{   

	k=0;
	if(c[i]==s[len1-1])
	{for(j=len1-1,e=0;j>=0;j--,e++)
	{if(s[j]==c[i-e])
	{
		k++;
	}
	
	if(k==len1)
	{l=1;
		printf("last occurence is %d",i-len1+1);
	break;}
	}
	if(l==1)
	break;
}
}
}
/*
enter the line :hello world hello

enter the subline :hello

last occurence is 12
*/

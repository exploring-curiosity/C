#include<stdio.h>
void main()
{
	int i=0,j,lo=-1,f=0;
	int l=0,k=0,e=0;
	char a,c[100],s[100],p[100];
	printf("enter the line :");
	do
	{	c[i]=getchar();
		i++;
	}while(c[i-1]!='\n');
int len;
len=i-1;
i=0;
printf("enter the subline(part of line) to be replaced:");
	do
	{	s[i]=getchar();
		i++;
	}while(s[i-1]!='\n');
int len1;
len1=i-1;
i=0;
printf("enter the line to be overwritten :");
	do
	{	p[i]=getchar();
		i++;
	}while(p[i-1]!='\n');
int len2;
len2=i-1;
for(i=0;i<len;i++)
{
	k=0;
	if(c[i]==s[0])
	{for(j=0,e=0;j<len1;j++,e++)
	{if(s[j]==c[i+e])
	{
		k++;
	}
	}
	e=0;
	if(k==len1)
	{
		
		lo=i;
	}
	
	
}}
	for(i=lo;i<len-len1;i++)
	{
		c[i]=c[i+len1];
	}
	c[i]='\0';	
	

	for(i;i>=lo;i--)
	{
		c[i+len2]=c[i];
	}
	for(i=lo;i<lo+len2;i++)
	{
		c[i]=p[i-lo];
	}
c[len-len1+len2]='\0';
printf("%s\n",c);
}
/*
enter the line :sudharshan
enter the subline(part of line) to be replaced:shan
enter the line to be overwritten :san
sudharsan
*/
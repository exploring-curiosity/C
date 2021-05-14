#include<stdio.h>
void count(char *a,char *b,int *n);
void main()
{	char a[100],b[100];
	char *c=&a,*s=&b;
	int i=0,*n,m;
	n=&m;
	printf("Enter the line\n");	
	do
	{
		scanf("%c",c+i);
		i++;
	}while(*(c+i-1)!='\n');
	extern int len1,len2;
	len1=i-1;
	*(c+i-1)='\0';		
	
	printf("Enter the word\n");	
	i=0;	
	do
	{
		scanf("%c",s+i);
		i++;
	}while(*(s+i-1)!='\n');
	len2=i-1;
	*(s+i-1)='\0';
	count(c,s,n);
	printf("count=%d\n",*n);
	
}
void count(char *a,char *b,int *n)
{int i;
for(i=0;i<len1;i++)
{

if(*(a+i)==*b)
{
for(j=0;j<len2;j++)
{if(*(a+i+j)==*(b+j))
l++;
}
if(l==len2)
*n++;



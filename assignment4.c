//1. simple string operations
#include<stdio.h>
#include<string.h>

void Strcat(char str1[],char str2[]);
void Strncpy(char dest[],char src[],int n);
int Strchr(char str[],char ch);
void main()
{
	int i=0,n;
	char str1[100],str2[100],a;
	line:
	i=0;
	printf("choose operation\n1.strcat\n2.strncpy\n3.strchr\n");
	scanf("%d",&n);
	if(n==1)
	{   scanf("%c",&str1[0]);
		printf("enter the string 1:");
		do
		{	

			scanf("%c",&str1[i]);
			i++;
		}while(str1[i-1]!='\n');
		i=0;

		printf("enter the string 2:");
		do
		{	str2[i]=getchar();
			i++;
		}while(str2[i-1]!='\n');
		Strcat(str1,str2);
		printf("concatenated string :%s\n",str1);
	}
	else if(n==2)
	{ int m;
		i=0;
		scanf("%c",&str1[0]);
		printf("enter the string :");
		do
		{	
			scanf("%c",&str1[i]);
			i++;
		}while(str1[i-1]!='\n');
		printf("enter size to be copied :");
		scanf("%d",&m);
		Strncpy(str2,str1,m);
		printf("copied string :%s\n",str2);

	}
	else if(n==3)
	{
		int m;
		char ch;
		scanf("%c",&str1[0]);
		printf("enter the string :");
		do
		{	
			scanf("%c",&str1[i]);
			i++;
		}while(str1[i-1]!='\n');
		printf("enter the character:");
		scanf(" %c",&ch);
		m=Strchr(str1,ch);
		if(m>-1)
		printf("found at position %d\n",m);
		else
		printf("not fount\n");
		
	}
	else
	{
		printf("invalid\n");
		goto line;
	}
	printf("do u want to continue y/n:");
	scanf(" %c",&a);
	if(a=='y')
	goto line;
}
void Strcat(char str1[],char str2[])
{
	int i,l1,l2;
	l1=strlen(str1);
	l2=strlen(str2);
	for(i=0;i<l2;i++)
	{
		str1[l1+i-1]=str2[i];
	}
}
void Strncpy(char dest[],char src[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		dest[i]=src[i];
	}
	dest[i]='\0';
}
int Strchr(char str[],char ch)
{
	int i;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]==ch)
		return i;
	}
	return -1;
}
/*

choose operation
1.strcat
2.strncpy
3.strchr
1
enter the string 1:sudhar
enter the string 2:shan
concatenated string :sudharshan

do u want to continue y/n:y
choose operation
1.strcat
2.strncpy
3.strchr
2
enter the string :sudharshan
enter size to be copied :5
copied string :sudha
do u want to continue y/n:y
choose operation
1.strcat
2.strncpy
3.strchr
3
enter the string :sudharshan
enter the character:a
found at position 4
do u want to continue y/n:n
*/

//2.last occurence of a substring

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

//3.replacing a substring

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

//4.reversing a string

#include<stdio.h>
void main()
{int i=0;
	char c[100],temp;
	printf("enter the line :");
	do
	{	c[i]=getchar();
		i++;
	}while(c[i-1]!='\n');
int len;
len=i-1;
for(i=0;i<len/2+1;i++)
{ 
	temp=c[i];
	c[i]=c[len-i];
	c[len-i]=temp;

}
printf("%s",c);
}
/*
enter the line :hello world

dlrow olleh
*/

//5.encoding and decoding a string

#include<stdio.h>
#include<stdlib.h>
void main()
{
	char s[100],e[100],d[100],a;
	int i=0,n,n1,n2,size,ar[100];
	n=rand();
	printf("enter the string :");
	do
	{	
		scanf("%c",&a);
		if(a!='\n')
		s[i]=a;
		i++;
	}while(a!='\n');
	size=i-1;
	for(i=0;s[i]!='\0';i++)
	ar[i]=s[i];
	n2=0;
	n1=ar[0];
	for(i=0;s[i]!='\0';i++)
	{
		if(n2<ar[i])
		{
			n2=ar[i];
		}
		if(n1>ar[i])
		{
			n1=ar[i];
		}
	}
	int t;
	for(i=0;s[i]!='\0';i++)
	{
		ar[i]+=n;
		if(n>n2)
		{ 
			t=n%n2;
			ar[i]=n1+t;
		}
	}
	for(i=0;s[i]!='\0';i++)
	{
		e[i]=ar[i];
	}e[i]='\0';
printf("encoded :%s\n",e);
int k,b[100],r;
for(i=0;i<size;i++)
{
	k=ar[i];
	r=n/n2;
	b[i]=ar[i]-n1+r*n2-n;
	
}
for(i=0;s[i]!='\0';i++)
	{
		d[i]=97+b[i];
	}
	d[i]='\0';
printf("decoded :%s \n",d);		
}
/*
enter the string :sudharshan
encoded :£₧ìæè¢£æèù
decoded :sudharshan
*/
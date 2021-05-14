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
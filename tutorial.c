#include<stdio.h>
#include<string.h>
void main()
{
	char s[100][100],temp[100];
	int i,n,j;
	printf("enter the number of students :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{printf("\nname %d:",i+1);
	scanf("%s",s[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(strcmpi(s[j],s[j+1])>0)
			{
				strcpy(temp,s[j+1]);
				strcpy(s[j+1],s[j]);
				strcpy(s[j],temp);
			}
		}
	
	}
	for(i=0;i<n;i++)
	{printf("%s\n",s[i]);}
}
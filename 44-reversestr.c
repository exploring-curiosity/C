#include<stdio.h>
#include<string.h>
void main()
{
	char a[100];
	printf("enter a line:");
	gets(a);
int t,k,i=0;
	k=strlen(a);
for(i=0;i<=k/2;i++)
	{
		t=a[i];
		a[i]=a[k-i-1];
		a[k-i-1]=t;
	}
printf("%s",a);
}
/*
enter a line:yeshwanth
htnawhsey
*/
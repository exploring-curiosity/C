#include<stdio.h>
#include<string.h>
void main()
{
	int n;
	printf("enter the no.of terms:");
	scanf("%d",&n);
	int a[n],k,d,s,m,j,i=0;
	for(i=0;i<n;i++)
	{
		printf("enter the number:");
		scanf("%d",&a[i]);
	}
	printf("enter the number to be changed:");
	scanf("%d",&k);
	printf("enter the number to be added:");
	scanf("%d",&d);
	m=n;
	for(i=0;i<n;i++)
	{	
		if(a[i]==k)
		{s=i;
		for(j=n;j>s+1;j--)
		a[j]=a[j-1];
	    	a[s+1]=d;
		m++;
		 }
n=m;
	}
for(i=0;i<m;i++)
printf("%d",a[i]);
}
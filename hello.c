#include<stdio.h>
float avg(int b[],int m);
void main()
{
	int a[20],n,i;
	float av;
	printf("enter the no. of terms :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
 	{
	 	scanf("%d",&a[i]);
 	}
 	//printf("%d,%d",a[2],a[4]);
 	av=avg(a,n);
 	printf("average=%f",av);		
}
float avg(int b[],int m)
{
	float sum=0;
	int i;
	for(i=0;i<m;i++)
	sum+=b[i];
	return sum/m;	
}
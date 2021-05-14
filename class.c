#include<stdio.h>
#include<stdlib.h>
void main()
{
	int *p,n,i,j,temp;
	printf("enter the size of the array");
	scanf("%d",&n);
	p=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",p+i);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(*(p+j)>*(p+j+1))
			{
				temp=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=temp;
			}
		}
	}
	for(j=0;j<n;j++)
	{
		printf("%d\n",*(p+j+1));
	}
		
			



}
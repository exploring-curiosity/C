#include<stdio.h>
void main()
{
	int n,x,y,i,j;
	float a[100][100],b[100][100];
	printf("enter the size of the array :");
	scanf("%d",&n);
	printf("enter a non singular matrix\n  ");
	for(i=0;i<n;i++)
	{
		printf(" %d",i);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",i);
		for(j=0;j<n;j++)
		{
			scanf("%f",&a[i][j]);
		}
	//printf("\n");
	}
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			if(j==i)
				b[i][j]=1;
			else
				b[i][j]=0;
		}	
	}

	int k;
	for(i=0;i<n;i++)
	{
		if(a[i][i]==0)
		{
			for(j=0;j<n;j++)
			{
				if(a[j][i]!=0)
				{
					for(k=0;k<n;k++)
					{
						a[i][k]+=a[j][k];
						b[i][k]+=b[j][k];
						
					}
					break;
				}
			}
		}
	}
	float c;
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			if(i!=j)
			{
				c=a[i][j]/a[j][j];
				for(k=0;k<n;k++)
				{
					a[i][k]=c*a[j][k]-(a[i][k]);
					b[i][k]=c*b[j][k]-(b[i][k]);
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]/=a[i][i];
			b[i][j]/=a[i][i];
		}
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%-.2f ",b[i][j]);
		}

	printf("\n");
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%-.2f ",a[i][j]);
		}

	printf("\n");
	}
	
}
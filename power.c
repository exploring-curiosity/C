#include<stdio.h>
float power(float x,int n)
{
float y=1;
for(int i=1;i<=n;i++)
	{
	y=y*x;
	}
return y;
}
int main()
{
int N;
float number;
printf("Enter Number:");
scanf("%f",&number);
printf("\nEnter power to raise to:");
scanf("%d",&N);
float answer;
answer=power(number,N);
printf("\nThe answer is= %f\n",answer);
return 0;
}

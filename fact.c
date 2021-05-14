#include<stdio.h>
int facto(int n);
void main()
{
int n,i,d;
printf("enter the number :");
scanf("%d",&n);
d=facto(n)%10;
printf("digit : %d",d);
}
int facto(int n)
{
int i,fact=1;
if(n==n%10)
{for(i=2;i<=n;i++)
 fact*=1;
 return fact;
}
else if(n%2==0)
return 	6*facto(n/5)*facto(n%10);
else
return 4*facto(n/5)*facto(n%10);
}

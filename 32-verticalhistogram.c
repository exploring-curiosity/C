#include<stdio.h>
void main()
{
int i,n,ar[100],b[9],j,max=0;
printf("enter the number of terms :");
scanf("%d",&n);

for(i=0;i<n;i++)
{
printf("enter the number:");
scanf("%d",&j);
 ar[i]=j;
}
for(i=0;i<=9;i++)
{b[i]=0;
 for(j=0;j<n;j++)
  {if(ar[j]==i)
   b[i]+=1;
  }
 if(max<b[i])
 max=b[i]; 
}


for(i=0;i<max;i++)
{for(j=0;j<=9;j++)
{if(b[j]>=max-i)
 printf("* ");
 else
 printf("  ");
}
printf("\n");
}
for(j=0;j<=9;j++)
{printf("%d ",j);
}
} 

/*
enter the number of terms :12
enter the number:1
enter the number:7
enter the number:2
enter the number:9
enter the number:6
enter the number:7
enter the number:1
enter the number:3
enter the number:7
enter the number:5
enter the number:7
enter the number:9
              *     
              *     
  *           *   * 
  * * *   * * *   * 
0 1 2 3 4 5 6 7 8 9 
*/

 

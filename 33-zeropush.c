#include<stdio.h>
void pushzeroestoend(int arr[],int n);
void main()
{int ar[100],n,i;
printf("enter the no. of terms :");
scanf("%d",&n);
for(i=0;i<n;i++)
{scanf("%d",&ar[i]);}
pushzeroestoend(ar,n);
for(i=0;i<n;i++)
{printf("%d ",ar[i]);}
}

void pushzeroestoend(int arr[],int n)
{int i,j,k,temp,d;
 for(i=0;i<n;i++)
 {
  if(arr[i]==0)
  {
   temp=arr[i];
   for(j=i;j<n-1;j++)
   {arr[j]=arr[j+1];
   }
   arr[n-1]=temp;
   d=1; 
   if(arr[i]==0)
   for(k=i;k<n;k++)
   {if(arr[k]!=0)
    {d=0;
     break;
    }
   }
   if(d==0)
   i--;
  }
}
}
/*
enter the no. of terms :8
0
0
0
2
3
0
6
0
2 3 6 0 0 0 0 0 
*/

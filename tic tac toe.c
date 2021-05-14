#include<stdio.h>
#include<stdlib.h>
void main()
{randomize();
	int m,n,k,i,r=1,j;
	char c,ar[3][3];
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	{
		ar[i][j]='a';
	}
	printf("choose player 1/player 2 :");
	scanf("%d",&k);
	printf("NOTE: enter row no. froms 1-3 and column no. from 1-3\n");
	if(k==1)
	{	
		int s=1;
		user:
		printf("YOUR TURN\n");
	 	printf("enter elemnet index(MxN) : ");
	 	scanf("%d %d",&m,&n);
	 	if(ar[m-1][n-1]!='a')
	 	{ar[m-1][n-1]='x';
		 s=0;
		}
		if(s==0)
		{display(ar);
			s=1;
			goto comp;
		}
		else
		{printf("input invalid,re-enter");
		 goto user;	
		}
		

		comp:
		printf("COMPUTER TURN\n");
		

	}	
}

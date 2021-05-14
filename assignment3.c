//1.well ordered numbers
#include<stdio.h>
void main()
{int ar[3],n,k=0;
for(ar[0]=1;ar[0]<=9;ar[0]++)
for(ar[1]=ar[0]+1;ar[1]<=9;ar[1]++)
for(ar[2]=ar[1]+1;ar[2]<=9;ar[2]++)
{n=100*ar[0]+10*ar[1]+ar[2];
printf("%d\n",n);
k++;
}
printf("the total no. of terms is %d\n",k); 
}
/*
123
124
125
126
127
128
129
134
135
136
137
138
139
145
146
147
148
149
156
157
158
159
167
168
169
178
179
189
234
235
236
237
238
239
245
246
247
248
249
256
257
258
259
267
268
269
278
279
289
345
346
347
348
349
356
357
358
359
367
368
369
378
379
389
456
457
458
459
467
468
469
478
479
489
567
568
569
578
579
589
678
679
689
789
the total no. of terms is 84
*/


//2.vertical histogram

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

 
//3.push zeroes to end
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

//4.student marklist

#include<stdio.h>
void main()
{
	int ar[100][20],m,n;
	float avg[100],avt=0;
	char name[100][100],l;
	printf("enter the total no. of students :");
	scanf("%d",&l);
	printf("enter names of students\n");
	int i,j,k;
	for(i=0;i<l;i++)
	{
		j=i+1;
		printf("%d.",j);
		scanf("%s",name[i]);
	}
	printf("enter number of subjects :");
	scanf("%d",&m);
	printf("enter their marks \n NOTE:enter space after each mark\n");
    printf("        NAME            |   SUBJECTS\n");
    printf("                         ");
    for(i=1;i<m+1;i++)
    printf("%2d ",i);
    printf("\n");
    for(i=0;i<l;i++)
	{   
		k=i+1;
        printf("%-2d.%-20s: ",k,name[i]);
        avg[i]=0;
        for(j=0;j<m;j++)
        {
	        scanf("%2d",&ar[i][j]);
    		avg[i]+=ar[i][j];
    	}
    	avg[i]/=m;
    	
        avt+=avg[i];
	}
	avt/=l;
	printf("        NAME            |   SUBJECTS\n");
    printf("                         ");
    for(i=1;i<m+1;i++)
    printf("%2d ",i);
    printf("  average");
    printf("\n");
    for(i=0;i<l;i++)
	{   
		k=i+1;
        printf("%-2d.%-20s: ",k,name[i]);
        for(j=0;j<m;j++)
        {
	        printf("%2d ",ar[i][j]);
       	}
    	printf("    %.2f\n",avg[i]);
        
	}
	
	printf("\n     CLASS AVERAGE : %.2f\n",avt);
}
/*
enter the total no. of students :3
enter names of students
1.sudharshan
2.amith
3.sreedhar
enter number of subjects :5
enter their marks
 NOTE:enter space after each mark
        NAME            |   SUBJECTS
                          1  2  3  4  5
1 .sudharshan          : 65 76 87 98 78
2 .amith               : 76 87 98 85 65
3 .sreedhar            : 56 78 98 97 67
        NAME            |   SUBJECTS
                          1  2  3  4  5   average
1 .sudharshan          : 65 76 87 98 78    80.80
2 .amith               : 76 87 98 85 65    82.20
3 .sreedhar            : 56 78 98 97 67    79.20

     CLASS AVERAGE : 80.73
*/  

//a . modification

#include<stdio.h>
void main()
{
	int ar[100][20],m,n;
	float avg[100],avt=0;
	char name[100][100],l;
	printf("enter the total no. of students :");
	scanf("%d",&l);
	printf("enter names of students\n");
	int i,j,k;
	for(i=0;i<l;i++)
	{
		j=i+1;
		printf("%d.",j);
		scanf("%s",name[i]);
	}
	m=6;
	printf("enter their marks \n NOTE:enter space after each mark\n");
    printf("        NAME            |   SUBJECTS\n");
    printf("                         ");
    for(i=1;i<m+1;i++)
    printf("%2d ",i);
    printf("\n");
    for(i=0;i<l;i++)
	{   
		k=i+1;
        printf("%-2d.%-20s: ",k,name[i]);
        avg[i]=0;
        for(j=0;j<m;j++)
        {
	        scanf("%2d",&ar[i][j]);
    		if(j<4)
    		avg[i]+=3*ar[i][j];
    		else
    		avg[i]+=4*ar[i][j];
    	}
    	avg[i]/=20;
    	
        avt+=avg[i];
	}
	avt/=l;
	printf("        NAME            |   SUBJECTS\n");
    printf("                         ");
    for(i=1;i<m+1;i++)
    printf("%2d ",i);
    printf("  average");
    printf("\n");
    for(i=0;i<l;i++)
	{   
		k=i+1;
        printf("%-2d.%-20s: ",k,name[i]);
        for(j=0;j<m;j++)
        {
	        printf("%2d ",ar[i][j]);
       	}
    	printf("    %.2f\n",avg[i]);
        
	}
	
	printf("\n     CLASS AVERAGE : %.2f\n",avt);
}
/*
enter the total no. of students :3
enter names of students
1.sudharshan
2.amith
3.sreedhar
enter their marks
 NOTE:enter space after each mark
        NAME            |   SUBJECTS
                          1  2  3  4  5  6
1 .sudharshan          : 56 76 89 98 97 96
2 .amith               : 76 87 98 87 98 76
3 .sreedhar            : 67 78 89 98 87 89
        NAME            |   SUBJECTS
                          1  2  3  4  5  6   average
1 .sudharshan          : 56 76 89 98 97 96     86.45
2 .amith               : 76 87 98 87 98 76     87.00
3 .sreedhar            : 67 78 89 98 87 89     85.00

     CLASS AVERAGE : 86.15
*/

//b. modification

#include<stdio.h>
void main()
{
	int ar[100][20],m,n;
	float avg[100],avt=0;
	char name[100][100],l;
	printf("enter the total no. of students :");
	scanf("%d",&l);
	printf("enter names of students\n");
	int i,j,k;
	for(i=0;i<l;i++)
	{
		j=i+1;
		printf("%d.",j);
		scanf("%s",name[i]);
	}
	m=6;
	printf("enter their marks \n NOTE:enter space after each mark\n");
    printf("        NAME            |   SUBJECTS\n");
    printf("                         ");
    for(i=1;i<m+1;i++)
    printf("%2d ",i);
    printf("\n");
    for(i=0;i<l;i++)
	{   
		k=i+1;
        printf("%-2d.%-20s: ",k,name[i]);
        avg[i]=0;
        for(j=0;j<m;j++)
        {
	        scanf("%2d",&ar[i][j]);
    		if(j<4)
    		avg[i]+=3*ar[i][j];
    		else
    		avg[i]+=4*ar[i][j];
    	}
    	avg[i]/=20;
    	
        avt+=avg[i];
	}
	avt/=l;
	printf("        NAME            |   SUBJECTS\n");
    printf("                         ");
    for(i=1;i<m+1;i++)
    printf("%2d ",i);
    printf("  average    deviation");
    printf("\n");
    for(i=0;i<l;i++)
	{   
		k=i+1;
        printf("%-2d.%-20s: ",k,name[i]);
        for(j=0;j<m;j++)
        {
	        printf("%2d ",ar[i][j]);
       	}
       	float k;
       	k=avg[i]-avt;
    	printf("    %.2f         %.2f\n",avg[i],k);
        
	}
	
	printf("\n     CLASS AVERAGE : %.2f\n",avt);
}
/*
enter the total no. of students :3
enter names of students
1.sudharshan
2.amith
3.sreedhar
enter their marks
 NOTE:enter space after each mark
        NAME            |   SUBJECTS
                          1  2  3  4  5  6
1 .sudharshan          : 76 78 89 78 89 96
2 .amith               : 67 76 76 87 98 96
3 .sreedhar            : 56 76 86 57 98 99
        NAME            |   SUBJECTS
                          1  2  3  4  5  6   average    deviation
1 .sudharshan          : 76 78 89 78 89 96     85.15         1.65
2 .amith               : 67 76 76 87 98 96     84.70         1.20
3 .sreedhar            : 56 76 86 57 98 99     80.65         -2.85

     CLASS AVERAGE : 83.50

*/     

//6. rock paper and scissor

#include<stdio.h>
#include<stdlib.h>
int result(int c,int p);
void main()
{
	//randomize();
	int c,p,k,cs=0,ps=0,sum=0;
	int i,ar[10];
	for(i=0;i<10;i++)
	{//randomize();
	c=rand()%10; 
	if(c<3)
	c=1;
	else if (c>6)
	c=3;
	else
	c=2;
	printf("enter choice:\n1.rock\n2.paper\n3.scissor\n    ");
	scanf("%d",&p);
	k=result(c,p);
	printf(" COMPUTER CHOICE :%d\n",c);
	if(k==-1)
	printf("       DRAW \n");
	else if(k==1)
	{
		ps+=1;
		printf("     PLAYER WINS\n");
	}
	else
	{
		cs+=1;
		printf("     COMPUTER WINS\n");
	}	
	printf("PLAYER SCORE: %d \t COMPUTER SCORE: %d\n",ps,cs);
    }

    printf("     GAME OVER\n");
    for(i=0;i<10;i++)
    {sum+=ar[i];}
    if(sum==0)
    {
    	printf("       DRAW\n");
    }
    else if(sum>0)
    {
    	printf("      YOU WIN\n");
    }
    else
    printf("  COMPUTER WINS \n");
}
int result(int c,int p)
{
	if(c==p)
	return 0;
	int r;
	r=c+p;
	if(r%2==1)
	{
		if(p>c)
		return 1;
		else 
		return -1;
	}
	else
	{
		if(p<c)
		return 1;
		else 
		return -1;
	}	
}/*

enter choice:
1.rock
2.paper
3.scissor
    3
 COMPUTER CHOICE :1
     COMPUTER WINS
PLAYER SCORE: 0          COMPUTER SCORE: 1
enter choice:
1.rock
2.paper
3.scissor
    2
 COMPUTER CHOICE :3
     COMPUTER WINS
PLAYER SCORE: 0          COMPUTER SCORE: 2
enter choice:
1.rock
2.paper
3.scissor
    3
 COMPUTER CHOICE :2
     PLAYER WINS
PLAYER SCORE: 1          COMPUTER SCORE: 2
enter choice:
1.rock
2.paper
3.scissor
    2
 COMPUTER CHOICE :1
     PLAYER WINS
PLAYER SCORE: 2          COMPUTER SCORE: 2
enter choice:
1.rock
2.paper
3.scissor
    1
 COMPUTER CHOICE :3
     PLAYER WINS
PLAYER SCORE: 3          COMPUTER SCORE: 2
enter choice:
1.rock
2.paper
3.scissor
    3
 COMPUTER CHOICE :2
     PLAYER WINS
PLAYER SCORE: 4          COMPUTER SCORE: 2
enter choice:
1.rock
2.paper
3.scissor
    2
 COMPUTER CHOICE :3
     COMPUTER WINS
PLAYER SCORE: 4          COMPUTER SCORE: 3
enter choice:
1.rock
2.paper
3.scissor
    1
 COMPUTER CHOICE :3
     PLAYER WINS
PLAYER SCORE: 5          COMPUTER SCORE: 3
enter choice:
1.rock
2.paper
3.scissor
    3
 COMPUTER CHOICE :1
     COMPUTER WINS
PLAYER SCORE: 5          COMPUTER SCORE: 4
enter choice:
1.rock
2.paper
3.scissor
    2
 COMPUTER CHOICE :2
       DRAW
PLAYER SCORE: 5          COMPUTER SCORE: 4
     GAME OVER
      YOU WIN
      */
      
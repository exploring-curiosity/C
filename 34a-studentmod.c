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
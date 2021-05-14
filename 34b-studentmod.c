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
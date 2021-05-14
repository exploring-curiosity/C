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

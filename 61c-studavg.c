#include<stdio.h>
struct student
{
char name[100];
int reg;
int sub[20];
float avg;
};
void main()
{
struct student s[20];
int n,m,i,j;

printf("enter no. of students: ");
scanf("%d",&m);
printf("enter no. of subjects: ");
scanf("%d",&n);
for(i=0;i<m;i++)
{
printf("name %d:",i+1);
scanf("%s",s[i].name);
printf("registration no. :");
scanf("%d",&s[i].reg);
printf("subject marks\n");
for(j=0;j<n;j++)
{
scanf("%d",&s[i].sub[j]);
s[i].avg+=s[i].sub[j];
}
s[i].avg/=n;
printf("students average is :%f\n",s[i].avg);
}

}
/*
PS F:\> gcc 61c-studavg.c -o k
PS F:\> ./k
enter no. of students: 3
enter no. of subjects: 2
name 1:ram
registration no. :532
subject marks
56
67
students average is :61.500000
name 2:kamal
registration no. :478
subject marks
43
67
students average is :55.000000
name 3:takur
registration no. :892
subject marks
56
78
students average is :67.000000
PS F:\>
*/
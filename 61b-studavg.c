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
int n,i,j;
printf("enter no. of subjects: ");
scanf("%d",&n);
for(i=0;i<1;i++)
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
}
printf("students average is :%f\n",s[0].avg);
}
/*
PS F:\> gcc 61b-studavg.c -o k
PS F:\> ./k
enter no. of subjects: 5
name 1:kamal
registration no. :475
subject marks
45
67
89
87
65
students average is :70.599998
PS F:\>
*/
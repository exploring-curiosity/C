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
int n,i;
/*printf("enter no. of students: ");
scanf("%d",&n);*/
n=1;
for(i=0;i<n;i++)
{
printf("name %d:",i+1);
scanf("%s",s[i].name);
printf("registration no. :");
scanf("%d",&s[i].reg);

printf("subject marks\n");
scanf("%d",&s[i].sub[0]);
scanf("%d",&s[i].sub[1]);
scanf("%d",&s[i].sub[2]);
s[i].avg=s[i].sub[0]+s[i].sub[1]+s[i].sub[2];
s[i].avg/=3;
}
printf("students average is :%f\n",s[0].avg);
}
/*
PS F:\> gcc 61a-studavg.c -o k
PS F:\> ./k
name 1:ram
registration no. :901
subject marks
45
54
67
students average is :55.333332
PS F:\>
*/
#include<stdio.h>
struct student
{
char name[100];
int reg;
int sub[20];
float avg;
};
void average(struct student s[],int m,int n);
void input(struct student s[],int m,int n);
void output(struct student s[],int m,int n);
void main()
{
struct student s[20];
int n,m,i,j=0;
float p;
printf("enter no. of students: ");
scanf("%d",&m);
printf("enter no. of subjects: ");
scanf("%d",&n);
input(s,m,n);
average(s,m,n);

for(i=0;i<m;i++)
{if(s[i].avg>=50)
j++;
}
p=j;
p=p*100/m;

printf("pass percent is %f\n",p);
//output(s,m,n);
}


void input(struct student s[],int m,int n)
{ int i,j;
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
}
}
}

void output(struct student s[],int m,int n)
{int i;
for(i=0;i<m;i++)
printf("student%d average :%f\n",i+1,s[i].avg);
}
void average(struct student s[],int m,int n)
{int i,j;
float sum=0;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
sum+=s[i].sub[j];
s[i].avg=sum;
s[i].avg/=n;
sum=0;
}
}

/*
PS F:\> gcc 63-passpercent.c -o k
PS F:\> ./k
enter no. of students: 3
enter no. of subjects: 2
name 1:ram
registration no. :456
subject marks
67
78
name 2:kamal
registration no. :76
subject marks
75
89
name 3:takur
registration no. :789
subject marks
45
43
pass percent is 66.666664
PS F:\>
*/
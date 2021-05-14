#include<stdio.h>
struct student
{
char name[100];
int reg;
int sub[20];
float avg;
};
void classavg(struct student s[],int m);
void average(struct student s[],int m,int n);
void input(struct student s[],int m,int n);
void output(struct student s[],int m,int n);
void main()
{
struct student s[20];
int n,m,i,j;

printf("enter no. of students: ");
scanf("%d",&m);
printf("enter no. of subjects: ");
scanf("%d",&n);
input(s,m,n);
average(s,m,n);
output(s,m,n);
classavg(s,m);
}


void classavg(struct student s[],int m)
{
	float sum=0;
	int i;
	for(i=0;i<m;i++)
	{
		sum+=s[i].avg;
	}
	sum/=m;
	printf("class avg:%f\n",sum);
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

PS F:\> gcc 62-studmod.c -o k
PS F:\> ./k
enter no. of students: 3
enter no. of subjects: 2
name 1:ram
registration no. :654
subject marks
67
76
name 2:kamal
registration no. :754
subject marks
76
87
name 3:takur
registration no. :743
subject marks
87
89
student1 average :71.500000
student2 average :81.500000
student3 average :88.000000
class avg:80.333336
PS F:\>
*/

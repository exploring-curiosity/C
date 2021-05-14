#include<stdio.h>
#include<string.h>
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
int n,m,i,j=0,h;
float p;
char t[100];
printf("enter no. of students: ");
scanf("%d",&m);
printf("enter no. of subjects: ");
scanf("%d",&n);
input(s,m,n);
average(s,m,n);
float temp;
for(i=0;i<m;i++)
{
	for (j=0;j<m-i-1;j++)
	{
		if(s[j].avg>s[j+1].avg)
		{	
			temp=s[j].avg;
			s[j].avg=s[j+1].avg;
			s[j+1].avg=temp;
			strcpy(t,s[j].name);
			strcpy(s[j].name,s[j+1].name);
			strcpy(s[j+1].name,t);
		}
	}
}
output(s,m,n);
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
{int i,j,lr=1;
for(i=m-1,j=1;i>=0;i--,j++)
{
	if(s[i+1].avg==s[i].avg&&i<m-1)
	printf("student name:%s average :%f  rank :%d\n",s[i].name,s[i].avg,lr);
	else
	{
		printf("student name:%s average :%f  rank :%d\n",s[i].name,s[i].avg,j);
		lr=j;
	}
}
}
void average(struct student s[],int m,int n)
{int i,j;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
s[i].avg+=s[i].sub[j];
s[i].avg/=n;
}
}

/*
PS F:\> gcc 64b-rank.c -o k
PS F:\> ./k
enter no. of students: 5
enter no. of subjects: 1
name 1:ram
registration no. :654
subject marks
78
name 2:kamal
registration no. :435
subject marks
65
name 3:raaju
registration no. :678
subject marks
78
name 4:takur
registration no. :689
subject marks
56
name 5:ben
registration no. :521
subject marks
56
student name:raaju average :78.000000  rank :1
student name:ram average :78.000000  rank :1
student name:kamal average :65.000000  rank :3
student name:ben average :56.000000  rank :4
student name:takur average :56.000000  rank :4
PS F:\>
*/
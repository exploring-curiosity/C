#include<stdio.h>
#include<string.h>
struct student
{
char name[100];
int reg;
int sub[20];
float avg;
};
int srchn(struct student s[],char n[],int m);
int srchr(struct student s[],int n,int m);
void average(struct student s[],int m,int n);
void input(struct student s[],int m,int n);
void output(struct student s[],int m,int n);
void main()
{
struct student s[20];
int n,m,i,r,v;
char ch[100];
printf("enter no. of students: ");
scanf("%d",&m);
printf("enter no. of subjects: ");
scanf("%d",&n);
input(s,m,n);
average(s,m,n);
//output(s,m,n);
do
{
	printf("1.srch by name \n2.srch by regno. \n3.exit\n");
	scanf("%d",&i);
	if(i==1)
	{
		printf("name:");
		scanf("%s",ch);
		v=srchn(s,ch,m);
		if(v>-1)
		printf("student name:%s  regno.: %d  average :%f\n",s[v].name,s[v].reg,s[v].avg);
		else
		printf("not found\n");

	}	
	if(i==2)
	{
		printf("regno.:");
		scanf("%d",&r);
		v=srchr(s,r,m);
		if(v>-1)
		printf("student name:%s  regno.: %d  average :%f\n",s[v].name,s[v].reg,s[v].avg);
		else
		printf("not found\n");
	}
}while(i!=3);

}

int srchr(struct student s[],int n,int m)
{
	int i;
	for(i=0;i<m;i++)
	{
		if(s[i].reg==n)
		return i;
	}
	return -1;
}
int srchn(struct student s[],char n[],int m)
{	
	int i;
	for(i=0;i<m;i++)
	{
		if(!strcmp(s[i].name,n))
		return i;
	}
	return -1;
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
printf("student%d average :%f\n",s[i].avg);
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
PS F:\> gcc 65-search.c -o k
PS F:\> ./k
enter no. of students: 3
enter no. of subjects: 2
name 1:ram
registration no. :543
subject marks
67
89
name 2:takur
registration no. :654
subject marks
67
99
name 3:kamal
registration no. :982
subject marks
55
88
1.srch by name
2.srch by regno.
3.exit
1
name:takur
student name:takur  regno.: 654  average :83.000000
1.srch by name
2.srch by regno.
3.exit
2
regno.:982
student name:kamal  regno.: 982  average :71.500000
1.srch by name
2.srch by regno.
3.exit
3
PS F:\>
*/
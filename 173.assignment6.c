//1a.student avgerage all fixed

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

//1b.student average student fixed

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

//1c.student average all variable

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

//2.student average modified to functions

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

//3.pass percentage

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

//4a.rank without formatation

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
{int i,j;
for(i=m-1,j=1;i>=0;i--,j++)
printf("student name:%s average :%f  rank :%d\n",s[i].name,s[i].avg,j);
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
PS F:\> gcc 64a-rank.c
PS F:\> gcc 64a-rank.c -o k
PS F:\> ./k
enter no. of students: 5
enter no. of subjects: 1
name 1:ram
registration no. :654
subject marks
67
name 2:kamal
registration no. :568
subject marks
78
name 3:takur
registration no. :983
subject marks
56
name 4:raju
registration no. :901
subject marks
77
name 5:ben
registration no. :592
subject marks
89
student name:ben average :89.000000  rank :1
student name:raju average :78.000000  rank :2
student name:takur average :77.000000  rank :3
student name:kamal average :67.000000  rank :4
student name:ram average :56.000000  rank :5
PS F:\>
*/

//4b.rank formatted

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

//5.search

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

//6.menu driven format

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
void rank(struct student s[],int m,int n);
void classavg(struct student s[],int m);
void average(struct student s[],int m,int n);
void input(struct student s[],int m,int n);
void output(struct student s[],int m,int n);
void main()
{
struct student s[20];
int n,m,i,j,opr,r,v;
float p,temp;
char ch[100],t[100];
printf("enter no. of students: ");
scanf("%d",&m);
printf("enter no. of subjects: ");
scanf("%d",&n);
for(i=0;i<m;i++)
{
	if(s[i].avg>=50)
	j++;
}
p=j*100/m;
j=0;

do
{
	printf("choose:\n");
	printf("\t1.input\n");
	printf("\t2.find average\n");
	printf("\t3.class average\n");
	printf("\t4.pass percent\n");
	printf("\t5.rank\n");
	printf("\t6.search by name\n");
	printf("\t7.search by reg no.\n");
	printf("\t8.display\n");
	printf("\t9.exit\n");
	scanf("%d",&opr);
	switch(opr)
	{
		case 1: input(s,m,n);
				average(s,m,n);
				break;
		case 2:	average(s,m,n);
		        output(s,m,n);
				break;
		case 3: classavg(s,m);
				break;
		case 4:	for(i=0;i<m;i++)
				{
					if(s[i].avg>=50)
					j++;
				}
				p=j;
				p=p*100/m;
				j=0;
				printf("pass percent is %f\n",p);
				break;
		case 5: for(i=0;i<m;i++)
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
				rank(s,m,n);
				break;
		case 6: printf("name:");
				scanf("%s",ch);
				v=srchn(s,ch,m);
				if(v>-1)
				printf("student name:%s  regno.: %d  average :%f\n",s[v].name,s[v].reg,s[v].avg);
				else
				printf("not found\n");
				break;
		case 7: printf("regno.:");
				scanf("%d",&r);
				v=srchr(s,r,m);
				if(v>-1)
				printf("student name:%s  regno.: %d  average :%f\n",s[v].name,s[v].reg,s[v].avg);
				else
				printf("not found\n");
				break;
		case 8:	output(s,m,n);
				break;
		case 9: break;		
		default:printf("invalid\n");			
										
	}


}while(opr!=9);
}

void rank(struct student s[],int m,int n)
{int i,j,lr=1;
for(i=m-1,j=1;i>=0;i--,j++)
{
	if((s[i+1].avg==s[i].avg)&&(i<m-1))
	printf("student name:%s average :%f  rank :%d\n",s[i].name,s[i].avg,lr);
	else
	{
		printf("student name:%s average :%f  rank :%d\n",s[i].name,s[i].avg,j);
		lr=j;
	}
}
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
printf("student%d student name:%s reg no:%d average :%f \n",i+1,s[i].name,s[i].reg,s[i].avg);
}

void average(struct student s[],int m,int n)
{int i,j;
float sum=0;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{sum+=s[i].sub[j];}

s[i].avg=sum;
s[i].avg/=n;
sum=0;
}
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

/*PS F:\> gcc 66-structmd.c -o k
PS F:\> ./k
enter no. of students: 4
enter no. of subjects: 3
choose:
        1.input
        2.find average
        3.class average
        4.pass percent
        5.rank
        6.search by name
        7.search by reg no.
        8.display
        9.exit
1
name 1:ram
registration no. :234
subject marks
78
76
56
name 2:kamal
registration no. :435
subject marks
98
97
51
name 3:raju
registration no. :658
subject marks
97
78
79
name 4:takur
registration no. :941
subject marks
78
98
67
choose:
        1.input
        2.find average
        3.class average
        4.pass percent
        5.rank
        6.search by name
        7.search by reg no.
        8.display
        9.exit
2
student1 student name:ram reg no:234 average :70.000000
student2 student name:kamal reg no:435 average :82.000000
student3 student name:raju reg no:658 average :84.666664
student4 student name:takur reg no:941 average :81.000000
choose:
        1.input
        2.find average
        3.class average
        4.pass percent
        5.rank
        6.search by name
        7.search by reg no.
        8.display
        9.exit
3
class avg:79.416664
choose:
        1.input
        2.find average
        3.class average
        4.pass percent
        5.rank
        6.search by name
        7.search by reg no.
        8.display
        9.exit
4
pass percent is 100.000000
choose:
        1.input
        2.find average
        3.class average
        4.pass percent
        5.rank
        6.search by name
        7.search by reg no.
        8.display
        9.exit
5
student name:raju average :84.666664  rank :1
student name:kamal average :82.000000  rank :2
student name:takur average :81.000000  rank :3
student name:ram average :70.000000  rank :4
choose:
        1.input
        2.find average
        3.class average
        4.pass percent
        5.rank
        6.search by name
        7.search by reg no.
        8.display
        9.exit
6
name:takur
student name:takur  regno.: 435  average :81.000000
choose:
        1.input
        2.find average
        3.class average
        4.pass percent
        5.rank
        6.search by name
        7.search by reg no.
        8.display
        9.exit
7
regno.:658
student name:kamal  regno.: 658  average :82.000000
choose:
        1.input
        2.find average
        3.class average
        4.pass percent
        5.rank
        6.search by name
        7.search by reg no.
        8.display
        9.exit
8
student1 student name:ram reg no:234 average :70.000000
student2 student name:takur reg no:435 average :81.000000
student3 student name:kamal reg no:658 average :82.000000
student4 student name:raju reg no:941 average :84.666664
choose:
        1.input
        2.find average
        3.class average
        4.pass percent
        5.rank
        6.search by name
        7.search by reg no.
        8.display
        9.exit
9
PS F:\>
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//structure declaration
struct student
{
char name[100];
int reg;
int sub[20];
float avg;
};
//functions used
int srchn(struct student (*s)[20],char n[],int m);
int srchr(struct student (*s)[20],int n,int m);
void rank(struct student (*s)[20],int m,int n);
void classavg(struct student (*s)[20],int m);
void average(struct student (*s)[20],int m,int n);
void input(struct student (*s)[20],int m,int n);
void output(struct student (*s)[20],int m,int n);

//main
void main()
{
struct student (*s)[20],temp;
s=malloc(sizeof(struct student));
int n,m,i,j,opr,r,v;
float p,temp;
char ch[100],t[100];
printf("enter no. of students: ");
scanf("%d",&m);
printf("enter no. of subjects: ");
scanf("%d",&n);

for(i=0;i<m;i++)
{
	if((*(*(s)+i)).avg>=50)
	j++;
}
p=j;
p=p*100/m;
j=0;
//menu driven
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
					if((*(*(s)+i)).avg>=50)
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
						if((*(*(s)+j)).avg>(*(*(s)+j+1)).avg)
						{	
							temp=(*(*(s)+j));
							(*(*(s)+j))=(*(*(s)+j+1));
							(*(*(s)+j+1))=temp;
						}
					}
				}
				rank(s,m,n);
				break;
		case 6: printf("name:");
				scanf("%s",ch);
				v=srchn(s,ch,m);
				if(v>-1)
				printf("student name:%s  regno.: %d  average :%f\n",(*(*(s)+v)).name,(*(*(s)+v)).reg,(*(*(s)+v)).avg);
				else
				printf("not found\n");
				break;
		case 7: printf("regno.:");
				scanf("%d",&r);
				v=srchr(s,r,m);
				if(v>-1)
				printf("student name:%s  regno.: %d  average :%f\n",(*(*(s)+v)).name,(*(*(s)+v)).reg,(*(*(s)+v)).avg);
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
//function for rank
void rank(struct student (*s)[20],int m,int n)
{int i,j,lr=1;
for(i=m-1,j=1;i>=0;i--,j++)
{
	if(((*(*(s)+i+1)).avg==(*(*(s)+i)).avg)&&(i<m-1))
	printf("student name:%s average :%f  rank :%d\n",(*(*(s)+i)).name,(*(*(s)+i)).avg,lr);
	else
	{
		printf("student name:%s average :%f  rank :%d\n",(*(*(s)+i)).name,(*(*(s)+i)).avg,j);
		lr=j;
	}
}
}

//function for class average
void classavg(struct student (*s)[20],int m)
{
	float sum=0;
	int i;
	for(i=0;i<m;i++)
	{
		sum+=(*(*(s)+i)).avg;
	}
	sum/=m;
	printf("class avg:%f\n",sum);
}
//function to get inout of students
void input(struct student (*s)[20],int m,int n)
{ int i,j;
for(i=0;i<m;i++)
{
printf("name %d:",i+1);
scanf("%s",(*(*(s)+i)).name);
printf("registration no. :");
scanf("%d",&(*(*(s)+i)).reg);
printf("subject marks\n");
for(j=0;j<n;j++)
{
scanf("%d",&(*(*(s)+i)).sub[j]);
}
}
}
//function to display array of student details
void output(struct student (*s)[20],int m,int n)
{int i;
for(i=0;i<m;i++)
printf("student%d student name:%s reg no:%d average :%f \n",i+1,(*(*(s)+i)).name,(*(*(s)+i)).reg,(*(*(s)+i)).avg);
}
//function to calculate their individual averages
void average(struct student (*s)[20],int m,int n)
{int i,j;
float sum=0;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{sum+=(*(*(s)+i)).sub[j];}

(*(*(s)+i)).avg=sum;
(*(*(s)+i)).avg/=n;
sum=0;
}
}
//function to search by registration no.
int srchr(struct student (*s)[20],int n,int m)
{
	int i;
	for(i=0;i<m;i++)
	{
		if((*(*(s)+i)).reg==n)
		return i;
	}
	return -1;
}
//function to search by name
int srchn(struct student (*s)[20],char n[],int m)
{	
	int i;
	for(i=0;i<m;i++)
	{
		if(!strcmp((*(*(s)+i)).name,n))
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
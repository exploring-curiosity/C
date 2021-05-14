#include<stdio.h>
#include"input.h"																																
struct student
{
char name[100];
int reg;
int sub[20];
float avg;
};
void classavg(struct student s[],int m);
void average(struct student s[],int m,int n);
void write(struct student s[],int m,int n);
void output(struct student s[],int m,int n);
//main function
void main()
{

	struct student s[20];
	int n=0,m=0;
	//FILE *a;
	//a=fopen("in.dat","r");

	printf("enter no. of students: ");
	scanf("%d",&m);
	printf("enter no. of subjects: ");
	scanf("%d",&n);

	/*fread(&m,sizeof(m),1,a);
	fread(&n,sizeof(n),1,a);
	printf("pass m=%d",m);*/
	//m=3;
	//n=3;
	//fclose(a);
	write(s,m,n);
	average(s,m,n);
	output(s,m,n);
	classavg(s,m);
}


void classavg(struct student s[],int m)
{
	FILE *a;
	//reading file
	a=fopen("out.txt","a+");
	float sum=0;
	int i;
	for(i=0;i<m;i++)
	{
		sum+=s[i].avg;
	}
	sum/=m;
	printf("class avg:%f\n",sum);
	fprintf(a,"class avg:%f\n",sum);
	fseek(a,0,0);
	input(a);
fclose(a);
}

void write(struct student s[],int m,int n)
{ int i,j;
FILE *a;
//writing file
a=fopen("in.dat","w");
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
	fwrite(&s[i],sizeof(s[i]),1,a);
        
}
fclose(a);
}

void output(struct student s[],int m,int n)
{int i;
FILE *b;
//reading file
b=fopen("out.txt","w");
for(i=0;i<m;i++)
{printf("student%d average :%f\n",i+1,s[i].avg);
fprintf(b,"student%d average :%f\n",i+1,s[i].avg);
}
fclose(b);
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

PS F:\> gcc a77-file.c -o k
PS F:\> ./k
enter no. of students: 3
enter no. of subjects: 2
name 1:ravi
registration no. :853
subject marks
78
94
name 2:kumar
registration no. :872
subject marks
86
75
name 3:balu
registration no. :649
subject marks
87
54
student1 average :86.000000
student2 average :80.500000
student3 average :70.500000
class avg:79.000000
student1 average :86.000000
student2 average :80.500000
student3 average :70.500000
class avg:79.000000
*/

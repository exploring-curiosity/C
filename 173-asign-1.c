#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define sizemax 100
typedef struct
{
	int regno;
	char name[20];
	float m1,m2,m3,total;
	char res;
}student;
typedef struct
{
	student a[100];
	int size;
}listADT;
void initialize(listADT *l)
{
	(*l).size=0;
}
void insertfront(listADT *l,student s)
{
	if((*l).size==sizemax)
	{
		printf("not enough space\n");
	}
	else
	{
		int i;
		for(i=(*l).size-1;i>=0;i--)
		{
			(*l).a[i+1]=(*l).a[i];
		}
		(*l).a[0]=s;
		(*l).size++;
	}
}
void insertend(listADT *l,student s)
{
	if((*l).size==sizemax)
	{
		printf("not enough space\n");
	}
	else
	{
		(*l).a[(*l).size]=s;
		(*l).size++;
	}
}
student searchregno(listADT *l,int reg)
{
	int i;
	for(i=0;i<(*l).size;i++)
	{
		if((*l).a[i].regno==reg)
			return (*l).a[i];
	}
}
void insertregno(listADT *l,int reg,student s)
{
	int i,regpos;
	for(i=0;i<(*l).size;i++)
	{
		if((*l).a[i].regno==reg)
			break;
	}
	regpos=i;
	if(regpos<(*l).size)
	{
		for(i=(*l).size-1;i>regpos;i--)
		{
			(*l).a[i+1]=(*l).a[i];
		}
		(*l).a[regpos+1]=s;
	}
	(*l).size++;
}
void listregno(listADT *l,int regno)
{
	student s;
	s=searchregno(l,regno);
	printf("name:%s\nmarks 1:%f 2:%f 3:%f total:%f \n result : %c\n",s.name,s.m1,s.m2,s.m3,s.total,s.res);
}
void delete(listADT *l,int reg)
{
	if((*l).size==0)
	{
		printf("the list is empty\n");
		return;
	}
	student s;
	s=searchregno(l,reg);
	if(s.regno>0)
	{
		printf("name:%s\nmarks 1:%f 2:%f 3:%f total:%f \n result : %c\n",s.name,s.m1,s.m2,s.m3,s.total,s.res);
		int i,regpos;
		for(i=0;i<(*l).size;i++)
		{
			if((*l).a[i].regno==reg)
				break;
		}
		regpos=i;
		if(regpos<(*l).size)
		{
			for(i=regpos;i<(*l).size-1;i++)
			{
				(*l).a[i]=(*l).a[i+1];
			}
		}
		(*l).size--;
	}
}
void computeresult(listADT *l)
{
	int i;
	for(i=0;i<(*l).size;i++)
	{
		(*l).a[i].total=(*l).a[i].m1+(*l).a[i].m2+(*l).a[i].m3;
		if(((*l).a[i].m1>=50)&&((*l).a[i].m2>=50)&&((*l).a[i].m3>=50))
		{
			(*l).a[i].res='P';
		}
		else
			(*l).a[i].res='F';
	}
}
student* listresult(listADT *l)
{
	student *h;
	h=(student*)malloc(5*sizeof(student));
	int i,j=0;
	for(i=0;i<(*l).size;i++)
	{
		if((*l).a[i].res=='P')
		{	
			*(h+j)=(*l).a[i];
			//printf("%d. %s\n",j,(*l).a[i].name);
			j++;
		}
	}
	return h;
}
student getentry()
{
	student s;
	printf("enter student name:");
	scanf("%s",s.name);
	printf("enter student regno:");
	scanf("%d",&s.regno);
	printf("enter student mark 1:");
	scanf("%f",&s.m1);
	printf("enter student mark 2:");
	scanf("%f",&s.m2);
	printf("enter student mark 3:");
	scanf("%f",&s.m3);
	return s;	
}
int listclass(listADT *l)
{
	int i,j=0;
	for(i=0;i<(*l).size;i++)
	{
		if((*l).a[i].total/3>=75)
		{
			j++;
		}
	}
	return j;
}
int passno(listADT *l)
{
	int i,j=0;
	for(i=0;i<(*l).size;i++)
	{
		if((*l).a[i].total/3>=50)
		{
			j++;
		}
	}
	return j;
}
void display(student *a,int x)
{
	int i;
	student s;
	for(i=0;i<x;i++)
	{
		//s=*(a+i);
		printf("name:%s\nmarks 1:%f 2:%f 3:%f total:%f \n result : %c\n",(a+i)->name,(a+i)->m1,(a+i)->m2,(a+i)->m3,(a+i)->total,(a+i)->res);
	}
}
student* searchname(listADT *l,char nam[100])
{
	student *h;
	h=(student*)malloc(5*sizeof(student));
	int i,j=0;
	for(i=0;i<(*l).size;i++)
	{
		if(!strcmp(nam,(*l).a[i].name))
		{	
			*(h+j)=(*l).a[i];
			//printf("%d. %s\n",j,(*l).a[i].name);
			j++;
		}
	}
	return h;	
}
int nameno(listADT *l,char nam[100])
{
	int i,j=0;
	for(i=0;i<(*l).size;i++)
	{
		if(!strcmp(nam,(*l).a[i].name))
		{	
			j++;
		}
	}
	return j;	
}
void main()
{
	char choice;
	char ch='y',nam[100];
	student s,*pass,*dis;
	int reg;
	listADT l;
	initialize(&l);
	do
	{
		printf("choose operation\n\n 1.insert front \n 2.insert end \n 3.insert after regno \n 4.search by regno \n 5.delete \n 6.compute result\n 7.show result \n 8.total in firstcalss \n 9.search by name \n your choice :");
		scanf(" %c",&choice);
		switch(choice)
		{
			case '1' : 	s=getentry();
					insertfront(&l,s);
					break;
			case '2' : 	s=getentry();
					insertend(&l,s);
					break;
			case '3' : 	s=getentry();
					printf("enter reg no:");
					scanf("%d",&reg);
					insertregno(&l,reg,s);
					break;
			case '4' : 	printf("enter reg no:");
					scanf("%d",&reg);
					listregno(&l,reg);
					break;
			case '5' :	printf("enter reg no:");
					scanf("%d",&reg);
					delete(&l,reg);
					break;
			case '6' :	computeresult(&l);
					break;
			case '7' : 	pass=listresult(&l);
					reg=passno(&l);
					display(pass,reg);
					break;
			case '8' :	reg=listclass(&l);
					printf("first class = %d",reg);
					break;
			case '9' : 	printf("enter the name:");
					gets(nam);
					gets(nam);
					dis=searchname(&l,nam);
					reg=nameno(&l,nam);
					display(dis,reg);
					break;
			default  :	printf("\ninvalid\n");		
		}
		printf("do u want to continue [y/n]");
		scanf(" %c",&ch);
	}while(ch=='y');
}
 /*
 PS F:\> ./k
choose operation

 1.insert front
 2.insert end
 3.insert after regno
 4.search by regno
 5.delete
 6.compute result
 7.show result
 8.total in firstcalss
 9.search by name
 your choice :1
enter student name:ram
enter student regno:1
enter student mark 1:67
enter student mark 2:56
enter student mark 3:78
do u want to continue [y/n]y
choose operation

 1.insert front
 2.insert end
 3.insert after regno
 4.search by regno
 5.delete
 6.compute result
 7.show result
 8.total in firstcalss
 9.search by name
 your choice :2
enter student name:kamal
enter student regno:2
enter student mark 1:56
enter student mark 2:87
enter student mark 3:98
do u want to continue [y/n]y
choose operation

 1.insert front
 2.insert end
 3.insert after regno
 4.search by regno
 5.delete
 6.compute result
 7.show result
 8.total in firstcalss
 9.search by name
 your choice :3
enter student name:madhu
enter student regno:3
enter student mark 1:78
enter student mark 2:98
enter student mark 3:78
enter reg no:1
do u want to continue [y/n]y
choose operation

 1.insert front
 2.insert end
 3.insert after regno
 4.search by regno
 5.delete
 6.compute result
 7.show result
 8.total in firstcalss
 9.search by name
 your choice :6
do u want to continue [y/n]y
choose operation

 1.insert front
 2.insert end
 3.insert after regno
 4.search by regno
 5.delete
 6.compute result
 7.show result
 8.total in firstcalss
 9.search by name
 your choice :4
enter reg no:3
name:madhu
marks 1:78.000000 2:98.000000 3:78.000000 total:254.000000
 result : P
do u want to continue [y/n]y
choose operation

 1.insert front
 2.insert end
 3.insert after regno
 4.search by regno
 5.delete
 6.compute result
 7.show result
 8.total in firstcalss
 9.search by name
 your choice :5
enter reg no:2
name:kamal
marks 1:56.000000 2:87.000000 3:98.000000 total:241.000000
 result : P
do u want to continue [y/n]y
choose operation

 1.insert front
 2.insert end
 3.insert after regno
 4.search by regno
 5.delete
 6.compute result
 7.show result
 8.total in firstcalss
 9.search by name
 your choice :7
name:ram
marks 1:67.000000 2:56.000000 3:78.000000 total:201.000000
 result : P
name:madhu
marks 1:78.000000 2:98.000000 3:78.000000 total:254.000000
 result : P
do u want to continue [y/n]y
choose operation

 1.insert front
 2.insert end
 3.insert after regno
 4.search by regno
 5.delete
 6.compute result
 7.show result
 8.total in firstcalss
 9.search by name
 your choice :8
first class = 1do u want to continue [y/n]y
choose operation

 1.insert front
 2.insert end
 3.insert after regno
 4.search by regno
 5.delete
 6.compute result
 7.show result
 8.total in firstcalss
 9.search by name
 your choice :1
enter student name:ram
enter student regno:4
enter student mark 1:67
enter student mark 2:56
enter student mark 3:45
do u want to continue [y/n]y
choose operation

 1.insert front
 2.insert end
 3.insert after regno
 4.search by regno
 5.delete
 6.compute result
 7.show result
 8.total in firstcalss
 9.search by name
 your choice :9
enter the name:ram
name:ram
marks 1:67.000000 2:56.000000 3:45.000000 total:0.000000
 result :
name:ram
marks 1:67.000000 2:56.000000 3:78.000000 total:201.000000
 result : P
do u want to continue [y/n]y
choose operation

 1.insert front
 2.insert end
 3.insert after regno
 4.search by regno
 5.delete
 6.compute result
 7.show result
 8.total in firstcalss
 9.search by name
 your choice :6
do u want to continue [y/n]y
choose operation

 1.insert front
 2.insert end
 3.insert after regno
 4.search by regno
 5.delete
 6.compute result
 7.show result
 8.total in firstcalss
 9.search by name
 your choice :9
enter the name:ram
name:ram
marks 1:67.000000 2:56.000000 3:45.000000 total:168.000000
 result : F
name:ram
marks 1:67.000000 2:56.000000 3:78.000000 total:201.000000
 result : P
do u want to continue [y/n]n
PS F:\> 
*/
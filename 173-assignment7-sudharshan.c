//1.file1
#include<stdio.h>
#include<stdlib.h>
//main function
void main()
{
	FILE *a;
	char ch,s[100];
	//reading file
	a=fopen("input.txt","r");
	//checking existence
	if(a==NULL)
	{
		printf("file not found");
		exit(1);
	}
	//reading and printing
	while(!feof(a))
	{ 
		fscanf(a,"%c",&ch);
		if(!feof(a))
		{
			printf("%c",ch);
		}
	}
	fclose(a);//closeing
}
/*
PS F:\> gcc a71-file.c -o k
PS F:\> ./k
hello everyone.
welcome to 2019.
This is c programming.
we are handling files
c is fun.
*/
//file 2

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include"input.h"
//main function
void main()
{
	FILE *a;
	char ch,s[100];
	int c=0,ws=0,d=0;
	//reading file
	a=fopen("input.txt","r");
	//checking file existence
	if(a==NULL)
	{
		printf("file not found");
		exit(1);
	}
	//processing
	while(!feof(a))
	{ 
		fscanf(a,"%c",&ch);
		if(!feof(a))
		{
			if(isalpha(ch))
			c++;
			else if(isdigit(ch))
			d++;
			else if(isspace(ch))
			ws++;
		}
	}
	printf("characters: %d  white spaces: %d  digits: %d\n",c,ws,d);
	fclose(a);
}
/*
PS F:\> gcc a72-file.c -o k
PS F:\> ./k
characters: 67  white spaces: 17  digits: 4
*/

//file 3


#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include"input.h"
//main function
void main()
{
	FILE *a;
	char ch,s[100],prev;
	int l=0,w=0,c=0,ws=0,d=0;
	//reading file
	a=fopen("input.txt","r");
	//checking for existence
	if(a==NULL)
	{
		printf("file not found");
		exit(1);
	}
	//processing
	while(!feof(a))
	{ 
		fscanf(a,"%c",&ch);
		if(!feof(a))
		{
			if(ch=='\n')//counting new lines
			l++;
			if(ch==' '||ch=='.'||ch=='\n'||ch==',')
			{
				if(!(prev==' '||prev=='.'||prev=='\n'||prev==','))//counting words
				w++;
			}

			if(isalpha(ch))
			c++;
			else if(isdigit(ch))
			d++;
			else if(isspace(ch))
			ws++;
		}
		prev=ch;
	}
	l++;
	w++;
	//output
	printf("lines: %d  words: %d  characters: %d  white spaces: %d  digits: %d\n",l,w,c,ws,d);
	fclose(a);
}
/*
PS F:\> gcc a73-file.c -o k
PS F:\> ./k
lines: 5  words: 19  characters: 67  white spaces: 17  digits: 4
*/

//file4

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include"input.h"
//main function
void main()
{
	FILE *a,*b;
	char ch,s[100],prev;
	int l=0,w=0,c=0,ws=0,d=0;
	//reading file
	a=fopen("input.txt","r");
	b=fopen("sample.txt","w+");
	//checking for existence
	if(a==NULL)
	{
		printf("file not found");
		exit(1);
	}
		//checking for existence
	if(b==NULL)
	{
		printf("file not found");
		exit(1);
	}//copying
	while(!feof(a))
	{ 
		fscanf(a,"%c",&ch);
		if(!feof(a))
		{
			fprintf(b,"%c",ch);
		}
		prev=ch;
	}
	//output
	fseek(b,0,0);
	input(b);
	fclose(a);
	fclose(b);
}
/*
PS F:\> gcc a74-file.c -o k
PS F:\> ./k
hello everyone.
welcome to 2019.
This is c programming.
we are handling files in c
c is fun.
*/
//file 5
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include"input.h"
//main function
void main()
{
	FILE *a;
	char ch,s[100],prev;
	//reading file
	a=fopen("input.txt","r+");
	
	fseek(a,0,0);
	//checking for existence
	if(a==NULL)
	{
		printf("file not found");
		exit(1);
	}
	//replacing vowels with z
	while(!feof(a))
	{ 
		ch=fgetc(a);
		if(!feof(a))
		{
			if((ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u'))
			{
				fseek(a,-1,1);
				fprintf(a,"z");
				fseek(a,1,1);
			}	
		}
		
	}
	//output
	fseek(a,0,0);
	input(a);
	fclose(a);
}
/*
PS F:\> gcc a75-file.c -o k
PS F:\> ./k
hzllz zvzryznz.
wzlczmz tz 2019.
Thzs zs c przgrzmmzng.
wz zrz hzndlzng fzlzs zn c
c zs fzn.
*/

//file 6

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include"input.h"
//main function
void main()
{
	FILE *a,*c;
	char ch,s[100],prev;
	int i=1,l,n;
	printf("enter the value of n:");
	scanf("%d",&n);
	//reading file
	a=fopen("input.txt","r");
	c=fopen("copy.txt","w+");
	//checking for existence
	if(a==NULL)
	{
		printf("file not found");
		exit(1);
	}
	//checking for existence
	if(c==NULL)
	{
		printf("file not found");
		exit(1);
	}
	//finding length of file
	while(!feof(a))
	{ 
		ch=fgetc(a);
		if(!feof(a))
		i++;		
	}
	fseek(a,0,0);
	l=i/2;//the vaue of m is l
	i=0;
	printf("%d\n",l);
	//writing from -n to +n from m
	while(!feof(a))
	{
		i++;
		ch=fgetc(a);
		if((i>=l-n)&(i<=l+n))
		{
			fprintf(c,"%c",ch);
		}
		
	}
	//output
	fseek(c,0,0);
	input(c);
	fclose(a);
	fclose(c);
}
/*
PS F:\> gcc a76-file.c -o k
PS F:\> ./k
enter the value of n:7
44
s is c programm
PS F:\>
*/

//file 7

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

//file 8

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"input.h"
//main function
void main()
{
	FILE *a;
	int i=0,count=0,k=0,l1,l2,n=0;
	char s1[100],s2[100],ch;
	strcpy(s1,"chennai");
	strcpy(s2,"tamilnadu");
	l1=strlen(s1);
	l2=strlen(s2);
	//reading file
	a=fopen("text.txt","r+");
	fpos_t pi,p,pf;
	fgetpos(a,&pi);
	fseek(a,0,2);
	fgetpos(a,&pf);
	p=pf;
	fseek(a,0,0);
	//searching thro file
	while(!feof(a))
	{
		fgetpos(a,&p);
		ch=fgetc(a);
		if(!feof(a))
		{
			for(i=0;i<l1;i++)
			{
				//checking for occurence of chennai
				if(s1[i]==ch)
				{
					ch=fgetc(a);
				}
				else
				{
					k=1;	
				}
			}
			if(k==0)
			{
				//displacing all following characers by 2
				pi=p;
				fseek(a,-1,2);
				fgetpos(a,&p);
				while(pi!=p)
				{
					ch=fgetc(a);
					fseek(a,-1,1);
					fputc(' ',a);
					fputc(' ',a);
					fputc(ch,a);
					fseek(a,-4,1);
					fgetpos(a,&p);
				}
				//wirting tamilnadu which overwrite c  hennai
				for(i=0;i<l2;i++)
				{
					fputc(s2[i],a);
				}
				fsetpos(a,&p);
				fseek(a,l2,1);

			}
			k=0;			
		}
	}//output
	fseek(a,0,0);
	input(a);
	fclose(a);
}/*
PS F:\> gcc a78-file.c -o k
PS F:\> ./k
this is ssn college of engineering at tamilnadu.tamilnadu is otherwise called as singara tamilnadu.
PS F:\>
*/

//file 9

#include<stdio.h>
#include<stdlib.h>
struct account
{
	char name[100],accountno[20];
	float balance;
};
//main function
void main()
{   
	struct account a;
	FILE *f;
	//reading file
	f=fopen("acnt.dat","wb");
	int n,count=0;
	printf("enter no. of accounts :");
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		printf("enter name:");
		scanf("%s",a.name);
		printf("enter account number:");
		scanf("%s",a.accountno);
		printf("enter balance:");
		scanf("%f",&a.balance);
		fwrite(&a,sizeof(a),1,f);		
	}
	fclose(f);
	//reading file
	f=fopen("acnt.dat","rb");
	float r;
	printf("enter minimum balance: ");
	scanf("%f",&r);
	//checking balance and printing
	for(i=0;i<n;i++)
	{
		fread(&a,sizeof(a),1,f);
		if(a.balance<r)
		{
			count++;
			printf("name: %s acno: %s balance: %f \n",a.name,a.accountno,a.balance);
		}
	}
	printf("count=%d",count);
	fclose(f);

}
/*
PS F:\> gcc a79-file.c -o k
PS F:\> ./k
enter no. of accounts :3
enter name:ravi
enter account number:4567890
enter balance:4000
PS F:\> gcc a79-file.c -o k
PS F:\> ./k
enter no. of accounts :3
enter name:ravi
enter account number:3456778
enter balance:4000
PS F:\> gcc a79-file.c -o k
PS F:\> ./k
enter no. of accounts :3
enter name:ravi
enter account number:4567895
enter balance:4000
enter name:kumar
enter account number:3457897
enter balance:1000
enter name:balu
enter account number:6742367
enter balance:2000
enter minimum balance: 2500
name: kumar acno: 3457897 balance: 1000.000000
name: balu acno: 6742367 balance: 2000.000000
count=2
*/

//file 10

#include <stdio.h>
#include <conio.h>
#include <string.h>

struct person{
     char name[20],tel[20],pin[10];
};

//function prototypes
void appendData(int *n);
void updateData(int n);
void deleteData(int *n);
void display(int n);

void main()
{
    struct person p[30];
    int ch=0;
    int i,n,*m=&n;
    FILE *fp;
    fp=fopen("tel.dat","w");

    printf("Enter number of persons:");
    scanf("%d",m);
    for(i=0;i<*m;i++)
    {
        printf("Enter name: ");
        scanf("%s",p[i].name);
        
        printf("Telephone No.: ");
        scanf("%s",p[i].tel);

        printf("Enter pin: ");
        scanf("%s",p[i].pin);
	    fwrite(&p[i],sizeof(p[i]),1,fp);
    }
    fclose(fp);

    while(ch!=5){
    printf("\n");
    printf("1.Append Record\n");
    printf("2.Update Record\n");
    printf("3.Delete Record\n");
    printf("4.Display\n");
    printf("5.Exit\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);

    switch(ch){
         case 1: //call append record
            appendData(m);
            //printf("%d",*m);
            break;
         case 2: //call find record
             updateData(*m);
             break;
         case 3: //Read all record
             deleteData(m);
             //printf("%d",*m);
             break;
         case 4:display(*m);
         		break;
         case 5:break;
         default :printf("invalid\n");
    }

    }
}

//functions
void appendData(int *n)
{
		FILE *fp;
		int k;
		struct person m;
        *n+=1;
        fp=fopen("tel.dat","a+");
        //fseek(fp,0,2);
        printf("\nEnter name: ");
        scanf("%s",m.name);
        printf("\nTelephone No.: ");
        scanf("%s",m.tel);
        printf("\nEnter pin: ");
        scanf("%s",m.pin);

        fwrite(&m,sizeof(m),1,fp);
        fclose(fp);
    	
        printf("\nRecord successfully appended\n");

}

void updateData(int n)
{
	FILE *fp;
    int i,f=0;
    struct person p;
    char nm[20];
    fp=fopen("tel.dat","r+");
    printf("\nEnter name of record to be updated: ");
    scanf("%s",nm);
    int k;
    k=sizeof(p);
    for(i=0;i<n;i++)
    {
    	
        fread(&p,sizeof(p),1,fp);
        if(strcmp(nm,p.name)==0)
        {    				
           			 /*printf("\nEnter new name: ");
                    scanf("%s",p.name);*/


                    printf("\nEnter new telephone no.: ");
                    scanf("%s",p.tel);


                    printf("\nEnter new pin: ");
                    scanf("%s",p.pin);
                    
    				fseek(fp,-1*k,1);
    				fwrite(&p,sizeof(p),1,fp);
    				f=1;
        }
    }
    if(f==1)
    printf("\nRecord successfully updated\n");
    else
    printf("record not found\n");
    fclose(fp);

}


void deleteData(int *n)
{
    FILE *fp;
    int i=0;
    char nm[20];
    FILE *ft;
    int k=0;
    struct person p;

    printf("\nEnter name of record to be deleted: ");
    scanf("%s",nm);

    fp = fopen("tel.dat","r+");
    ft = fopen("Temp.dat","w+");

    for(i=0;i<*n;i++)
    {
       fread(&p,sizeof(p),1,fp);
       if(strcmp(nm,p.name)!=0)
       {
	       fwrite(&p,sizeof(p),1,ft);
	   }
	   else
	   k=1;
    }

    fclose(fp);
    fclose(ft);
    remove("tel.dat");
    rename("Temp.dat","tel.dat");
    if(k==1)
    {
	    *n-=1;
	    printf("\nRecord successfully deleted\n");
    }
    else
    printf("record not found\n");
}
void display(int n)
{
	int i;
	FILE *fp;
	struct person p;
	fp=fopen("tel.dat","r");
	for(i=0;i<n;i++)
	{
		fread(&p,sizeof(p),1,fp);

        printf("\nEnter name: %s",p.name);
        printf("\nTelephone No.:%s ",p.tel);
        printf("\nEnter pin: %s ",p.pin);
        
	}
	fclose(fp);
}
/*
PS F:\> gcc a10-file.c -o k
PS F:\> ./k
Enter number of persons:2
Enter name: ravi
Telephone No.: 0987654321
Enter pin: 123456
Enter name: mohan
Telephone No.: 1234567892
Enter pin: 654321

1.Append Record
2.Update Record
3.Delete Record
4.Display
5.Exit
Enter your choice : 2

Enter name of record to be updated: mohan

Enter new telephone no.: 5432109876

Enter new pin: 543987

Record successfully updated

1.Append Record
2.Update Record
3.Delete Record
4.Display
5.Exit
Enter your choice : 4

Enter name: ravi
Telephone No.:0987654321
Enter pin: 123456
Enter name: mohan
Telephone No.:5432109876
Enter pin: 543987
1.Append Record
2.Update Record
3.Delete Record
4.Display
5.Exit
Enter your choice : 1

Enter name: takur

Telephone No.: 7654398765

Enter pin: 765234

Record successfully appended

1.Append Record
2.Update Record
3.Delete Record
4.Display
5.Exit
Enter your choice : 4

Enter name: ravi
Telephone No.:0987654321
Enter pin: 123456
Enter name: mohan
Telephone No.:5432109876
Enter pin: 543987
Enter name: takur
Telephone No.:7654398765
Enter pin: 765234
1.Append Record
2.Update Record
3.Delete Record
4.Display
5.Exit
Enter your choice : 3

Enter name of record to be deleted: mohan

Record successfully deleted

1.Append Record
2.Update Record
3.Delete Record
4.Display
5.Exit
Enter your choice : 4

Enter name: ravi
Telephone No.:0987654321
Enter pin: 123456
Enter name: takur
Telephone No.:7654398765
Enter pin: 765234
1.Append Record
2.Update Record
3.Delete Record
4.Display
5.Exit
Enter your choice : 5
PS F:\>
*/

//file 11

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct 
{
	char country[50];
	char capital[50];
}cap;
//writing in a function
void input()
{
	cap a;
	FILE *fp=fopen("coucap.dat","ab+");
	printf("Country : ");
	scanf(" %[^\n]",a.country);
	printf("Capital : ");
	scanf(" %[^\n]",a.capital);
	fwrite(&a,sizeof(a),1,fp);
	fclose(fp);
}
//deleting a record
void delete_rec()
{
	FILE *fp,*pf;
	cap c;
	char coun[50];
	fp=fopen("coucap.dat","rb+");
	pf=fopen("temp.dat","wb+");
	printf("Country (deletion) : ");
	scanf(" %[^\n]",coun);
	while(fread(&c,sizeof(c),1,fp))
	{
		if(strcmp(coun,c.country)!=0)
			fwrite(&c,sizeof(c),1,pf);
	}
	remove("coucap.dat");
	rename("temp.dat","coucap.dat");
	fclose(fp);
	fclose(pf);
}

void capsrch()
{
	cap c;
	char coun[50];
	int flag=1;
	FILE *fp=fopen("coucap.dat","rb+");
	printf("Country : ");
	scanf(" %[^\n]",coun);
	while(fread(&c,sizeof(c),1,fp))
	{
		if(strcmp(c.country,coun)==0)
		{
			printf("Capital : %s",c.capital);
			flag=0;
			break;
		}
	}
	if(flag)
	{
		printf("Sorry !!!\nCountry still not updated on the database\n");
	}
	fclose(fp);
}

void list()
{
	cap c;
	FILE *fp=fopen("coucap.dat","rb+");
	printf("The list :\n");
	printf("\n%20s %20s %10s\n","COUNTRY   ","","  CAPITAL ");
	while(fread(&c,sizeof(c),1,fp))
	{
		printf("%7s %-30s %-30s\n"," ",c.country,c.capital);
	}
	fclose(fp);
}

void cousrch()
{
	cap c;
	char cap[50];
	int flag=1;
	FILE *fp=fopen("coucap.dat","rb+");
	printf("Capital : ");
	scanf(" %[^\n]",cap);
	while(fread(&c,sizeof(c),1,fp))
	{
		if(strcmp(c.capital,cap)==0)
		{
			printf("Country : %s",c.country);
			flag=0;
			break;
		}
	}
	if(flag)
	{
		printf("Sorry !!!\nCapital not found \n");
	}
	fclose(fp);
}


int main()
{
	int choice;
	start:
	printf("\n\nDRIVER-MENU :-\n\t1. Appending a Record\n\t2. Deleting a record\n\t3. List\n\t4. Country to capital\n\t5. Capital to country\n\t6. Exit\n\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1: {
					input();
					goto start;  
				}
		
		case 2: {
					delete_rec();
					goto start;
				}
		
		case 3: {
					list();
					goto start;
				}

		case 4: {
					capsrch();
					goto start;
				}

		case 5: {
					cousrch();
					goto start;
				}

		case 6: goto end;
		default : goto start;	
	}
	
	end:
	printf("\n *** THANK YOU *** \n");
	return 0;
}

/*
PS F:\> gcc a711-file.c -o k
PS F:\> ./k


DRIVER-MENU :-
        1. Appending a Record
        2. Deleting a record
        3. List
        4. Country to capital
        5. Capital to country
        6. Exit

Enter your choice : 1
Country : india
Capital : delhi


DRIVER-MENU :-
        1. Appending a Record
        2. Deleting a record
        3. List
        4. Country to capital
        5. Capital to country
        6. Exit

Enter your choice : 1
Country : china
Capital : beijing


DRIVER-MENU :-
        1. Appending a Record
        2. Deleting a record
        3. List
        4. Country to capital
        5. Capital to country
        6. Exit

Enter your choice : 1
Country : britain
Capital : london


DRIVER-MENU :-
        1. Appending a Record
        2. Deleting a record
        3. List
        4. Country to capital
        5. Capital to country
        6. Exit

Enter your choice : 2
Country (deletion) : britain


DRIVER-MENU :-
        1. Appending a Record
        2. Deleting a record
        3. List
        4. Country to capital
        5. Capital to country
        6. Exit

Enter your choice : 3
The list :

          COUNTRY                           CAPITAL
        india                          delhi
        china                          beijing
        britain                        london


DRIVER-MENU :-
        1. Appending a Record
        2. Deleting a record
        3. List
        4. Country to capital
        5. Capital to country
        6. Exit

Enter your choice : 4
Country : britain
Capital : london

DRIVER-MENU :-
        1. Appending a Record
        2. Deleting a record
        3. List
        4. Country to capital
        5. Capital to country
        6. Exit

Enter your choice : 6

 *** THANK YOU ***
 */
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
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
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
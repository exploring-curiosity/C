#include<stdio.h>
typedef struct
{
	float rpart,ipart;
}comp;
void read(comp v)
{
	printf("enter real part:");
	scanf("%f",&v.rpart);

	printf("enter imaginary part:");
	scanf("%f",&v.ipart);
}
void write(comp v)
{
	printf("%f + i%f",v.rpart,v.ipart);
}
/*comp add(comp v1,comp v2)
{
	
}

comp sub(comp v1,comp v2)
{
}*/
void main()
{
	comp v1,v2,v3;
	int ch;
	char rep;
	do
	{
		read(v1);
		read(v2);
		printf("1.add 2.subtract\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			//res=add(var1,var2);
			comp v3;
	v3.rpart=v1.rpart+v2.rpart;

	v3.ipart=v1.ipart+v2.ipart;
	
			write(v3);
		}
		if(ch==2)
		{
			//res=sub(var1,var2);
			
	comp v3;
	v3.rpart=v1.rpart-v2.rpart;

	v3.ipart=v1.ipart-v2.ipart;
	
			write(v3);
		}
		printf("do u want to continue?");
		scanf(" %c",&rep);
	}while(rep=='y');
}

#include<stdio.h>
void main(int argc,char *argv[])
{
	int a,b;
	char sym;
	a=argv[1][0]-48;
	b=argv[3][0]-48;
	sym=*argv[2];
	switch(sym)
	{
		case '+':printf("%d",a+b);break;
	}


}
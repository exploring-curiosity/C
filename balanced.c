#include<stdio.h>
typedef struct
{
	int top;
	char sym[100];
}stack;
void initialize(stack *s)
{
	s->top=-1;
}
void push(stack *s,char c)
{
	s->top++;
	s->sym[s->top]=c;
}
void pop(stack *s)
{
	s->top--;
}
int balanced(char data[]);
void main()
{	
	char data[1000];
	int x=0;
	gets(data);
	printf("please wait..");
	x=balanced(data);
	printf("The data is ");
	if(x==0)
	printf("\nUNBALANCED\n");
	else
	printf("\nBALANCED\n");
}
int balanced(char data[])
{
	int i;
	stack *s;
	char temp;
	initialize(s);
	for(i=0;data[i]!='\0';i++)
	{
		if(data[i]=='{'||data[i]=='['||data[i]=='(')
		push(s,data[i]);
		else if(data[i]=='}'||data[i]==']'||data[i]==')')
		{	
			if(data[i]=='}')
			temp='{';
			if(data[i]==']')
			temp='[';
			if(data[i]==')')
			temp='(';

			if(s->top>=0)
			{
				if(s->sym[s->top]==temp)
				{
					pop(s);
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
	}
	if(s->top>-1)
	{
		return 0;
	}
	return 1; 
}
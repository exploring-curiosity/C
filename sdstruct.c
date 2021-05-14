#include<stdio.h>
#include<stdlib.h>
struct student
{
	int rno;
	int mark;
};
void main()
{
	struct student (*s)[5];
	int i;
	s=malloc(sizeof(struct student));
	for(i=0;i<4;i++)
	{
		printf("enter student%d marks,reg_no:",i+1);
		scanf("%d%d",&(*(*(s)+i)).mark,&(*(*(s)+i)).rno);
	}
}

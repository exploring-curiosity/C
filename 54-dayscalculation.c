#include<stdio.h>
#include<stdlib.h>
long convert(int mm,int dd,int yy);
void main()
{
	long *a,*b,j,k;
	int *m,*y,*d,mm,yy,dd;
	a=&j;
	b=&k;
	m=&mm;
	y=&yy;
	d=&dd;
	printf("enter 1st date dd /mm /yy:");
	scanf("%d%d%d",d,m,y);
	*a=convert(*m,*d,*y);//calculates date1 from base date
	printf("enter 2nd date dd /mm /yy:");
	scanf("%d%d%d",d,m,y);
	*b=convert(*m,*d,*y);//calculates date2 from base date
	int c=*b-*a;
	if(c>0)
	printf("days=%d",c);
	else
	printf("days=%d",-1*c);
	//we get their difference as output
}

long convert(int mm,int dd,int yy)		//count no of days from base date
{
	long ndays;
	long ncycles;
	int nyears;
	int day;
	yy-=1900;
	ndays=(long)(30.42*(mm-1))+dd;
	if(mm==2)
	++ndays;
	if((mm>2)&(mm<8))
	--ndays;
	if((yy%4==0)&&mm>2)
	++ndays;
	ncycles=yy/4;
	ndays+=ncycles*1461;
	nyears=yy%4;
	if(nyears>0)
	ndays+=365*nyears+1;
	if(ndays>59)
	--ndays;
	return ndays;			//returns the specified value of number of days
}
/*
enter 1st date dd /mm /yy:23 5 1987
enter 2nd date dd /mm /yy:28 9 1996
days=3416
*/
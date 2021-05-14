#include<stdio.h>
#include<stdlib.h>
int result(int c,int p);
void main()
{
	//randomize();
	int c,p,k,cs=0,ps=0;
	int i;
	for(i=0;i<10;i++)
	{//randomize();
	c=rand()%10; 
	if(c<3)
	c=1;
	else if (c>6)
	c=3;
	else
	c=2;
	printf("enter choice:\n1.rock\n2.paper\n3.scissor\n    ");
	scanf("%d",&p);
	k=result(c,p);
	printf(" COMPUTER CHOICE :%d\n",c);
	if(k==-1)
	printf("       DRAW \n");
	else if(k==1)
	{
		ps+=1;
		printf("     PLAYER WINS\n");
	}
	else
	{
		cs+=1;
		printf("     COMPUTER WINS\n");
	}	
	printf("PLAYER SCORE: %d \t COMPUTER SCORE: %d\n",ps,cs);
    }

    printf("     GAME OVER\n");
    if(cs==ps)
    {
    	printf("       DRAW\n");
    }
    else if(ps>cs)
    {
    	printf("      YOU WIN\n");
    }
    else
    printf("  COMPUTER WINS \n");
}
int result(int c,int p)
{
	if(c==p)
	return -1;
	int r;
	r=c+p;
	if(r%2==1)
	{
		if(p>c)
		return 1;
		else 
		return 0;
	}
	else
	{
		if(p<c)
		return 1;
		else 
		return 0;
	}	
}/*

enter choice:
1.rock
2.paper
3.scissor
    3
 COMPUTER CHOICE :1
     COMPUTER WINS
PLAYER SCORE: 0          COMPUTER SCORE: 1
enter choice:
1.rock
2.paper
3.scissor
    2
 COMPUTER CHOICE :3
     COMPUTER WINS
PLAYER SCORE: 0          COMPUTER SCORE: 2
enter choice:
1.rock
2.paper
3.scissor
    3
 COMPUTER CHOICE :2
     PLAYER WINS
PLAYER SCORE: 1          COMPUTER SCORE: 2
enter choice:
1.rock
2.paper
3.scissor
    2
 COMPUTER CHOICE :1
     PLAYER WINS
PLAYER SCORE: 2          COMPUTER SCORE: 2
enter choice:
1.rock
2.paper
3.scissor
    1
 COMPUTER CHOICE :3
     PLAYER WINS
PLAYER SCORE: 3          COMPUTER SCORE: 2
enter choice:
1.rock
2.paper
3.scissor
    3
 COMPUTER CHOICE :2
     PLAYER WINS
PLAYER SCORE: 4          COMPUTER SCORE: 2
enter choice:
1.rock
2.paper
3.scissor
    2
 COMPUTER CHOICE :3
     COMPUTER WINS
PLAYER SCORE: 4          COMPUTER SCORE: 3
enter choice:
1.rock
2.paper
3.scissor
    1
 COMPUTER CHOICE :3
     PLAYER WINS
PLAYER SCORE: 5          COMPUTER SCORE: 3
enter choice:
1.rock
2.paper
3.scissor
    3
 COMPUTER CHOICE :1
     COMPUTER WINS
PLAYER SCORE: 5          COMPUTER SCORE: 4
enter choice:
1.rock
2.paper
3.scissor
    2
 COMPUTER CHOICE :2
       DRAW
PLAYER SCORE: 5          COMPUTER SCORE: 4
     GAME OVER
      YOU WIN
      */
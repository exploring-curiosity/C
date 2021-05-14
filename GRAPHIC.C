#include<mus.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>

struct user
{
	char un[100];
	char pw[100];
};
int navigation(char b1[100],char b2[100]);
int login();
void newuser();
void callnewentry(char username[80]){}
void callrecords(char username[80]){}
void callstatisyics(char username[80]);
int checkunpw(char user[100],char pass[100]);
int checkun(char user[80]);
void main()
{
	struct user u;
	int the_end=0,input_pos=0,l,button;
	char username[80],password[80],un[12],pw[12];
	char inputbuf[80],c,showtext[15];
	int valid=0;
	int button_in_1=0;
	int button_in_2=0;
	int button_in_3=0;
	int button_in_4=0;
	int button_in_5=0;
	int button_in_6=0;
	char s[100];
	int x,y,mclick=0;
	float k;
	time_t t;
	char d[30],d1[30];
	int z,a,b,sec;
	int i,j,gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\BGI");

	cleardevice();
	setcolor(GREEN);
	setbkcolor(WHITE);
	for(i=0;i<180;i++)
	{
		for(j=0;j<20-i/10;j++)
		arc(300,200,255-i,270-i,50+i/2+j);
		delay(10);
	}
	for(i=0;i<180;i++)
	{
		for(j=0;j<10-i/20;j++)
		arc(300,200,255-i,270-i,30+i/2+j);
		delay(10);
	}
	setcolor(RED);
	for(i=0;i<160;i++)
	{
		if(255+i<320||255+i>350)
			line(255+i,180,265+i,150);
		else
			line(237+i,235,283+i,95);
		delay(10);
	}
	settextstyle(7,0,5);
	outtextxy(200,300," C - CLINIC");
	delay(2000);
	setbkcolor(WHITE);
	setcolor(WHITE);
	for(k=0;k<300;k++)
	{
		fillellipse(300,200,k+5,k+4);
		delay(10);
	}
	cleardevice();
	valid=login();
	detect_mouse ();
	showmouse_text ();
	showmouse_graphics();
	mclick=0;
	cleardevice();
	setbkcolor(BLACK);
	time(&t);
	i=0;
	in.x.ax = 3;
	int86 (0X33,&in,&out);
	pg1:
	button=0;
	mclick=0;
	while(mclick<1)
	{
		mclick=0;
		in.x.ax = 3;
		int86 (0X33,&in,&out);
		button=out.x.bx&7 ;
		int86 (0X33,&in,&out);
		button_in_1=0;
		button_in_2=0;
		button_in_3=0;
		button_in_4=0;
		button_in_5=0;
		button_in_6=0;
		ctime(&t);
		sprintf(d,"%s",ctime(&t));
		setcolor(WHITE);
		settextstyle(9,0,1);
		outtextxy(110,370,d);
		setcolor(BLUE);
		for(j=0;j<5;j++)
		{
		arc(300,200,0+3*i,80+3*i,80+j);
		arc(300,200,120+3*i,200+3*i,80+j);
		arc(300,200,240+3*i,320+3*i,80+j);
		}
		if(i==120)
		i=0;
		in.x.ax = 1;
		int86 (0X33,&in,&out);
		{

			in.x.ax = 3;
			int86 (0X33,&in,&out);
			{
				x = out.x.cx;
				y = out.x.dx;
			}
		}
		mclick+=out.x.bx;
		for(j=0;j<15;j++)
		{
		 circle(300,200,100+j) ;
		}
		line(220,120,180,80);
		line(380,280,420,320);
		line(185,200,150,200);
		line(415,200,450,200);
		line(380,120,420,80);
		line(220,280,180,320);
		line(180,80,150,80);
		line(180,320,150,320);
		line(420,320,450,320);
		line(420,80,450,80);
		if(y>60&y<100&x>50&x<140)
		button_in_1=1;

		if(y>300&y<340&x>50&x<140)
		button_in_2=1;

		if(y>180&y<220&x>50&x<140)
		button_in_3=1;


		if(y>60&y<100&x>460&x<550)
		button_in_4=1;

		if(y>300&y<340&x>460&x<550)
		button_in_5=1;

		if(y>180&y<220&x>460&x<550)
		button_in_6=1;

		for(z=0;z<3;z++)
		{
			if(button_in_1==1)
			{setcolor(WHITE);}
			line(160,60+z,50,60+z);
			line(140,100+z,30,100+z);
			line(30+z,100,50+z,60);
			line(160-z,60,140-z,100);

			setcolor(BLUE);

			if(button_in_2==1)
			{setcolor(WHITE);}

			line(160,300+z,50,300+z);
			line(140,340+z,30,340+z);
			line(30+z,340,50+z,300);
			line(160-z,300,140-z,340);

			setcolor(BLUE);

			if(button_in_3==1)
			{setcolor(WHITE);}

			line(160,180+z,50,180+z);
			line(140,220+z,30,220+z);
			line(30+z,220,50+z,180);
			line(160-z,180,140-z,220);

			setcolor(BLUE);

			if(button_in_4==1)
			{setcolor(WHITE);}

			line(460,60+z,570,60+z);
			line(440,100+z,550,100+z);
			line(550+z,100,570+z,60);
			line(460-z,60,440-z,100);

			setcolor(BLUE);

			if(button_in_5==1)
			{setcolor(WHITE);}

			line(460,300+z,570,300+z);
			line(440,340+z,550,340+z);
			line(550+z,340,570+z,300);
			line(460-z,300,440-z,340);

			setcolor(BLUE);

			if(button_in_6==1)
			{setcolor(WHITE);}

			line(460,180+z,570,180+z);
			line(440,220+z,550,220+z);
			line(550+z,220,570+z,180);
			line(460-z,180,440-z,220);
			setcolor(BLUE);

		}
		setcolor(WHITE);
		settextstyle(2,0,6);
		outtextxy(50,70,"NEW-ENTRY");
		outtextxy(60,190,"UPDATE");
		outtextxy(50,310,"REMAINDER");
		outtextxy(470,70,"RECORDS");
		outtextxy(460,190,"STATISTICS");
		outtextxy(480,310,"EXIT");

		setcolor(RED);
		bar(230,190,370,210);
		bar(290,270,310,130);
		if((strcmp(d,d1)))
		{
			cleardevice();
			i++;
		}
		strcpy(d1,d);
	}
	cleardevice();
	if(button_in_1)
	{
		cleardevice();
		outtextxy(200,250,"NEW-ENTRY");
		delay(2000);
		callnewentry(username);
		cleardevice();
		goto pg1;
	}
	if(button_in_2)
	{
		cleardevice();
		outtextxy(200,250,"REMAINDER");
		delay(2000);
		cleardevice();
		goto pg1;
	}
	if(button_in_3)
	{
		cleardevice();
		outtextxy(200,250,"UPDATE");
		delay(2000);
		cleardevice();
		goto pg1;
	}
	if(button_in_4)
	{
		cleardevice();
		outtextxy(200,250,"RECORDS");
		delay(2000);
		cleardevice();
		goto pg1;
	}
	if(button_in_5)
	{
		cleardevice();
		outtextxy(200,250,"EXIT");
		delay(2000);
		cleardevice();
	}
	if(button_in_6)
	{
		cleardevice();
		outtextxy(200,250,"STATISTICS");
		delay(2000);
		cleardevice();
		goto pg1;
	}
	getch ();
	hide_mouse ();
	closegraph();
	getch();
}
void newuser()
{
	FILE *p;
	struct user U;
	int l,valid,i,the_end=0,mclick=0,x,y,button,input_pos=0;
	char showtext[12],inputbuf[100],username[100],c,password[100],un[12],pw[12];
	cleardevice();
	p=fopen("users.dat","ab+");
	rectangle(300,200,400,220);
	rectangle(300,230,400,250);
	rectangle(300,260,400,280);
	outtextxy(200,205,"username:");
	outtextxy(200,235,"password:");
	outtextxy(310,265,"create");

	inputbuf[0]='\0';
	un[0]='\0';
	pw[0]='\0';
	cleardevice();

	graphdefaults();
	un[0]='\0';
	pw[0]='\0';
	inputbuf[0]='\0';
	setbkcolor(BLACK);
	setcolor(WHITE);
	rectangle(250,220,400,240);
	outtextxy(200,200,"ENTER DATA");
	rectangle(250,250,400,270);
	outtextxy(150,225,"USERNAME:");
	outtextxy(150,255,"PASSWORD:");
	rectangle(230,290,280,310);
	outtextxy(235,295,"CREATE");
	hide_mouse();

	detect_mouse ();
	showmouse_text ();
	showmouse_graphics();
	in.x.ax = 3;
	int86 (0X33,&in,&out);

	mclick=0;
	while(!mclick)
	{
		in.x.ax = 1;
		int86 (0X33,&in,&out);
		in.x.ax = 3;
		int86 (0X33,&in,&out);
		x = out.x.cx;
		y = out.x.dx;
		in.x.ax = 3;
		int86 (0X33,&in,&out);
		button=out.x.bx&7 ;
		int86 (0X33,&in,&out);

		if((x>250)&&(x<400)&&(y>220)&&(y<240)&&(button==1))
		{  
			hide_mouse();
			do
			{
				c = getch();
				switch (c)
				{
					case 8: /* backspace */
						if (input_pos)
						{
							input_pos--;
							inputbuf[input_pos] ='\0';
							cleardevice();
							rectangle(250,220,400,240);
							outtextxy(200,200,"ENTER DATA");
							rectangle(250,250,400,270);
							outtextxy(150,225,"USERNAME:");
							outtextxy(150,255,"PASSWORD:");
							rectangle(230,290,280,310);
							outtextxy(255,255,pw);
							outtextxy(235,295,"CREATE");
						}
						break;
					case 13: /* return */
						the_end = 1;
						break;
					case 27: /* Escape = Abort */
						inputbuf[0] = '\0';
						the_end = 1;
						break;
					default:
						if (input_pos < 80-1 && c >= ' ' && c <= '~')
						{
							inputbuf[input_pos] = c;
							input_pos++;
							inputbuf[input_pos] ='\0';
						}
				}
				cleardevice();
				rectangle(250,220,400,240);
				outtextxy(200,200,"ENTER DATA");
				rectangle(250,250,400,270);
				outtextxy(150,225,"USERNAME:");
				outtextxy(150,255,"PASSWORD:");
				rectangle(230,290,280,310);
				outtextxy(255,255,pw);
				outtextxy(235,295,"CREATE");
				if(input_pos>12)
				{
					for(i=0;i<12;i++)
					showtext[11-i]=inputbuf[input_pos-i-1];
					showtext[12]='\0';
				}
				else
				strcpy(showtext,inputbuf);
				outtextxy (255,225,showtext);
			}while(!the_end);
			the_end=0;
			l=strlen(inputbuf);
			strcpy(username,inputbuf);
			for(i=0;i<12;i++)
			un[i]=username[i];
			un[i]='\0';
			for(i=0;i<l;i++)
			inputbuf[i]='\0';
			detect_mouse ();
			showmouse_text ();
			showmouse_graphics();
			button=0;
			for(i=0;i<12;i++)
			showtext[i]='\0';
			input_pos=0;
		}
		if((x>250)&&(x<400)&&(y>250)&&(y<270)&&(button==1))
		{  
			hide_mouse();
			do
			{
				c = getch();
				switch (c)
				{
					case 8: /* backspace */
						if (input_pos)
						{
							input_pos--;
							inputbuf[input_pos] ='\0';
							cleardevice();
							rectangle(250,220,400,240);
							outtextxy(200,200,"ENTER DATA");
							rectangle(250,250,400,270);
							outtextxy(150,225,"USERNAME:");
							outtextxy(150,255,"PASSWORD:");
							rectangle(230,290,280,310);
							outtextxy(255,225,un);
							outtextxy(235,295,"CREATE");
						}
						break;
					case 13: /* return */
						the_end = 1;
						break;
					case 27: /* Escape = Abort */
						inputbuf[0] = '\0';
						the_end = 1;
						break;
					default:
						if (input_pos < 80-1 && c >= ' ' && c <= '~')
						{
							inputbuf[input_pos] = c;
							input_pos++;
							inputbuf[input_pos] ='\0';
						}
				}
				cleardevice();
				rectangle(250,220,400,240);
				outtextxy(200,200,"ENTER DATA");
				rectangle(250,250,400,270);
				outtextxy(255,225,un);
				outtextxy(150,225,"USERNAME:");
				outtextxy(150,255,"PASSWORD:");
				rectangle(230,290,280,310);
				outtextxy(235,295,"CREATE");
				if(input_pos>12)
				{
					for(i=0;i<12;i++)
					showtext[11-i]='*';
					showtext[12]='\0';
				}
				else
				{
					for(i=0;i<input_pos;i++)
					showtext[i]='*';
					showtext[i]='\0';
				}
				outtextxy (255,255, showtext);
			}while(!the_end);
			the_end=0;
			strcpy(password,inputbuf);
			l=strlen(inputbuf);
			for(i=0;i<l;i++)
			inputbuf[i]='\0';
			for(i=0;i<strlen(password);i++)
			pw[i]='*';
			pw[i]='\0';
			detect_mouse ();
			showmouse_text ();
			showmouse_graphics();
			button=0;
			for(i=0;i<12;i++)
			showtext[i]='\0';
			input_pos=0;
		}
		if((x>230)&&(x<280)&&(y>290)&&(y<310))
		{
			if(button==1)
			{
				mclick=1;
				button=0;
				valid=checkun(username);
				if(!valid)
				{
					cleardevice();
					settextstyle(1,0,4);
					outtextxy(200,200,"created successfully");
					delay(2000);
					mclick=1;
					graphdefaults();
					//outtextxy(200,220,password);
					//delay(2000);
					cleardevice();
					strcpy(U.un,username);
					strcpy(U.pw,password);

					fwrite(&U,sizeof(U),1,p);
				 }
				 else
				 {
					cleardevice();
					settextstyle(1,0,4);
					outtextxy(200,200,"creation not successful");
					delay(2000);
					mclick=0;
					graphdefaults();
					cleardevice();
					rectangle(250,220,400,240);
					outtextxy(200,200,"ENTER DATA");
					rectangle(250,250,400,270);
					outtextxy(255,225,un);
					outtextxy(150,225,"USERNAME:");
					outtextxy(150,255,"PASSWORD:");
					rectangle(230,290,280,310);
					outtextxy(235,295,"CREATE");
				  }
			}
		}
	}
	hide_mouse();
	inputbuf[0]='\0';
	clrscr();
	cleardevice();
	fclose(p);
}
int checkun(char user[100])
{
	FILE *a;
	struct user U;
	a=fopen("users.dat","rb");
	while(!feof(a))
	{
		fread(&U,sizeof(U),1,a);
		if(!strcmp(U.un,user))
		{
			fclose(a);
			return 1;
		}
	}
	fclose(a);
	return 0;
}
int checkunpw(char usern[100],char pass[100])
{
	FILE *a;
	int n=0;

	struct user U;

	a=fopen("users.dat","rb");
	while(fread(&U,sizeof(U),1,a))
	{
		n++;
		if(!strcmp(U.un,usern))
		{
			if(!strcmp(U.pw,pass))
			{
				fclose(a);
				return n;
			}
		}
	}
	fclose(a);
	return 0;
}
int login()
{
	char s[100];
	int x,y,mclick=0;
	float k;
	time_t t;
	char d[30],d1[30];
	int z,a,b,sec;
	int i,j,gdriver=DETECT,gmode;

	int the_end=0,input_pos=0,l,button;
	char username[80],password[80],un[12],pw[12];
	char inputbuf[80],c,showtext[15];
	int valid=0;


	graphdefaults();
	un[0]='\0';
	pw[0]='\0';
	inputbuf[0]='\0';
	setbkcolor(BLACK);
	setcolor(WHITE);
	rectangle(250,220,400,240);
	outtextxy(200,200,"ENTER PASSWORD");
	rectangle(250,250,400,270);
	outtextxy(150,225,"USERNAME:");
	outtextxy(150,255,"PASSWORD:");
	rectangle(230,290,280,310);
	outtextxy(235,295,"LOGIN");
	outtextxy(350,290,"new_user?");

	detect_mouse ();
	showmouse_text ();
	showmouse_graphics();
	in.x.ax = 3;
	int86 (0X33,&in,&out);

	mclick=0;
	while(!mclick)
	{
		in.x.ax = 1;
		int86 (0X33,&in,&out);
		in.x.ax = 3;
		int86 (0X33,&in,&out);
		x = out.x.cx;
		y = out.x.dx;
		in.x.ax = 3;
		int86 (0X33,&in,&out);
		button=out.x.bx&7 ;
		int86 (0X33,&in,&out);

		if((x>250)&&(x<400)&&(y>220)&&(y<240)&&(button==1))
		{      	//un[0]='\0';
			//printf("username");
			hide_mouse();

			do
			{
				c = getch();
				switch (c)
				{
					case 8: // backspace
						if (input_pos)
						{
							input_pos--;
							inputbuf[input_pos] ='\0';
							cleardevice();
							rectangle(250,220,400,240);
							outtextxy(200,200,"ENTER PASSWORD");
							rectangle(250,250,400,270);
							outtextxy(150,225,"USERNAME:");
							outtextxy(150,255,"PASSWORD:");
							rectangle(230,290,280,310);
							outtextxy(255,255,pw);
							outtextxy(235,295,"LOGIN");
							outtextxy(350,290,"new_user?");
						}
						break;
					case 13: // return
						the_end = 1;
						break;
					case 27: // Escape = Abort
						inputbuf[0] = '\0';
						the_end = 1;
						break;
					default:
						if (input_pos < 80-1 && c >= ' ' && c <= '~')
						{
							inputbuf[input_pos] = c;
							input_pos++;
							inputbuf[input_pos] ='\0';
						}
				}
				cleardevice();
				rectangle(250,220,400,240);
				outtextxy(200,200,"ENTER PASSWORD");
				rectangle(250,250,400,270);
				outtextxy(150,225,"USERNAME:");
				outtextxy(150,255,"PASSWORD:");
				rectangle(230,290,280,310);
				outtextxy(255,255,pw);
				outtextxy(235,295,"LOGIN");
				outtextxy(350,290,"new_user?");
				if(input_pos>12)
				{
					for(i=0;i<12;i++)
					showtext[11-i]=inputbuf[input_pos-i-1];
					showtext[12]='\0';
				}
				else
				strcpy(showtext,inputbuf);
				outtextxy (255,225,showtext);
			}while(!the_end);
			the_end=0;
			l=strlen(inputbuf);
			strcpy(username,inputbuf);
			for(i=0;i<12;i++)
			un[i]=username[i];
			un[i]='\0';
			for(i=0;i<l;i++)
			inputbuf[i]='\0';
			detect_mouse ();
			showmouse_text ();
			showmouse_graphics();
			button=0;
			for(i=0;i<12;i++)
			showtext[i]='\0';
			input_pos=0;
		}
	    if((x>250)&&(x<400)&&(y>250)&&(y<270)&&(button==1))
		{ 
			hide_mouse();

			do
			{
				c = getch();
				switch (c)
				{
					case 8: // backspace
						if (input_pos)
						{
							input_pos--;
							inputbuf[input_pos] ='\0';
							cleardevice();
							rectangle(250,220,400,240);
							outtextxy(200,200,"ENTER PASSWORD");
							rectangle(250,250,400,270);
							outtextxy(150,225,"USERNAME:");
							outtextxy(150,255,"PASSWORD:");
							rectangle(230,290,280,310);
							outtextxy(255,225,un);
							outtextxy(235,295,"LOGIN");
							outtextxy(350,290,"new_user?");
						}
						break;
					case 13: // return
						the_end = 1;
						break;
					case 27: // Escape = Abort
						inputbuf[0] = '\0';
						the_end = 1;
						break;
					default:
						if (input_pos < 80-1 && c >= ' ' && c <= '~')
						{
							inputbuf[input_pos] = c;
							input_pos++;
							inputbuf[input_pos] ='\0';
						}
				}
				cleardevice();
				rectangle(250,220,400,240);
				outtextxy(200,200,"ENTER PASSWORD");
				rectangle(250,250,400,270);
				outtextxy(255,225,un);
				outtextxy(150,225,"USERNAME:");
				outtextxy(150,255,"PASSWORD:");
				rectangle(230,290,280,310);
				outtextxy(235,295,"LOGIN");
				outtextxy(350,290,"new_user?");
				if(input_pos>12)
				{
					for(i=0;i<12;i++)
					showtext[11-i]='*';
					showtext[12]='\0';
				}
				else
				{
					for(i=0;i<input_pos;i++)
					showtext[i]='*';
					showtext[i]='\0';
				}
				outtextxy (255,255, showtext);

			}while(!the_end);
			the_end=0;
			strcpy(password,inputbuf);
			l=strlen(inputbuf);
			for(i=0;i<l;i++)
			inputbuf[i]='\0';
			for(i=0;i<strlen(password);i++)
			pw[i]='*';
			pw[i]='\0';
			detect_mouse ();
			showmouse_text ();
			showmouse_graphics();
			button=0;
			for(i=0;i<12;i++)
			showtext[i]='\0';
			input_pos=0;
		}
		if((x>230)&&(x<280)&&(y>290)&&(y<310)&&(button==1))
		{
			hide_mouse();
			mclick=1;
			button=0;
			valid=checkunpw(username,password);
			if(!valid)
			{
				cleardevice();
				settextstyle(1,0,4);
				outtextxy(200,200,"invalid");
				delay(2000);
				 mclick=0;
				 graphdefaults();
				 cleardevice();

				 rectangle(250,220,400,240);
				 outtextxy(200,200,"ENTER PASSWORD");
				 rectangle(250,250,400,270);
				 outtextxy(150,225,"USERNAME:");
				 outtextxy(150,255,"PASSWORD:");
				 rectangle(230,290,280,310);
				 outtextxy(235,295,"LOGIN");
				 outtextxy(350,290,"new_user?");
			}
		}
		if((x>350)&&(x<430)&&(y>290)&&(y<300)&&(button==1))
		{
			newuser();
			mclick=1;
		}
	}
	hide_mouse();
	inputbuf[0]='\0';
	clrscr();
	cleardevice();

	delay(1000);

	return valid;
4p}
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

struct time t;
void display(int,int,int);
void main()
{
    int i=0,gd=DETECT,gm,hr,min,sec;
    clrscr();
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    setcolor(RED);
    settextstyle(8,0,6);

    while(!kbhit())
    {
       gettime(&t);
       hr=t.ti_hour;
       min=t.ti_min;
       sec=t.ti_sec;
       i++;

       display(100,100,hr);
       display(200,100,min);
       display(300,100,sec);
	      sound(400);
       delay(30);
       nosound();
       delay(930);
       cleardevice();
    }
    getch();
}
void display(int x,int y,int num)
{

     char str[3];
     itoa(num,str,10);

     settextstyle(4,0,6);

     outtextxy(180,100,":");
     outtextxy(280,100,":");
     outtextxy(x,y,str);

     rectangle(90,90,380,200);
     rectangle(70,70,400,220);
     setfillstyle(SOLID_FILL,RED);
     floodfill(71,72,RED);

     outtextxy(90,250,"Digital Clock");
     line(83,265,83,310);
     line(380,265,380,310);
     line(78,272,78,303);
     line(385,272,385,303);
}

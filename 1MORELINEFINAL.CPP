#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
int z,r1,score=0,x2,y2;
double x1,y1,b=0;
static double u=0.016;
int w=3;
//GIVING COORDINATES IN TERMS OF GETMAXX AND GETMAXY AND Z ETC FOR THE GAME
//TO WORK IN ALL RESOLUTIONS
void background()
{//F1
//DRAWING THE 4 BACKGROUND LINES
if(getmaxx()<getmaxy())
{
setcolor(w);
line(0,0,getmaxx(),0);
line(0,0,0,getmaxx());
line(0,getmaxx(),getmaxx(),getmaxx());
line(getmaxx(),0,getmaxx(),getmaxx());
// THE 4 CIRCLES
circle(x1,0,r1);
circle(x1,z/2,r1);
circle(x1,z/4,r1);
circle(x1,3*z/4,r1);
circle(x1,z,r1);
//TIME FUNCTION AND SCORE
cout<<"TIME"<<'\t'<<clock()/CLK_TCK<<endl;
cout<<"SCORE"<<'\t'<<score;
}//IF
else
{
setcolor(w);
line(0,0,getmaxy(),0);
line(0,0,0,getmaxy());
line(0,getmaxy(),getmaxy(),getmaxy());
line(getmaxy(),0,getmaxy(),getmaxy());
// THE 4 CIRCLES
circle(x1,0,r1);
circle(x1,z/2,r1);
circle(x1,z/4,r1);
circle(x1,3*z/4,r1);
circle(x1,z,r1);
//TIME FUNCTION AND SCORE
cout<<"TIME"<<'\t'<<clock()/CLK_TCK<<endl;
cout<<"SCORE"<<'\t'<<score;
}//ELSE
return;
}//FUNCTION END(F1)
void main()
{
clrscr();
//INITIALISING GRAPHICS DRIVER
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C:/TURBOC3/BGI");
//CREATING A SQUARE BOARD
if(getmaxx()<getmaxy())
::z=getmaxx();
else
::z=getmaxy();
char c='1';
//CREATING 3 CASES FOR THE THREE CIRCLES
batman1:
switch(c)
{
case '1'://MIDDLE CIRCLE
{
cin.ignore();//CLEARING THE INPUT BUFFER FOR NEXT TURN FOR USING KBHIT
x1=z/2,y1=z/2,r1=20;
while(w!=1)
{
w--;//w VARIABLE FOR RANDOMLY ASSINING COLOURS WHILE TRAVELLING FROM EACH
//CIRCLE
if(w==2)
w=7;
background();
double t1,s;
//INFINITE LOOP TILL GOING TO NEXT CIRCLE OR GAME OVER
while(1)
{
for(double t=0;t<2*M_PI;t+=u)
{
x2=r1*cos(t)+x1;
y2=r1*sin(t)+y1;
circle(x2,y2,2);
line(x1,y1,x2,y2);
//FOR THE MOVING SMALL CIRCLE IN THE CIRCLE BY USING EQUATION OF CIRCLE
delay(6);
clrscr();
cleardevice();
background();
//MAKING IT GO IN CIRCLE TILL INPUT GOT BY KBHIT FUNCTION
if(kbhit())
{
//FUNCTIONS FOR MAKING THE BALL GO TANGENTIALLY
if(x2<=x1-15 && y2<=y1)
//THE CORRECT POSITION WHICH GOES TO THE  NEXT RING
{t1=0;s=-1;
while(x2<=::z+100 || y2<=::z+100)//FOR MAKING IT GO INDEFINATELY TILL GAME
{                                //OVER OR NEXT RING
circle(x2+=t1,y2+=s,2);
delay(6);
clrscr();
cleardevice();
background();
if(x2>=::z || y2>=::z || x2<=0 || y2<=z/4)
{
score++;
u+=0.002;//FOR INCREASING SPEED
c='2';//GOING TO THE NEXT CIRCLE BY GOTO FUNCTION AND NEXT CASE
goto batman1;
}
}
}
//ALL THE FOUR REMAINING IFS AND ELSE FOR BALL TO GO TANGENTIALLY AND EXIT
//IF EXIT ENCOUNTERED
else if(x2<=x1 && y2<=y1)
{t1=1;s=-1;
while(x2<=::z+100 || y2<=::z+100)
{
circle(x2+=t1,y2+=s,2);
delay(6);
clrscr();
cleardevice();
background();
if(x2>=::z || y2>=::z || x2<=0 || y2<=0)
{
cout<<endl<<"GAME OVER";delay(6000);
getch();
exit(0);
}
}
}
if(x2>=x1 && y2>=y1)
{t1=-1;s=1;
while(x2<=::z+100 || y2<=::z+100)
{
circle(x2+=t1,y2+=s,2);
delay(6);
clrscr();
cleardevice();
background();
if(x2>=::z || y2>=::z || x2<=0 || y2<=0)
{
cout<<endl<<"GAME OVER";delay(6000);
getch();
exit(0);
}
}
}
if(x2>=x1 && y2<=y1)
{t1=1;s=1;
while(x2<=::z+100 || y2<=::z+100)
{
circle(x2+=t1,y2+=s,2);
delay(6);
clrscr();
cleardevice();
background();
if(x2>=::z || y2>=::z || x2<=0 || y2<=0)
{
cout<<endl<<"GAME OVER";delay(6000);
getch();
exit(0);
}
}
}
if(x2<=x1 && y2>=y1)
{t1=-1;s=-1;
while(x2<=::z+100 || y2<=::z+100)
{
circle(x2+=t1,y2+=s,2);
delay(6);
clrscr();
cleardevice();
background();
if(x2>=::z || y2>=::z || x2<=0 || y2<=0)
{
cout<<endl<<"GAME OVER";delay(6000);
getch();
exit(0);
}
}
}
}
else
continue;//CONTINUING THE LOOP FOR THE BALL TO KEEP MOVING
}
}
}
}//CASE 1
break;
case '2': //CIRCLE 1 UPPER CIRCLE
{
//REMAINING LOGIC SAME AS BEFORE CASE BY ONLY CHANGING COORDINATE OF X1=Z/4
cin.ignore();
x1=z/2,y1=z/4,r1=20;
circle(x1,y1,r1);
background();
while(w!=1)
{
w--;

if(w==2)
w=9;
double t1,s;
while(1)
{
for(double t=0;t<2*M_PI;t+=u)
{
x2=r1*cos(t)+x1;
y2=r1*sin(t)+y1;
circle(x2,y2,2);
line(x1,y1,x2,y2);
delay(6);
clrscr();
cleardevice();
background();
if(kbhit())
{
if(x2<=x1-15 && y2<=y1)
{t1=0;s=-1;
while(x2<=::z+100 || y2<=::z+100)
{
circle(x2+=t1,y2+=s,2);
delay(6);
clrscr();
cleardevice();
background();
if(x2>=::z || y2>=::z || x2<=0 || y2<=0)
{
score++;
c='3';
u+=0.002;//FOR INCREASING SPEED
goto batman1;
}
}
}
else if(x2<=x1 && y2<=y1)
{t1=1;s=-1;
while(x2<=::z+100 || y2<=::z+100)
{
circle(x2+=t1,y2+=s,2);
delay(6);
clrscr();
cleardevice();
background();
if(x2>=::z || y2>=::z || x2<=0 || y2<=0)
{
cout<<endl<<"GAME OVER";delay(6000);
getch();
exit(0);
}
}
}
if(x2>=x1 && y2>=y1)
{t1=-1;s=1;
while(x2<=::z+100 || y2<=::z+100)
{
circle(x2+=t1,y2+=s,2);
delay(6);
clrscr();
cleardevice();
background();
if(x2>=::z || y2>=::z || x2<=0 || y2<=0)
{
cout<<endl<<"GAME OVER";delay(6000);
getch();
exit(0);
}
}
}
if(x2>=x1 && y2<=y1)
{t1=1;s=1;
while(x2<=::z+100 || y2<=::z+100)
{
circle(x2+=t1,y2+=s,2);
delay(6);
clrscr();
cleardevice();
background();
if(x2>=::z || y2>=::z || x2<=0 || y2<=0)
{
cout<<endl<<"GAME OVER";delay(6000);
getch();
exit(0);
}
}
}
if(x2<=x1 && y2>=y1)
{t1=-1;s=-1;
while(x2<=::z+100 || y2<=::z+100)
{
circle(x2+=t1,y2+=s,2);
delay(6);
clrscr();
cleardevice();
background();
if(x2>=::z || y2>=::z || x2<=0 || y2<=0)
{
cout<<endl<<"GAME OVER";delay(6000);
getch();
exit(0);
}
}
}
}
else
continue;
}
}
}
}//CASE 2
break;
case '3'://CIRCLE 3 LOWER CIRCLE
{
cin.ignore();
//JUST CHANGING COORDINATES TO X/2 REMAINING LOGIC SAME
x1=z/2,y1=3*z/4,r1=20;
circle(x1,y1,r1);
background();
while(w!=1)
{
w--;

if(w==2)
w=9;
double t1,s;
while(1)
{
for(double t=0;t<2*M_PI;t+=u)
{
x2=r1*cos(t)+x1;
y2=r1*sin(t)+y1;
circle(x2,y2,2);
line(x1,y1,x2,y2);
delay(6);
clrscr();
cleardevice();
background();
if(kbhit())
{
if(x2<=x1-15 && y2<=y1)
{t1=0;s=-1;
while(x2<=::z+100 || y2<=::z+100)
{
circle(x2+=t1,y2+=s,2);
delay(6);
clrscr();
cleardevice();
background();
if(x2>=::z || y2>=::z || x2<=0 || y2<=z/2)
{
score++;
c='1';
u+=0.002;
goto batman1;
}
}
}
else if(x2<=x1 && y2<=y1)
{t1=1;s=-1;
while(x2<=::z+100 || y2<=::z+100)
{
circle(x2+=t1,y2+=s,2);
delay(6);
clrscr();
cleardevice();
background();
if(x2>=::z || y2>=::z || x2<=0 || y2<=0)
{
cout<<endl<<"GAME OVER";delay(6000);
getch();
exit(0);
}
}
}
if(x2>=x1 && y2>=y1)
{t1=-1;s=1;
while(x2<=::z+100 || y2<=::z+100)
{
circle(x2+=t1,y2+=s,2);
delay(6);
clrscr();
cleardevice();
background();
if(x2>=::z || y2>=::z || x2<=0 || y2<=0)
{
cout<<endl<<"GAME OVER";delay(6000);
getch();
exit(0);
}
}
}
if(x2>=x1 && y2<=y1)
{t1=1;s=1;
while(x2<=::z+100 || y2<=::z+100)
{
circle(x2+=t1,y2+=s,2);
delay(6);
clrscr();
cleardevice();
background();
if(x2>=::z || y2>=::z || x2<=0 || y2<=0)
{
cout<<endl<<"GAME OVER";delay(6000);
getch();
exit(0);
}
}
}
if(x2<=x1 && y2>=y1)
{t1=-1;s=-1;
while(x2<=::z+100 || y2<=::z+100)
{
circle(x2+=t1,y2+=s,2);
delay(6);
clrscr();
cleardevice();
background();
if(x2>=::z || y2>=::z || x2<=0 || y2<=0)
{
cout<<endl<<"GAME OVER";delay(6000);
getch();
exit(0);
}
}
}
}
else
continue;
}
}
}
}//CASE 3
break;
}//SWITCH
getch();
}

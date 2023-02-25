#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
float f(int x);

void main()
{
int x,y;
int a=4;
int gdriver = DETECT, gmode, errorcode;

initgraph(&gdriver, &gmode, “”);

line(300,300,300,50);
line(300+200,175,100,175);
putpixel(300,175,GREEN);

for(x=0;x<1000;x++)
{
y=f(x);
putpixel(x+300, 175-y,GREEN);
putpixel(x+300, 175+y,GREEN);
}

getch();
closegraph();
}

float f(int x)
{
return 2*sqrt(4*x);
}

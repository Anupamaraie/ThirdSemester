#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void ellipseMIdpoint(float,float,float,float);
void drawEllipse(float,float,float,float);

int main()
{

    float xc,yc,rx,ry;
    int gd= DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    printf("Enter the center coordinates of ellipse: ");
    scanf("%f%f",&xc,&yc);
    printf("Enter x-radius coordinates: ");
    scanf("%f",&rx);
    printf("Enter y-radius coordinates: ");
    scanf("%f",&ry);
    ellipseMIdpoint(xc,yc,rx,ry);
    getch();
}
void ellipseMIdpoint(float xc, float yc, float rx, float ry)
{
    float rxsq = rx*rx;
    float rysq = ry*ry;
    float x=0, y=ry,p;
    float px=0, py=2, yx = rxsq*y;

    drawEllipse(xc,yc,x,y);
    while(px<py)
    {
        x++;
        px = py+2 * rysq;

        if(p<0)
            p=p+rysq+px;
        else
        {
            y--;
            py = py-2*rxsq;
            p=p+rysq+px-py;
        }
        drawEllipse(xc,yc,x,y);
        delay(30);
    }
    p = rysq *(x+0.5) * (x+0.5) + rxsq*(y-1) - rxsq * rysq;

    while(y>0)
    {

        y--;
        py = py-2*rxsq;

        if(p>0)
            p = p+rxsq - py;
        else
        {

            x++;
            px = px+2*rysq;
            p = p+ rxsq - py +px;
        }
        drawEllipse(xc,yx,x,y);
        delay(30);
    }
}
void drawEllipse(float xc, float yc, float x, float y)
{
    putpixel(xc+x,yc+y,WHITE);
    putpixel(xc-x,yc+y,WHITE);
    putpixel(xc+x,yc-y,WHITE);
    putpixel(xc-x,yc-y,WHITE);
}


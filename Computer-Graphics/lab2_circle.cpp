#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

int circleMidpoint(int,int,int);
int drawCircle(int,int,int,int);

int main()
{
    int xc,yc,r;
    int gd= DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    printf("Enter the center coordinates of circle: ");
    scanf("%d%d",&xc,&yc);
    printf("Enter the radius: ");
    scanf("%d",&r);
    circleMidpoint(xc,yc,r);
    getch();
    return 0;
}
int circleMidpoint(int xc, int yc,int r)
    {
        int x=0, y=r;
        int p = 1-r;

        while(x<r)
        {
            drawCircle(xc,yc,x,y);
            x++;
        if(p<0)
            p=p+2*x+1;
        else
        {
            y--;
            p=p+2*(x-y)+1;
        }
        drawCircle(xc,yc,x,y);
        delay(50);
        }
    }

int drawCircle(int xc, int yc, int x, int y)
    {
        putpixel(xc+x,yc+y,RED);
        putpixel(xc-x,yc+y,WHITE);
        putpixel(xc+x,yc-y,GREEN);
        putpixel(xc-x,yc-y,YELLOW);
        putpixel(xc+x,yc+y,RED);
        putpixel(xc-x,yc+y,WHITE);
        putpixel(xc+x,yc-y,GREEN);
        putpixel(xc-x,yc-y,YELLOW);
    }


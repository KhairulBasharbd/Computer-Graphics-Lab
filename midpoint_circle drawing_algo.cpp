#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;


void draw(int a, int b, int x, int y)
{

    putpixel(a+x, b+y, BLUE);
    putpixel(a+x, b-y, BLUE);
    putpixel(a-x, b+y, BLUE);
    putpixel(a-x, b-y, BLUE);
    putpixel(a+y, b+x, BLUE);
    putpixel(a+y, b-x, BLUE);
    putpixel(a-y, b+x, BLUE);
    putpixel(a-y, b-x, BLUE);
}

void mid_point_circle(int x1,int y1,int r){
    int x,p,y;
    x = 0;
    y = r;
    p = 1-r;
    while(x<y){
        draw(x1,y1,x,y);
        x++;
        if(p<0){
            p += 2*x +1;
        }
        else if(p>=0){
            y--;
            p += 2*x - 2*y +1;
        }
        delay(40);
    }


}


int main(){

    initwindow(500,500);
    //int gd,gm;
   //detectgraph(&gd,&gm);
    //initgraph(&gd,&gm,"");

    int x,y,r;
    cin >>x>>y>>r;

    mid_point_circle(x,y,r);

    getch();
}

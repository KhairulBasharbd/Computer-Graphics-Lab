#include<graphics.h>

using namespace std;

int main(){
    int gd,gm;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");

    //drawing trangle
    setcolor(RED);
    line(150,50,50,250);
    line(150,50,250,250);
    line(50,250,250,250);
    setfillstyle(SOLID_FILL,RED);
    floodfill(200,225,RED);

    //drawing circle
    setcolor(GREEN);
    circle(250,250,100);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(260,250,GREEN);

    //drawing rectangle
    setcolor(BLUE);
    rectangle(250,250,550,400);
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(350,350,BLUE);

    getch();
    return 0;
}

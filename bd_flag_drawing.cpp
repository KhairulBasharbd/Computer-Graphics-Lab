#include<graphics.h>
//#include<stdio.h>
//#include<iostream>

using namespace std;

int main(){

    int gd,gm;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");

    setcolor(GREEN);
	rectangle(50,50,220,150);
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(51,51,GREEN);

	setcolor(RED);
	circle(135,100,34);
	setfillstyle(SOLID_FILL,RED);
	floodfill(135,100,RED);      //: This parameter determines the color or pattern used for the fill. It should match the color or pattern set using setfillstyle(). The flood fill algorithm starts from the specified position and fills the enclosed area until it encounters a boundary or reaches a different color.



    getch();
    closegraph();
    return 0;
}

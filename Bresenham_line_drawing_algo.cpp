#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void linedraw(int x1,int y1,int x2,int y2){
    int x,y,p,dx,dy;

    dx = abs(x2-x1);
    dy = abs(y2-y1);
    p = 2*dy - dx;

    x = x1;
    y = y1;

    for(int i=0;i<dx;i++){
        putpixel(x,y,WHITE);
        if(p<0){
            p += 2*dy;
            if(x1>x2) x--;
            else x++;
        }
        else{
            p += 2*dy -2*dx;
            if(x1>x2) x--;
            else x++;

            if(y1<y2) y++;
            else y--;
        }
        delay(50);
    }
}


int main(){
    initwindow(600,600);

    int x1,y1,x2,y2;
    printf("Enter co-ordinates of two points : ");
    cin>>x1>>y1>>x2>>y2;

    linedraw(x1,y1,x2,y2);


    getch();
    closegraph();
}

#include<graphics.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int v;
double ang;
vector <int> x,y;

void drawpoint(){
    if(v == 1){
        putpixel(x[0],y[0],WHITE);

    }
    if(v == 2){
        line(x[0]+200,y[0],x[1]+200,y[1]);

    }
    else{
        for(int i=0;i<v;i++){
            line(x[i],y[i],x[(i+1)%v],y[(i+1)%v]);
        }
    }

}


void rotation(){
    if(v == 1){
        putpixel(x[0]*cos(ang) - y[0]*sin(ang),x[0]*sin(ang) + y[0]*cos(ang) ,YELLOW);

    }
    if(v == 2){
        line(x[0]*cos(ang) - y[0]*sin(ang),x[0]*sin(ang) + y[0]*cos(ang) ,x[1]*cos(ang) - y[1]*sin(ang),x[1]*sin(ang) + y[1]*cos(ang) );
         // shifting 200 pixel to right to see better view;
    }
    else{
        for(int i=0;i<v;i++){
            line(x[i]*cos(ang) - y[i]*sin(ang) + 200 ,x[i]*sin(ang) + y[i]*cos(ang) ,x[(i+1)%v]*cos(ang) - y[(i+1)%v]*sin(ang) + 200,x[(i+1)%v]*sin(ang) + y[(i+1)%v]*cos(ang));
            // shifting 200 pixel to right to see better view;
        }
    }

}


int main(){
    int gd,gm;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");


    int a,b,tht;
    cout<<"Enter the no. of vertex : ";
    cin >>v;

    for(int i=0;i<v;i++){

        cout<<"(x"<<i+1<<","<<"y"<<i+1<<") = ";
        cin >>a>>b;
        x.push_back(a);
        y.push_back(b);
    }

    cout<<"Enter the rotation angle in degree = ";
    cin >>tht;

    ang = tht * 0.017453; //in radian



    setcolor(WHITE);
    drawpoint();
    setcolor(YELLOW);
    rotation();


    getch();
    return 0;
}

/*
3
80 50
30 150
130 150
90
*/


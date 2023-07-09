#include<graphics.h>
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int v,scx,scy;
vector <int> x,y;

void drawpoint(){
    if(v == 1){
        putpixel(x[0],y[0],WHITE);

    }
    if(v == 2){
        line(x[0],y[0],x[1],y[1]);

    }
    else{
        for(int i=0;i<v;i++){
            line(x[i],y[i],x[(i+1)%v],y[(i+1)%v]);
        }
    }

}

void scaling(){
    if(v == 1){
        putpixel(x[0]*scx,y[0]*scy,YELLOW);

    }
    if(v == 2){
        line(x[0]*scx,y[0]*scy,x[1]*scx,y[1]*scy);

    }
    else{
        for(int i=0;i<v;i++){
            line(x[i]*scx,y[i]*scy,x[(i+1)%v]*scx,y[(i+1)%v]*scy);
        }
    }


}


int main(){
    int gd,gm;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");


    int a,b;
    cout<<"Enter the no. of vertex : ";
    cin >>v;

    for(int i=0;i<v;i++){

        cout<<"(x"<<i+1<<","<<"y"<<i+1<<") = ";
        cin >>a>>b;
        x.push_back(a);
        y.push_back(b);
    }

    cout<<"Enter the scaling vector (scx,scy) = ";
    cin >>scx>>scy;

    setcolor(WHITE);
    drawpoint();
    setcolor(YELLOW);
    scaling();

    getch();
    return 0;
}

/*
3
80 50
30 150
130 150
2 2


*/


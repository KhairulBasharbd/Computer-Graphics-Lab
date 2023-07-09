#include<graphics.h>
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int v,shx,shy;
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

void translation(){
    if(v == 1){
        putpixel(x[0]+shx,y[0]+shy,YELLOW);

    }
    if(v == 2){
        line(x[0]+shx,y[0]+shy,x[1]+shx,y[1]+shy);

    }
    else{
        for(int i=0;i<v;i++){
            line(x[i]+shx,y[i]+shy,x[(i+1)%v]+shx,y[(i+1)%v]+shy);
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

    cout<<"Enter the shift vector (shx,shy) = ";
    cin >>shx>>shy;

    setcolor(WHITE);
    drawpoint();
    setcolor(YELLOW);
    translation();

    getch();
    return 0;
}

/*
3
80 50
30 150
130 150
50 100


*/


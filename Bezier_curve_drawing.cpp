#include<graphics.h>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;
int main(){

    int gd,gm;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");


    int x[4],y[4];

    for(int i=0; i<4; i++){
        cin >> x[i]>>y[i];
    }

    double p_x,p_y,t;

    for(t=0; t<=1; t+=0.001){
        p_x = x[0] * pow(1-t,3) + 3 * x[1] * pow(1-t,2) * t   + 3 * x[2] *(1-t) * pow(t,2)  +   x[3] * pow(t,3);
        p_y = y[0] * pow(1-t,3) + 3 * y[1] * pow(1-t,2) * t   + 3 * y[2] *(1-t) * pow(t,2)  +   y[3] * pow(t,3);

        putpixel(p_x,p_y,GREEN);
    }

    getch();
    closegraph();
    return 0;
}


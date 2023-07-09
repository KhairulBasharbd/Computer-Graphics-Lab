#include <graphics.h>

void drawSierpinskiTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int depth) {
    if (depth == 0) {
        // Base case: Draw the triangle
        line(x1, y1, x2, y2);
        line(x2, y2, x3, y3);
        line(x3, y3, x1, y1);
    } else {
        // Recursive case: Divide the triangle into three smaller triangles
        int mid1x = (x1 + x2) / 2;
        int mid1y = (y1 + y2) / 2;
        int mid2x = (x2 + x3) / 2;
        int mid2y = (y2 + y3) / 2;
        int mid3x = (x3 + x1) / 2;
        int mid3y = (y3 + y1) / 2;

        drawSierpinskiTriangle(x1, y1, mid1x, mid1y, mid3x, mid3y, depth - 1);
        drawSierpinskiTriangle(mid1x, mid1y, x2, y2, mid2x, mid2y, depth - 1);
        drawSierpinskiTriangle(mid3x, mid3y, mid2x, mid2y, x3, y3, depth - 1);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 400;
    int x2 = 500, y2 = 400;
    int x3 = 300, y3 = 100;
    int depth = 5;

    drawSierpinskiTriangle(x1, y1, x2, y2, x3, y3, depth);

    getch();
    closegraph();
    return 0;
}

#include <graphics.h>

// Define the region codes for the clipping window
const int INSIDE = 0;  // 0000
const int LEFT = 1;    // 0001
const int RIGHT = 2;   // 0010
const int BOTTOM = 4;  // 0100
const int TOP = 8;     // 1000

// Define the clipping window coordinates
const int X_MIN = 100;
const int Y_MIN = 100;
const int X_MAX = 400;
const int Y_MAX = 300;

// Function to compute the region code of a point
int computeRegionCode(int x, int y) {
    int code = INSIDE;  // Initialize as inside

    if (x < X_MIN)
        code |= LEFT;
    else if (x > X_MAX)
        code |= RIGHT;

    if (y < Y_MIN)
        code |= BOTTOM;
    else if (y > Y_MAX)
        code |= TOP;

    return code;
}

// Function to clip a line segment using the Cohen-Sutherland algorithm
void cohenSutherlandLineClip(int x1, int y1, int x2, int y2) {
    int code1 = computeRegionCode(x1, y1);
    int code2 = computeRegionCode(x2, y2);
    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
            // Both endpoints are inside the clipping window
            accept = true;
            break;
        } else if (code1 & code2) {
            // Both endpoints are outside the same region, line is completely outside
            break;
        } else {
            // Line may intersect the clipping window, perform further clipping
            int codeOut;
            int x, y;

            if (code1 != 0)
                codeOut = code1;
            else
                codeOut = code2;

            if (codeOut & TOP) {
                // Clip against the top edge
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            } else if (codeOut & BOTTOM) {
                // Clip against the bottom edge
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            } else if (codeOut & RIGHT) {
                // Clip against the right edge
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            } else if (codeOut & LEFT) {
                // Clip against the left edge
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }

            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeRegionCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeRegionCode(x2, y2);
            }
        }
    }

    if (accept) {
        // Draw the clipped line
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 50, y1 = 150;
    int x2 = 400, y2 = 50;

    setcolor(YELLOW);
    rectangle(100, 100, 400, 300);
    // Draw the original line in green
    setcolor(GREEN);
    line(x1, y1, x2, y2);

    // Clip the line using the Cohen-Sutherland algorithm
    setcolor(WHITE);
    cohenSutherlandLineClip(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

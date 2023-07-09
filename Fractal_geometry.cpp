#include <graphics.h>

const int MAX_ITERATIONS = 1000;
const double MIN_X = -2.5;
const double MAX_X = 1.0;
const double MIN_Y = -1.0;
const double MAX_Y = 1.0;
const int WIDTH = 800;
const int HEIGHT = 600;

int mandelbrot(double x, double y) {
    double zx = 0.0;
    double zy = 0.0;
    int iteration = 0;

    while (zx * zx + zy * zy < 4.0 && iteration < MAX_ITERATIONS) {
        double xtemp = zx * zx - zy * zy + x;
        zy = 2 * zx * zy + y;
        zx = xtemp;
        iteration++;
    }

    return iteration;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    double dx = (MAX_X - MIN_X) / WIDTH;
    double dy = (MAX_Y - MIN_Y) / HEIGHT;

    for (int px = 0; px < WIDTH; px++) {
        for (int py = 0; py < HEIGHT; py++) {
            double x = MIN_X + px * dx;
            double y = MIN_Y + py * dy;
            int iteration = mandelbrot(x, y);

            // Coloring based on the iteration count
            int color = iteration % 16;
            putpixel(px, py, color);
        }
    }

    getch();
    closegraph();
    return 0;
}


#include <stdio.h>
#include <graphics.h>
#include <math.h> // For abs()

void drawLineBresenham(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    int e2;

    while (1) {
        putpixel(x0, y0, WHITE); // Plot the current pixel

        if (x0 == x1 && y0 == y1) {
            break; // Reached the end point
        }

        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    int x0, y0, x1, y1;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); // Adjust path as needed

//    printf("Enter coordinates of first point (x0 y0): ");
//    scanf("%d %d", &x0, &y0);
//    printf("Enter coordinates of second point (x1 y1): ");
//    scanf("%d %d", &x1, &y1);

    drawLineBresenham(1, 3, 100, 150);

    getch(); // Wait for a key press
    closegraph(); // Close graphics mode

    return 0;
}

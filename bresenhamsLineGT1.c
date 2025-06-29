#include <stdio.h>
#include <graphics.h> // For graphics functions like putpixel, initgraph, closegraph
#include <math.h>   // For abs() function

// Function to draw a line using Bresenham's algorithm
void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1; // Sign for x increment
    int sy = (y1 < y2) ? 1 : -1; // Sign for y increment
    int err;

    // Handle the case where slope is greater than 1 (or less than -1)
    if (dx < dy) {
        // Swap roles of x and y
        err = 2 * dx - dy;
        while (y1 != y2) {
            putpixel(x1, y1, WHITE);
            if (err >= 0) {
                x1 += sx;
                err -= 2 * dy;
            }
            y1 += sy;
            err += 2 * dx;
        }
    } else {
        // Normal case where slope is less than or equal to 1 (or greater than or equal to -1)
        err = 2 * dy - dx;
        while (x1 != x2) {
            putpixel(x1, y1, WHITE);
            if (err >= 0) {
                y1 += sy;
                err -= 2 * dx;
            }
            x1 += sx;
            err += 2 * dy;
        }
    }
    putpixel(x1, y1, WHITE); // Plot the last point
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Adjust path as needed

    printf("Enter coordinates of first point (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter coordinates of second point (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    drawLineBresenham(x1, y1, x2, y2);

    delay(5000); // Wait for 5 seconds
    closegraph();

    return 0;
}

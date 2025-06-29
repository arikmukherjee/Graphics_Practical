#include <stdio.h>
#include <graphics.h> // For graphics functions like putpixel

// Function to draw a line using the Midpoint Line Drawing Algorithm
void drawLineMidpoint(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int d = 2 * dy - dx; // Initial decision parameter
    int x = x1, y = y1;

    // Plot the starting point
    putpixel(x, y, WHITE);

    // Iterate through the x-coordinates
    while (x < x2) {
        x++;
        if (d < 0) {
            d = d + 2 * dy;
        } else {
            y++;
            d = d + 2 * (dy - dx);
        }
        putpixel(x, y, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); // Adjust path as needed

    // Example: Draw a line from (100, 100) to (300, 200)
    drawLineMidpoint(100, 100, 300, 200);

    getch(); // Wait for a key press
    closegraph(); // Close graphics mode
    return 0;
}

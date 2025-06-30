#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int gd = DETECT, gm;
    int x1, y1, z1, x2, y2, z2; // Original coordinates of a cuboid
    float sx, sy, sz;          // Scaling factors

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); // Initialize graphics (path may vary)

    // Define original cuboid (example)
    x1 = 100; y1 = 100; z1 = 50;
    x2 = 200; y2 = 200; z2 = 100;

    // Draw original cuboid (using bar3d for simplicity)
    bar3d(x1, y1, x2, y2, z2 - z1, 1);
    getch();

    // Get scaling factors from user
    printf("Enter scaling factors (Sx Sy Sz): ");
    scanf("%f %f %f", &sx, &sy, &sz);

    // Clear device and draw scaled cuboid
    cleardevice();
    bar3d(x1 * sx, y1 * sy, x2 * sx, y2 * sy, (z2 - z1) * sz, 1);
    getch();

    closegraph();
    return 0;
}

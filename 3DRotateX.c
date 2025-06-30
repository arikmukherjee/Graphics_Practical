#include <stdio.h>
#include <graphics.h>
#include <math.h>

// Function to draw a 3D bar
void draw_bar(int x1, int y1, int x2, int y2, int depth) {
    bar3d(x1, y1, x2, y2, depth, 1);
}

// Function to perform X-axis rotation
void rotate_x(int *x, int *y, int *z, float angle) {
    float radian_angle = angle * M_PI / 180.0; // Convert degrees to radians
    int new_y = (*y) * cos(radian_angle) - (*z) * sin(radian_angle); // Apply rotation formula for y-coordinate
    int new_z = (*y) * sin(radian_angle) + (*z) * cos(radian_angle); // Apply rotation formula for z-coordinate
    *y = new_y; // Update y-coordinate
    *z = new_z; // Update z-coordinate
    // x-coordinate remains unchanged for rotation about the x-axis
}

 int rotated_x1, rotated_y1, rotated_z1; // z1 is 0 for the front face
 int rotated_x2, rotated_y2, rotated_z2; // z2 is depth for the back face

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, depth, angle;
    int midx, midy;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); // Replace with the path to your BGI directory

    // Get screen dimensions
    midx = getmaxx() / 2;
    midy = getmaxy() / 2;

    // Get input from the user
    printf("Enter the coordinates of the 3D bar (top-left x1, y1, bottom-right x2, y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    printf("Enter the depth of the bar: ");
    scanf("%d", &depth);
    printf("Enter the angle of rotation (in degrees) about the x-axis: ");
    scanf("%d", &angle);

    // Draw the original bar
    setcolor(WHITE);
    draw_bar(midx + x1, midy - y1, midx + x2, midy - y2, depth); // Adjust coordinates for center of the screen
    delay(2000); // Wait for a few seconds

    // Clear the screen
    cleardevice();

    // Perform rotation and redraw the bar
    rotated_x1 = x1, rotated_y1 = y1, rotated_z1 = 0; // z1 is 0 for the front face
    rotated_x2 = x2, rotated_y2 = y2, rotated_z2 = depth; // z2 is depth for the back face

    rotate_x(&rotated_x1, &rotated_y1, &rotated_z1, angle); // Rotate top-left point
    rotate_x(&rotated_x2, &rotated_y2, &rotated_z2, angle); // Rotate bottom-right point

    setcolor(RED);
    draw_bar(midx + rotated_x1, midy - rotated_y1, midx + rotated_x2, midy - rotated_y2, depth); // Redraw rotated bar

    // Wait for user input to close the graphics window
    getch();

    // Close graphics mode
    closegraph();

    return 0;
}

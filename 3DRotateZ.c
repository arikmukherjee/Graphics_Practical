#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

#define PI 3.14159265358979323846 // Definition of PI

// Define the vertices of a cube
// You can define other 3D objects here
float vertices[8][3] = {
    {0, 0, 0},
    {100, 0, 0},
    {100, 100, 0},
    {0, 100, 0},
    {0, 0, 100},
    {100, 0, 100},
    {100, 100, 100},
    {0, 100, 100}
};

// Function to draw the cube
void drawCube() {
    // You need to replace this with your actual drawing code
    // using graphics.h functions like line() or bar3d()
    // For a cube, you would draw lines connecting the vertices
    // to form the edges of the cube.
    // Example: Drawing a few edges
    line((int)vertices[0][0], (int)vertices[0][1], (int)vertices[1][0], (int)vertices[1][1]);
    line((int)vertices[1][0], (int)vertices[1][1], (int)vertices[2][0], (int)vertices[2][1]);
    line((int)vertices[2][0], (int)vertices[2][1], (int)vertices[3][0], (int)vertices[3][1]);
    line((int)vertices[3][0], (int)vertices[3][1], (int)vertices[0][0], (int)vertices[0][1]);

    line((int)vertices[4][0], (int)vertices[4][1], (int)vertices[5][0], (int)vertices[5][1]);
    line((int)vertices[5][0], (int)vertices[5][1], (int)vertices[6][0], (int)vertices[6][1]);
    line((int)vertices[6][0], (int)vertices[6][1], (int)vertices[7][0], (int)vertices[7][1]);
    line((int)vertices[7][0], (int)vertices[7][1], (int)vertices[4][0], (int)vertices[4][1]);

    line((int)vertices[0][0], (int)vertices[0][1], (int)vertices[4][0], (int)vertices[4][1]);
    line((int)vertices[1][0], (int)vertices[1][1], (int)vertices[5][0], (int)vertices[5][1]);
    line((int)vertices[2][0], (int)vertices[2][1], (int)vertices[6][0], (int)vertices[6][1]);
    line((int)vertices[3][0], (int)vertices[3][1], (int)vertices[7][0], (int)vertices[7][1]);
}

// Function to perform Z-axis rotation
void rotateZ(float angle_degrees) {
    float angle_radians = angle_degrees * PI / 180.0; // Convert to radians
    float cos_theta = cos(angle_radians);
    float sin_theta = sin(angle_radians);
	int i;
    for (i = 0; i < 8; i++) {
        float x = vertices[i][0];
        float y = vertices[i][1];

        // Apply the Z-axis rotation formulas
        vertices[i][0] = x * cos_theta - y * sin_theta;
        vertices[i][1] = x * sin_theta + y * cos_theta;
    }
}
 float rotationAngle;
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); // Initialize graphics mode
    printf("Enter the rotation angle (degrees): ");
    scanf("%f", &rotationAngle);

    // Set drawing color
    setcolor(WHITE);

    // Initial drawing of the object
    drawCube();

    // Perform rotation
    rotateZ(rotationAngle);

    // Clear previous drawing
    cleardevice();

    // Draw the rotated object
    drawCube();

    getch(); // Wait for a key press
    closegraph(); // Close graphics mode

    return 0;
}


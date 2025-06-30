#include <graphics.h> // For graphics functions like bar3d() and setcolor()
#include <math.h>     // For trigonometric functions like cos() and sin()
#include <stdio.h>    // For input/output functions like printf() and scanf()
#include <conio.h>    // For console input (getch() in some environments)
// Define cube vertices (x, y, z)
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
void rotateY(float angle_degrees) {
    float angle_radians = angle_degrees * M_PI / 180.0; // Convert to radians
    float cos_theta = cos(angle_radians);
    float sin_theta = sin(angle_radians);
	int i;
    for ( i = 0; i < 8; i++) {
        float x = vertices[i][0];
        float z = vertices[i][2];

        // Apply the Y-axis rotation formulas
        vertices[i][0] = x * cos_theta + z * sin_theta;
        vertices[i][2] = z * cos_theta - x * sin_theta;
    }
}
int depth;
int drawCube() {
    // Implement drawing logic using graphics.h or other graphics library
    // For a cube, you would draw lines or use bar3d() to represent the faces
    // Example (using bar3d for a single face):
    bar3d(vertices[0][0], vertices[0][1], vertices[2][0], vertices[2][1], depth, 1);
    // You would need to adapt this for a full cube representation
}
float rotationAngle;
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); // Initialize graphics mode
    setbkcolor(GREEN);
    printf("Enter the rotation angle (degrees): ");
    scanf("%f", &rotationAngle);

    // Initial drawing of the object
    drawCube();

    // Perform rotation
    rotateY(rotationAngle);

    // Clear previous drawing
    cleardevice();

    // Draw the rotated object
    drawCube();

    getch(); // Wait for a key press
    closegraph(); // Close graphics mode

    return 0;
}



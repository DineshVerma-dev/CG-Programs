#include <graphics.h>
#include <conio.h>
#include <math.h>

void rotate(float angle) {
    int x1 = 100, y1 = 100; 
    int x2 = 300, y2 = 300; 

    rectangle(x1, y1, x2, y2);

    float rad = angle * (M_PI / 180.0); 
    float cosTheta = cos(rad);
    float sinTheta = sin(rad);

    int centerX = (x1 + x2) / 2;
    int centerY = (y1 + y2) / 2;

    int newX1 = centerX + (x1 - centerX) * cosTheta - (y1 - centerY) * sinTheta;
    int newY1 = centerY + (x1 - centerX) * sinTheta + (y1 - centerY) * cosTheta;
    int newX2 = centerX + (x2 - centerX) * cosTheta - (y2 - centerY) * sinTheta;
    int newY2 = centerY + (x2 - centerX) * sinTheta + (y2 - centerY) * cosTheta;

    rectangle(newX1, newY1, newX2, newY2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    float angle = 45.0; 

    rotate(angle);

    getch();
    closegraph();
    return 0;
}

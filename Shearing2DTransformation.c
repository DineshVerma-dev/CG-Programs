#include <graphics.h>
#include <conio.h>
#include <math.h>

void shear(float shx, float shy) {
    int x1 = 100, y1 = 100;
    int x2 = 300, y2 = 300;

    rectangle(x1, y1, x2, y2);

    int shearedX1 = x1 + shx * y1;
    int shearedY1 = y1 + shy * x1;
    int shearedX2 = x2 + shx * y2;
    int shearedY2 = y2 + shy * x2;

    rectangle(shearedX1, shearedY1, shearedX2, shearedY2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    float shx = 0.1;
    float shy = 0.0;

    shear(shx, shy);

    getch();
    closegraph();
    return 0;
}

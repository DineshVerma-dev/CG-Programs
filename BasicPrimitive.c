#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    int poly[10];

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    circle(300, 200, 50);
    bar(100, 100, 200, 200);
    ellipse(400, 300, 0, 360, 100, 50);
    rectangle(250, 100, 400, 200);
    line(150, 300, 450, 300);

    poly[0] = 200; poly[1] = 350;
    poly[2] = 300; poly[3] = 450;
    poly[4] = 400; poly[5] = 400;
    poly[6] = 350; poly[7] = 300;
    poly[8] = 250; poly[9] = 300;
    
    drawpoly(5, poly);

    getch();
    closegraph();
    return 0;
}

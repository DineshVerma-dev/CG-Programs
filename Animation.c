#include <graphics.h>
#include <conio.h>
#include <dos.h>

void drawBall(int x, int y, int radius) {
    setcolor(RED);
    circle(x, y, radius);
    floodfill(x, y, RED);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int x = 300, y = 200;
    int radius = 20;
    int xSpeed = 5;
    int ySpeed = 4;

    while (!kbhit()) {
        cleardevice();
        drawBall(x, y, radius);

        x += xSpeed;
        y += ySpeed;

        if (x + radius >= getmaxx() || x - radius <= 0) {
            xSpeed = -xSpeed;
        }
        if (y + radius >= getmaxy() || y - radius <= 0) {
            ySpeed = -ySpeed;
        }

        delay(30);
    }

    closegraph();
    return 0;
}

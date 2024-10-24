#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void Bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int e2; // Removed err variable

    while (x1 != x2 || y1 != y2) {
        putpixel(x1, y1, WHITE);
        e2 = 2 * (dx - dy); // Recalculating error based on dx and dy

        if (e2 > -dy) {
            dx -= dy;
            x1 += sx;
        }
        
        if (e2 < dx) {
            dy += dx;
            y1 += sy;
        }
    }
    
    putpixel(x2, y2, WHITE);
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    Bresenham(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

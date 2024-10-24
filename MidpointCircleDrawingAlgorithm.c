#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void main() {
    int x, y, x_mid, y_mid, radius, dp;
    int g_mode, g_driver = DETECT;

    clrscr();
    initgraph(&g_driver, &g_mode, "C:\\Turboc3\\BGI");
    printf("MIDPOINT Circle Drawing Algorithm \n ");
   printf("Enter the coordinates of the center: ");
    scanf("%d %d", &x_mid, &y_mid);
    printf("Enter the radius: ");
    scanf("%d", &radius);

    x = 0;
    y = radius;
    dp = 1 - radius;

    do {
        putpixel(x_mid + x, y_mid + y, YELLOW);
        putpixel(x_mid + y, y_mid + x, YELLOW);
        putpixel(x_mid - y, y_mid + x, YELLOW);
        putpixel(x_mid - x, y_mid + y, YELLOW);
        putpixel(x_mid - x, y_mid - y, YELLOW);
        putpixel(x_mid - y, y_mid - x, YELLOW);
        putpixel(x_mid + y, y_mid - x, YELLOW);
        putpixel(x_mid + x, y_mid - y, YELLOW);
        
        if (dp < 0) {
            dp += (2 * x) + 1;
        } else {
            y--;
            dp += (2 * x) - (2 * y) + 1;
        }
        x++;
    } while (y > x);

    getch();
    closegraph();
}
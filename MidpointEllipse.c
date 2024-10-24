#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void MidpointEllipse(int centerX, int centerY, int radiusX, int radiusY) {
    int x = 0, y = radiusY;
    int d1 = (radiusY * radiusY) - (radiusX * radiusX * radiusY) + (0.25 * radiusX * radiusX);
    int d2 = (radiusX * radiusX) * (y - 0.5) * (y - 0.5) + (radiusY * radiusY) * (x + 1) * (x + 1) - (radiusX * radiusX * radiusY * radiusY);

    // Region 1
    while ((radiusY * radiusY * x) < (radiusX * radiusX * y)) {
        putpixel(centerX + x, centerY + y, WHITE);
        putpixel(centerX - x, centerY + y, WHITE);
        putpixel(centerX + x, centerY - y, WHITE);
        putpixel(centerX - x, centerY - y, WHITE);
        
        if (d1 < 0) {
            d1 += (2 * radiusY * radiusY * x) + (radiusY * radiusY);
        } else {
            d1 += (2 * radiusY * radiusY * x) - (2 * radiusX * radiusX * y) + (radiusY * radiusY);
            y--;
        }
        x++;
    }

    // Region 2
    while (y >= 0) {
        putpixel(centerX + x, centerY + y, WHITE);
        putpixel(centerX - x, centerY + y, WHITE);
        putpixel(centerX + x, centerY - y, WHITE);
        putpixel(centerX - x, centerY - y, WHITE);
        
        if (d2 > 0) {
            d2 -= (2 * radiusX * radiusX * y) + (radiusX * radiusX);
        } else {
            d2 += (2 * radiusY * radiusY * x) - (2 * radiusX * radiusX * y) + (radiusX * radiusX);
            x++;
        }
        y--;
    }
}

int main() {
    int gd = DETECT, gm;
    int centerX, centerY, radiusX, radiusY;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter the center coordinates (centerX, centerY): ");
    scanf("%d %d", &centerX, &centerY);
    printf("Enter the lengths of the semi-major and semi-minor axes (radiusX, radiusY): ");
    scanf("%d %d", &radiusX, &radiusY);

    MidpointEllipse(centerX, centerY, radiusX, radiusY);

    getch();
    closegraph();
    return 0;
}

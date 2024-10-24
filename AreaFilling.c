#include <graphics.h>
#include <conio.h>

void floodFill(int x, int y, int fillColor, int boundaryColor) {
    int currentColor = getpixel(x, y);
    
    if (currentColor != boundaryColor && currentColor != fillColor) {
        putpixel(x, y, fillColor);
        floodFill(x + 1, y, fillColor, boundaryColor); 
        floodFill(x - 1, y, fillColor, boundaryColor); 
        floodFill(x, y + 1, fillColor, boundaryColor); 
        floodFill(x, y - 1, fillColor, boundaryColor); 
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    
    rectangle(100, 100, 300, 300); 
    
    floodFill(150, 150, RED, WHITE); 
    
    getch();
    closegraph();
    return 0;
}

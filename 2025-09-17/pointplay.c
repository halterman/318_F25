#include <stdio.h>

typedef struct {
    double x;
    double y;
} Point;


Point midpoint(Point p1, Point p2) {
    double mx = (p1.x + p2.x)/2;
    double my = (p1.y + p2.y)/2;
    Point mid;
    mid.x = mx;
    mid.y = my;
    return mid;
}

int main() {
    Point p1, p2 = {10.5, 3.77};
    p1.x = 3.5;
    p1.y = 0.3;
    printf("(%.2lf, %.2lf)\n", p1.x, p1.y);
    Point mid = midpoint(p1, p2);
    printf("(%.2lf, %.2lf)\n", mid.x, mid.y);


}

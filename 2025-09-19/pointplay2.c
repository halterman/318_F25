#include <stdio.h>

struct point {
    double x;
    double y;
};


struct point midpoint(struct point p1, struct point p2) {
    double mx = (p1.x + p2.x)/2;
    double my = (p1.y + p2.y)/2;
    struct point mid;
    mid.x = mx;
    mid.y = my;
    return mid;
}

int main() {
    struct point p1, p2 = {10.5, 3.77};
    p1.x = 3.5;
    p1.y = 0.3;
    printf("(%.2lf, %.2lf)\n", p1.x, p1.y);
    struct point mid = midpoint(p1, p2);
    printf("(%.2lf, %.2lf)\n", mid.x, mid.y);


}

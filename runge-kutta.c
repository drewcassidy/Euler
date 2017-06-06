#include <stdio.h>

#define STEPCOUNT 10
#define STEPSIZE 0.1
#define STARTY 1
#define STARTX 0

float f(float x, float y);

int main() {
    float y = STARTY;
    float x = STARTX;

    for (int i = 1; i <= STEPCOUNT; i++) {

        float k1 = STEPSIZE * f(x, y);
        float k2 = STEPSIZE * f(x + STEPSIZE / 2, y + k1 / 2);
        float k3 = STEPSIZE * f(x + STEPSIZE / 2, y + k2 / 2);
        float k4 = STEPSIZE * f(x + STEPSIZE, y + k3);

        x += STEPSIZE;
        y += (k1 + (2 * k2) + (2 * k3) + k4) / 6;

        printf("n=%d: x=%2.3f y=%2.3f\n", i, x, y);
    }
}

// y' = xy
float f(float x, float y) {
    return x * y;
}

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

        float predictor = y + (STEPSIZE * f(x, y));

        float k1 = f(x, y);
        float k2 = f(x + STEPSIZE, predictor);

        x += STEPSIZE;
        y += STEPSIZE * 0.5 * (k1 + k2);

        printf("n=%d: x=%2.3f y=%2.3f\n", i, x, y);
    }
}

// y' = xy
float f(float x, float y) {
    return x * y;
}

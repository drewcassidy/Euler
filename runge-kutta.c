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

        float val1 = STEPSIZE * f(x, y);
        float val2 = STEPSIZE * f(x + STEPSIZE / 2, y + val1 / 2);
        float val3 = STEPSIZE * f(x + STEPSIZE / 2, y + val2 / 2);
        float val4 = STEPSIZE * f(x + STEPSIZE, y + val3);

        x += STEPSIZE;
        y += (1.0 / 6.0) * (val1 + 2 * val2 + 2 * val3 + val4);

        printf("n=%d: y(%2f) = %2f\n", i, x, y);
    }
}

// y' = xy
float f(float x, float y) {
    return x * y;
}

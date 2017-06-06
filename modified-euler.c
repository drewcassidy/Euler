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

        float lastx = x;


        float predictor = y + (STEPSIZE * f(lastx, y));

        x += STEPSIZE;
        y += STEPSIZE * 0.5 * (f(lastx, y) + f(x, predictor));
        printf("n=%d: y(%2f) = %2f\n", i, x, y);
    }
}

// y' = xy
float f(float x, float y) {
    return x * y;
}

#include <stdio.h>

#define STEPCOUNT 10
#define STEPSIZE 0.1
#define STARTY 1
#define STARTX 0

float func(float x, float y);

int main() {
    float y = STARTY;
    float x = STARTX;

    for (int i = 1; i <= STEPCOUNT; i++) {
        float lastx = x;
        x += STEPSIZE;

        float predictor = y + (STEPSIZE * func(lastx, y));
        y += STEPSIZE * 0.5 * (func(lastx, y) + func(x, predictor));
        printf("n=%d: y(%2f) = %2f\n",i, x, y);
    }
}

float func(float x, float y) {
    return x * y;
}

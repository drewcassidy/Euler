#include <stdio.h>
#include <math.h>

#define STEPCOUNT 10
#define STEPSIZE 0.1
#define STARTZ 0 //== y'
#define STARTY 0
#define STARTX 0

float f(float x, float y, float z);

int main() {
    float y = STARTY;
    float x = STARTX;
    float z = STARTZ;

    for (int i = 1; i <= STEPCOUNT; i++) {



        float ypredictor = y + (STEPSIZE * z);
        float zpredictor = z + (STEPSIZE * f(x, y, z));

        float val1 = f(x, y, z);
        float val2 = f(x + STEPSIZE, ypredictor, zpredictor);

        x += STEPSIZE;
        y += STEPSIZE * 0.5 * (z + zpredictor);
        z += STEPSIZE * 0.5 * (val1 + val2);

        printf("n=%d: y(%2f) = %2f\n",i, x, y);
    }
}

float f(float x, float y, float z) {
    return cos(x) - sin(z) - (x * x * y);
}

float g(float x, float y, float z) {
    return z;
}

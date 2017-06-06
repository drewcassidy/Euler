#include <stdio.h>
#include <math.h>

#define STEPCOUNT 10
#define STEPSIZE 0.1
#define STARTZ 0 //== y'
#define STARTY 0
#define STARTX 0

float f(float x, float y, float z);
float g(float x, float y, float z);

int main() {
    float y = STARTY;
    float x = STARTX;
    float z = STARTZ;

    for (int i = 1; i <= STEPCOUNT; i++) {

        float ypredictor = y + (STEPSIZE * f(x, y, z));
        float zpredictor = z + (STEPSIZE * g(x, y, z));

        float k1 = f(x, y, z);
        float k2 = f(x + STEPSIZE, ypredictor, zpredictor);

        float l1 = g(x, y, z);
        float l2 = g(x + STEPSIZE, ypredictor, zpredictor);

        x += STEPSIZE;
        y += STEPSIZE * 0.5 * (k1 + k2);
        z += STEPSIZE * 0.5 * (l1 + l2);

        printf("n=%d: y(%2f) = %2f\n", i, x, y);
    }
}

// y" + sin(x)y' + x²y = cos(x)
float f(float x, float y, float z) {
    return cos(x) - sin(z) - (x * x * y);
}

float g(float x, float y, float z) {
    return z;
}

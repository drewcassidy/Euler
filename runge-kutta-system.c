#include <stdio.h>
#include <math.h>

#define STEPCOUNT 10
#define STEPSIZE 0.1
#define STARTZ 0 //== y'
#define STARTY 0
#define STARTX 0

float f(float x, float y, float z); // dy/dx
float g(float x, float y, float z); // dz/dx

int main() {
    float y = STARTY;
    float x = STARTX;
    float z = STARTZ;

    for (int i = 1; i <= STEPCOUNT; i++) {

        float k1 = STEPSIZE * f(x, y, z);
        float l1 = STEPSIZE * g(x, y, z);
        float k2 = STEPSIZE * f(x + STEPSIZE / 2, y + k1 / 2, z + l1 / 2);
        float l2 = STEPSIZE * g(x + STEPSIZE / 2, y + k1 / 2, z + l1 / 2);
        float k3 = STEPSIZE * f(x + STEPSIZE / 2, y + k2 / 2, z + l2 / 2);
        float l3 = STEPSIZE * g(x + STEPSIZE / 2, y + k2 / 2, z + l2 / 2);
        float k4 = STEPSIZE * f(x + STEPSIZE, y + k3, z + l3);
        float l4 = STEPSIZE * g(x + STEPSIZE, y + k3, z + l3);

        x += STEPSIZE;
        y += (1.0 / 6.0) * (k1 + k2*2 + k3*2 + k4);
        z += (1.0 / 6.0) * (l1 + l2*2 + l3*2 + l4);

        printf("n=%2d: x=%2.3f y=%2.3f z=%2.3f\n",i, x, y, z);
    }
}

float f(float x, float y, float z) {
    return z;
}

float g(float x, float y, float z) {
    return cos(x) - sin(z) - (x * x * y);
}



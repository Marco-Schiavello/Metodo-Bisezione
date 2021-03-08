#include <stdio.h>
#include <math.h>

float f(float x){ return pow(x,3) + pow(x,2) - (3 * x) - 2; }

int main()
{
    printf("%f",f(3));
}

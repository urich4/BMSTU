#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
    long double x, y, y1, y2;
    puts("Enter x:");
    scanf_s("%Lf", &x);
    y1 = (exp(x) - exp(-x)) / 2;
    y2 = (exp(x) + exp(-x)) / 2;
    y = pow(y2, 2) - pow(y1, 2);
    printf_s("%20.16Lf %20.16Lf %20.16Lf %20.16Lf %20.16Lf", y1, y2, y, fabs(1 - y), fabs(1 - y) / 1);
    return 0;
}
    
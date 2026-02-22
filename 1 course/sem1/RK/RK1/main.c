#include <stdio.h>

int main()
{
    float x[20] = {1, 1}, y[20] = {1, 1};
    for (int i = 2; i < 20; i++){
      x[i] = x[i - 1] + (y[i - 1] / (i * i));
      y[i] = y[i - 1] + (x[i - 1] / i);
  }
    printf("%f %f\n", x[12], y[18]);

    return 0;
}

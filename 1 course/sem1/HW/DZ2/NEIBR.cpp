#include "NEIBR.h"
#include <math.h>
#include <string>
using namespace std;
void NEIBR(float x, float y, float(*f)(float), string &s){
    s = (fabs(y - f(x)) < 0.000001) ? "ПРИНАДЛЕЖИТ": "НЕ ПРИНАДЛЕЖИТ";
}

float f1(float x){
    return x * x - 4;
}

float f2(float x){
    return log(x);
}

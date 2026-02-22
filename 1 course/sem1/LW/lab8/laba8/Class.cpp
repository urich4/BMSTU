#include <iostream>
#include <string.h>
#include "Class.h"

using namespace std;
Round::Round(float d){
    diam = d;
}

void Round::show1(){
    cout << "Диаметр:" << diam;
}

double Round::square(){
    return 3.14 * (diam / 2) * (diam / 2);
}

Skillet::Skillet(float d, string m) : public Round{
    diam = d;
    material = m;
}

void Skillet::show2(){
    cout << "Материал:" << material;
    cout << "Диаметр:" << diam;
}

int Skillet::number_kotlet(float square_k){
    return (int)(square(diam) / square_k);
}

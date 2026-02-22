#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
    long double x, e = 0.00001;
    cout << "Введите x:";
    cin >> x;
    cout << pow(sin(x), 2) + pow(cos(x), 2);
    return 0;
}

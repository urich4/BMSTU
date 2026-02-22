#include <iostream>
#include <string.h>

using namespace std;
class Round{
protected:
    float diam;
public:
    Round(float d){
        diam = d;
    }
    void show(){
        cout << "Диаметр: " << diam << endl;
    }
    double square(){
        return 3.14 * (diam / 2) * (diam / 2);
    }
};


class Skillet : public Round{
private:
    string material;
public:
    Skillet(float d, string m) : Round(d){
        material = m;
    }
    void show(){
        cout << "Материал: " << material << endl;
        cout << "Диаметр: " << diam << endl;
    }
    int number_kotlet(float square_k){
        return (int)(square() / square_k);
    }
};

int main()
{
    Round s1(50);
    Skillet s2(100, "chugun");

    s1.show();
    cout << "Площадь: " << s1.square() << endl;
    puts("--------");
    s2.show();
    cout << "Кол-во котлет: " << s2.number_kotlet(601) << endl;
    cout << "Площадь: " << s2.square() << endl;
    return 0;
}

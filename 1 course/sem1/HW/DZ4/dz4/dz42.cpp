#include <iostream>
#include <string.h>
#include "Class.h"
#include "CLASS.cpp"

using namespace std;

Castle input_castle(){
    int k;
    cout << "Введите кол-во башен в крепости: "; 
    cin >> k;
    char namet[100], namec[100];
    cout << "Введите имя крепости: ";
    cin >> namec;
    float high;
    bool pass;
    Tower castle[k];
    cout << "Введите название, высоту и признак проездной в башне, через пробел:" << endl; 
    for (int i = 0; i < k; i++){
        cin >> namet >> high >> pass;
        castle[i] = Tower(namet, high, pass);
    }
    return Castle(namec, k, castle);
}

int main(){
    Castle C = input_castle();
    C.show_info();
    cout << "Самая высокая башня: " << C.hmax()->get_name() << endl;
    cout << "Количество пропускных пунктов: " << C.pass_tower() << endl;
    return 0;
}

//Эйфелева 330 1
//Останкинская 540.1 1
//Пизанская 55.8 0
//Шуховская 148.3 1
//Галатская 62.5 0
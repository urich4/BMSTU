#include <iostream>
#include <string.h>
#include "Class.h"
#include "CLASS.cpp"

using namespace std;

int main(){
    int k, countpass = 0;
    cout << "Введите кол-во башен в крепости: "; 
    cin >> k;
    char name[100];
    float high;
    bool pass;
    Tower castle[k], hmax;
    cout << "Введите название, высоту и признак проездной в башне, через пробел:" << endl; 
    for (int i = 0; i < k; i++){

        cin >> name >> high >> pass;
        castle[i] = Tower(name, high, pass);
        if (high > hmax.get_high()) hmax = castle[i];
        if (pass) countpass += 1;
    }
    cout << "--------------------------" << endl;
    cout << "Самая высокая башня: " << hmax.get_name() << " " << hmax.get_high() << " метров" << endl;
    cout << "Количество пропускных пунктов: " << countpass << endl;
    cout << "Крепость состоит из башен: ";
    for (int i = 0; i < k; i++){
        cout << castle[i].get_name() << " ";
    }
    return 0;

}

//Эйфелева 330 1
//Останкинская 540.1 1
//Пизанская 55.8 0
//Шуховская 148.3 1
//Галатская 62.5 0
#include <iostream>
#include <string.h>
#include "Class.h"
using namespace std;


Tower::Tower(const char *n ,  float h , bool s){
    strcpy(name, n);
    high = h;
    pass = s;
}
char* Tower::get_name(){
    return name;
}
float Tower::get_high(){
    return high;
}
bool Tower::get_pass(){
    return pass;
}
void Tower::show_info(){
    cout << "Название: " << get_name() << endl;
    cout << "Высота: " << high << endl;
    cout << "Есть проездная: " << (pass ? "да" : "нет") << endl;
}


Castle::Castle() {
    name[0] = '\0';
    len = 0;
    castle= nullptr;
}
Castle::Castle(const char *n, int l, Tower *c){
    strcpy(name, n);
    len = l;
    for (int i = 0; i < len; i++){
        castle[i] = c[i];
    }
}
void Castle::show_info(){
    cout << "Название: " << name << endl;
    cout << "Кол-во башен: " << len << endl;
    cout << "Крепость состоит из башен: ";
    for (int i = 0; i < len; i++){
        cout << (castle+i)->get_name() << " ";
    }
    cout << endl;
}
Tower* Castle::hmax(){
    Tower* max = castle;
    for (int i = 0; i < len; i++){
        if ((castle+i)->get_high() > max->get_high()) max = (i+castle);
    }
    return max;
}
int Castle::pass_tower(){
    int c = 0;
    for (int i = 0; i < len; ++i){
        if (castle[i].get_pass()) c++;
    }
    return c;
}



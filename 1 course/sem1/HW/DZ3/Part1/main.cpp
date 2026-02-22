#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

struct tag{
    char data;
    tag* next;
};

tag* push(tag* top, char data){
    tag *ptr = new tag;

    ptr->data = data;
    ptr->next = top;
    return ptr;
}

void show(tag* top){ф
    tag* ptr = top;
    while (ptr != nullptr) {
        printf("%c ", ptr->data);
        ptr = ptr->next;
    }
}

tag* pop(tag* top){
    tag* ptr = top;
    tag* ptr2 = top;
    while(ptr != nullptr){
        if ((ptr->data) >= 53 && (ptr->data) <= 57){
            if (ptr == top){
                top = ptr->next;
                delete ptr;
                ptr = top;
            }
            else{
                ptr2->next = ptr->next;
                delete ptr;
                ptr = ptr2->next;
            }
        }
        else{
            ptr2 = ptr;
            ptr = ptr->next;
        }
    }
    return top;
}

int main(){
    tag* top = nullptr;
    char n;
    puts("Введите букву или цифру, чтобы закончить введите знак !");
    while (scanf("%c", &n), n != '!'){
        if (n != ' ' && n != 10)
            top = push(top, n);
    }
    puts("-----------------");
    show(top);
    top = pop(top);
    puts("\n-----------------");
    show(top);
    tag* ptr = top;
    while (top != nullptr){
        top = top->next;
        delete ptr;
        ptr = top;
    }

    return 0;
}

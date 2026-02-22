#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct queue{
    char data[100];
    queue* next;
};

queue* push(queue *first, char nel[]){
    queue *ptr_new = new queue;
    strcpy(ptr_new->data, nel);
    ptr_new->next = nullptr;

    if (first == nullptr) 
        first = ptr_new;
    else{
        queue *ptr = first;
        while (ptr->next != nullptr){
            ptr = ptr->next;
        }
        ptr->next = ptr_new;
    }
    return first;
}

void show(queue* first){
    queue* ptr = first;
    while (ptr != nullptr){
        printf("%s ", ptr->data);
        ptr = ptr->next;
    }
}


int main(){
    queue *first = nullptr;
    char c[100];
    while (scanf("%99s", c) == 1 && strcmp(c, "end") != 0){
        first = push(first, c);
    }

    cout << "---------------" << endl;
    show(first);

    

    queue *ptr_new = new queue;
    strcpy(ptr_new->data, "0");
    ptr_new->next = first;
    first = ptr_new;
    cout << endl <<  "---------------" << endl;

    queue *ptrn = first->next, *ptrb = first;

    while (ptrn->next != nullptr){
        ptrn = ptrn->next;
        ptrb = ptrb->next;
    }
    queue *ptr_new1 = new queue;
    ptrb->next = ptr_new1;
    strcpy(ptr_new1->data, "0");
    ptr_new1->next = ptrn;

    show(first);

    while (first != nullptr) {
        queue* temp = first;
        first = first->next;
        delete temp;
    }



    return 0;
}
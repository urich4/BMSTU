#include <string.h>
#include <cstdio>
#include "baseitem.h"
#include "queueexception.h"


template <class type>
struct Node{
    type item;
    Node<type> *next;
    Node<type> *back;
};



template <class type>
class Queue{
    int size;
    Node<type> *first=nullptr;
    Node<type> *last=nullptr;

public:
    Queue(): size(0), first(nullptr) {}
    Queue(Node<type> *item): size(1), first(item) {}
    ~Queue(){
        Node<type> *current = first;
        while (current->next != nullptr) {
            Node<type> *temp = current;
            current = current->next;
            delete temp;
        }
    }

    void addItem(type it){
        if (first == nullptr)
        {
            first = new Node<type>{it, nullptr, nullptr};
            last = first;
            return;
        }
        Node<type> *current = first;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node<type>{it, nullptr, current};
        last = current->next;
        size += 1;
    }

    void delItem(){
        if (isEmpty()) throw QueueEmptyException();
        Node<type> *temp = first->next;
        delete first;
        first = temp;
    }

    bool isEmpty() const{
        if (first == nullptr) return 1;
        return 0;
    }
    void sortStrings();
    Node<type>* getFirst(){
        return first;
    }
};


class SortedQueue: public Queue<std::string>{
public:
    void sortQueue(){
        bool ok = false;
        while (!ok){
            ok = true;
            Node<std::string> *current = getFirst();
            while (current->next != nullptr){
                if (current->item > current->next->item){
                    std::string temp = current->item;
                    current->item = current->next->item;
                    current->next->item = temp;
                    ok = false;
                }
                current = current->next;
            }
        }
    }
};



















#ifndef QUEUE_H
#define QUEUE_H

#include <string.h>
#include <cstdio>
#include "baseitem.h"
#include "queueexception.h"

struct Node{
    BaseItem *item;
    Node *next;
    Node *back;
};


class Queue{
    int size;
    Node *first=nullptr;
    Node *last=nullptr;

public:
    Queue(): size(0), first(nullptr) {}
    Queue(Node *item): size(1), first(item) {}
    ~Queue();
    void addItem(BaseItem *it);
    void delItem();
    bool isEmpty() const;
    void sortStrings();
    Node* getFirst();
};


class SortedQueue: public Queue{
public:
    void sortQueue();
};





#endif // QUEUE_H

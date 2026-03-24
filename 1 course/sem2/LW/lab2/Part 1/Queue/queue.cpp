#include "queue.h"

void Queue::addItem(BaseItem *it){
    if (first == nullptr)
    {
        first = new Node{it, nullptr, nullptr};
        last = first;
        return;
    }
    Node *current = first;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = new Node{it, nullptr, current};
    last = current->next;
    size += 1;
}

bool Queue::isEmpty() const{
    if (first == nullptr) return 1;
    return 0;
}

void Queue::delItem(){
    if (isEmpty()) throw QueueEmptyException();
    Node *temp = first->next;
    delete first;
    first = temp;
}
Node* Queue::getFirst(){
    return first;
}

Queue::~Queue(){
    Node *current = first;
    while (current->next != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
}

void SortedQueue::sortQueue(){
    bool ok = false;
    while (!ok){
        ok = true;
        Node *current = getFirst();
        while (current->next != nullptr){
            if (current->item->toString() > current->next->item->toString()){
                BaseItem *temp = current->item;
                current->item = current->next->item;
                current->next->item = temp;
                ok = false;
            }
            current = current->next;
        }
    }
}







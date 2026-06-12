#ifndef DECK_H
#define DECK_H

#include <string>

using namespace std;


struct Node {
    int value;      
    Node* next;     
    Node(int val) : value(val), next(nullptr) {}
};


struct Deck {
    Node* head;     
    Node* tail;     
    int size;       

    Deck() : head(nullptr), tail(nullptr), size(0) {}
};

#endif 
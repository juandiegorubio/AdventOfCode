#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstddef>


class LinkedList {
    
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int x) : data(x), prev(NULL), next(NULL) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    LinkedList();
    ~LinkedList();
    
    void push_back(int x);
    void insert_sort(int x);
    bool is_ordered();
};


#endif
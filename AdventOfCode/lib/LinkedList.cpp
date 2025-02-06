#include "../include/LinkedList.h"

LinkedList::LinkedList() : head(NULL), tail(NULL), size(0) {}

LinkedList::~LinkedList() {
    Node* n = head;
    while(n != NULL) {
        Node* next = n->next;
        delete n;
        n = next;
    }
}

void LinkedList::push_back(int x) {
    Node* new_element = new Node(x);
    if(size == 0) { head = new_element; tail = new_element; }
    else {
        tail->next = new_element;
        new_element->prev = tail;
    }
    tail = new_element;
    size++;
}

// void LinkedList::print_list() {
//     Node* element = head;
//     while(element != NULL) {
//         cout << element->data << " ";
//         element = element->next;
//     }
//     cout << endl;
// }

void LinkedList::insert_sort(int x) {
    if(size==0) {
        this->push_back(x);
        return;
    }
    
    // Find the two elements before and after x
    Node* n = head;
    while(n->next != NULL && n->data <= x) n = n->next;
    Node* element_before = n->data <= x ? n : n->prev;
    Node* element_after = n->data <= x ? n->next : n;

    // Update pointers to the new element
    Node* new_element = new Node(x);
    new_element->prev = element_before;
    new_element->next = element_after;
    if(element_before != NULL) element_before->next = new_element;
    if(element_after != NULL) element_after->prev = new_element;

    if(head->prev != NULL) head = head->prev;
    if(tail->next != NULL) tail = tail->next;
    size++;
}

bool LinkedList::is_ordered() {
    if (size < 2) return true;
    Node* n = head;
    Node* next = n->next;
    while(next != NULL) {
        if(n->data > next->data) return false;
        n = next;
        next = n->next;
    }
    return true;
}

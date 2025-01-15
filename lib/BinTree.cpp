#include "../include/BinTree.h"

BinTree::BinTree() : root(NULL), size(0) {}

BinTree::~BinTree() {
    Node* n = head;
    while(n != NULL) {
        Node* next = n->next;
        delete n;
        n = next;
    }
}
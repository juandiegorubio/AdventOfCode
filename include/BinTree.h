#ifndef BIN_TREE_H
#define BIN_TREE_H

#include <cstddef>

class BinTree {
    
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int x) : data(x), left(NULL), right(NULL) {}
    };

    Node* root;
    int size;


public:
    
    BinTree();

    void push(int x);
    

};


#endif
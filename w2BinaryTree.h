//
// Created by julia on 5/22/17.
//

#ifndef ASSIGNMENT2_Q1_BINARYTREE_H
#define ASSIGNMENT2_Q1_BINARYTREE_H

#include <vector>
#include "w2Node.h"


class BinaryTree {
private:
    Node* Root;
    int Size_;

public:
    BinaryTree();
    ~BinaryTree();

    void insert(int elem);
    Node* find(int name);
    void destroy(Node* node);
    Node* get_root();
};


#endif //ASSIGNMENT2_Q1_BINARYTREE_H

//
// Created by julia on 5/24/17.
//

#ifndef WEEK_2_W2_BINARYTREE_H
#define WEEK_2_W2_BINARYTREE_H


#include "w2_Node.h"


class BinaryTree {
private:
    Node* Root_;
    int Size_;

public:
    BinaryTree();
    BinaryTree(Node* Root, int Size);
    BinaryTree(int Size); // create tree by adding children
    ~BinaryTree();

    Node* find(int name, Node* Starter);
    Node* find(int name);
    void destroy(Node* node);
    int getSize();
};


#endif //WEEK_2_W2_BINARYTREE_H

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
    Node* find(int name, Node* Starter);

public:
    BinaryTree();
    BinaryTree(Node* Root);
    ~BinaryTree();

    Node* find(int name);
    const bool insert(Node* new_node, int name, bool is_left);
    void destroy(Node* node);
    const int getSize();
    const int CommonAncestor(int key1, int key2);
    const std::vector<int> ReturnAncestors(int key);
};


#endif //WEEK_2_W2_BINARYTREE_H

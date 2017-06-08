//
// Created by julia on 5/24/17.
//

#ifndef WEEK_2_W2_NODE_H
#define WEEK_2_W2_NODE_H


#include <queue>
#include <set>
#include "w2_BinaryTree.h"


class Node {
    int name;
    int level;
    Node* parent;
    Node* left;
    Node* right;

public:
    friend class BinaryTree;
    friend void DefineNewNode(Node* new_node, int name, Node* old_node, bool is_left, std::set<int> &VertexesSet);
    friend void CreateRoot(Node* Root, int name);
    friend void HelpToCBT1(Node* old_node, bool is_left);
    friend void HelpToCBT2(Node* new_vertex, int name);
};


#endif //WEEK_2_W2_NODE_H

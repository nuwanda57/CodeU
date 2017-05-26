//
// Created by julia on 5/26/17.
//

#ifndef WEEK_2_CREATEBINARYTREE_H
#define WEEK_2_CREATEBINARYTREE_H


#include "w2_BinaryTree.h"


Node* CreateBinaryTree1(BinaryTree& MyTree);
void CreateRoot(Node* Root, int name);
void DefineNewNode(Node* new_node, int name, Node* old_node, bool is_left, std::set<int> &VertexesSet);
Node* CreateBinaryTree2(BinaryTree& MyTree);
void HelpToCBT1(Node* old_node, bool is_left);
void HelpToCBT2(Node* new_vertex, int name);

#endif //WEEK_2_CREATEBINARYTREE_H

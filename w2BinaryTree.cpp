//
// Created by julia on 5/22/17.
//

#include <iostream>
#include "w2BinaryTree.h"


BinaryTree::BinaryTree() {
    Size_ = 0;
}

BinaryTree::~BinaryTree() {
    destroy(Root);
}

void BinaryTree::destroy(Node *node) {
    if (node == NULL)
        return;
    else {
        destroy(node->right);
        destroy(node->left);
    }
    delete node;
}

void BinaryTree::insert(int name) {
    Node *elem = new Node;
    elem->name = name;
    elem->right = NULL;
    elem->left = NULL;
    ++Size_;
    if (Size_ == 1) { // The tree was empty
        elem->parent = NULL;
        Root = elem;
        return;
    }
    Node *Starter = Root;
    // go down from Root till find an empty place
    // if elem->name is bigger --> go right
    // else --> go left
    while (1) {
        if (elem->name <= Starter->name) {
            if (Starter->left == NULL) {
                elem->parent = Starter;
                Starter->left = elem;
                break;
            }
            else
                Starter = Starter->left;
        }
        else {
            if (Starter->right == NULL) {
                elem->parent = Starter;
                Starter->right = elem;
                break;
            }
            else
                Starter = Starter->right;
        }
    }
}

Node* BinaryTree::find(int name) {
    Node* Starter = Root;
    while (Starter->name != name) {
        if (Starter->name < name) {
            if (Starter->right != NULL) {
                Starter = Starter->right;
            }
            else
                return NULL; // such element doesn't exist
        }
        else {
            if (Starter->left != NULL)
                Starter = Starter->left;
            else
                return NULL;
        }
    }
    return Starter;
}

Node* BinaryTree::get_root() {
    return Root;
}
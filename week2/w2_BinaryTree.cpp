//
// Created by julia on 5/24/17.
//

#include <iostream>
#include <queue>
#include <set>
#include "w2_BinaryTree.h"


BinaryTree::BinaryTree() {
    Size_ = 0;
    Root_ = nullptr;
}

BinaryTree::BinaryTree(Node* Root) {
    Root_ = Root;
    Size_ = 0;
    std::queue<Node*> VertexesQueue;
    VertexesQueue.push(Root);
    Node* variable;
    while (!VertexesQueue.empty()) {
        variable = VertexesQueue.front();
        VertexesQueue.pop();
        if (variable != nullptr) {
            ++Size_;
            VertexesQueue.push(variable->left);
            VertexesQueue.push(variable->right);
        }
    }
}

BinaryTree::~BinaryTree() {
    destroy(Root_);
}

void BinaryTree::destroy(Node *node) {
    if (node == nullptr) {
        return;
    } else {
        destroy(node->right);
        destroy(node->left);
        delete node;
    }
}

const int BinaryTree::getSize() {
    return Size_;
}

Node* BinaryTree::find(int name, Node* Starter) {
    if (Starter == nullptr)
        return nullptr;
    Node* ans1 = nullptr;
    Node* ans2 = nullptr;
    if (Starter->name == name) {
        return Starter;
    } else {
        ans1 = find(name, Starter->left);
        ans2 = find(name, Starter->right);
        if (ans1 != nullptr) {
            return ans1;
        }
        return ans2;
    }
}

Node* BinaryTree::find(int name) {
    return find(name, Root_);
}

const bool BinaryTree::insert(Node* new_node, int name, bool is_left) {
    if (Size_ == 0) {
        Root_ = new_node;
        Root_->parent = nullptr;
        Root_->level = 0;
        Size_ = 1;
        return true;
    }
    Node* parent = find(name, Root_);
    if (parent == nullptr) {
        std::cout << "Insertion failed, try again" << std::endl;
        return false;
    }
    if ((is_left && parent->left != nullptr) || (!is_left && parent->right != nullptr)) {
        std::cout << "This place is occupied, try again" << std::endl;
        return false;
    }
    if (is_left) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
    new_node->parent = parent;
    new_node->level = parent->level + 1;
    ++Size_;
    return true;
}

const int BinaryTree::CommonAncestor(int key1, int key2) {
    Node *N1 = find(key1);
    Node *N2 = find(key2);
    if (N1 == nullptr || N2 == nullptr) {
        std::cout << "Impossible input" << std::endl;
        return NULL;
    }
    // lets count the lengths of paths from N1 and N2 to the Root
    // move the vertexes to the same level
    while (N1->level > N2->level) {
        N1 = N1->parent;
        --N1->level;
    }
    while (N2->level > N1->level) {
        N2 = N2->parent;
        --N2->level;
    }
    // find common ancestor
    while (N1->name != N2->name) {
        N1 = N1->parent;
        N2 = N2->parent;
    }
    return N1->name;
}

const std::vector<int> BinaryTree::ReturnAncestors(int key) {
    Node* Starter = find(key);
    std::vector<int> Ancestors;
    if (Starter == nullptr) { // There is no Node with a name equals to the key
        std::cout << "This vertex doesn't exist!" << std::endl;
        return Ancestors;
    } else {
        while (Starter->parent != nullptr) { // while Starter is not Root
            Starter = Starter->parent;
            Ancestors.push_back(Starter->name);
        }
    }
    return (Ancestors);
}

//
// Created by julia on 5/24/17.
//

#include <iostream>
#include <queue>
#include <set>
#include "w2_BinaryTree.h"


BinaryTree::BinaryTree() {
    Size_ = 0;
}

BinaryTree::BinaryTree(Node* Root, int Size) {
    Root_ = Root;
    Size_ = Size;
}

BinaryTree::BinaryTree(int Size) {
    std::queue<Node*> QueueOfVertexes; // is used to store added vertexes
    int counter = 1; // is used to count the number of vertexes given
    std::cout << "Enter Root: ";
    Node* Root = new Node;
    int name;
    std::cin >> name;
    Root->name = name;
    std::cout << std::endl;
    Root->parent = NULL;
    Root->left = NULL;
    Root->right = NULL;
    QueueOfVertexes.push(Root);
    std::string input; // variable
    Node* old_node; // variable
    std::set<int> VertexesSet;
    VertexesSet.insert(Root->name);
    while (counter < Size) { // while the number of given vertex < Size
        if (QueueOfVertexes.empty()) { // but we can't add children
            std::cout << "Impossible Input" << std::endl;
            Size_ = -1;
            return;
        }
        old_node = QueueOfVertexes.front(); // now we can add children of old_node vertex
        QueueOfVertexes.pop();
        std::cout << "Enter the left child of " << old_node->name << " (type 'NULL' if it doesn't exist) ";
        std::cin >> input;
        if (!(input == "NULL" || input == "'NULL'")) {
            name = atoi(input.c_str());
            Node *new_node = new Node;
            new_node->name = name;
            new_node->parent = old_node;
            old_node->left = new_node;
            new_node->left = NULL;
            new_node->right = NULL;
            QueueOfVertexes.push(new_node);
            VertexesSet.insert(new_node->name);
            ++counter;
        }
        if (counter == Size)
            continue;
        std::cout << "Enter the right child of " << old_node->name << " (type 'NULL' if it doesn't exist) ";
        std::cin >> input;
        if (input == "NULL" || input == "'NULL'")
            continue;
        name = atoi(input.c_str());
        Node* new_node1 = new Node;
        new_node1->name = name;
        new_node1->parent = old_node;
        old_node->right = new_node1;
        new_node1->left = NULL;
        new_node1->right = NULL;
        QueueOfVertexes.push(new_node1);
        VertexesSet.insert(new_node1->name);
        ++counter;
    }
    if (!(VertexesSet.size() == Size)) {
         std::cout << "Vertexes must be different!" << std::endl;
        Size_ = -1;
        return;
    }
    Root_ = Root;
    Size_ = Size;
}

BinaryTree::~BinaryTree() {
    destroy(Root_);
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

int BinaryTree::getSize() {
    return Size_;
}

Node* BinaryTree::find(int name, Node* Starter) {
    Node* ans1 = NULL;
    Node* ans2 = NULL;
    if (Starter->name == name)
        return Starter;
    else {
        if (Starter->left != NULL)
            ans1 = find(name, Starter->left);
        if (Starter->right != 0)
            ans2 = find(name, Starter->right);
        if (ans1 != NULL)
            return ans1;
        return ans2;
    }
}

Node* BinaryTree::find(int name) {
    return find(name, Root_);
}

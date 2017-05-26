//
// Created by julia on 5/26/17.
//
// Two variants of creating a tree
//


#include <iostream>
#include <queue>
#include <set>
#include "w2_BinaryTree.h"


void DefineNewNode(Node* new_node, int name, Node* old_node,
                   bool is_left, std::set<int> &VertexesSet) { //friend to Node
    new_node->name = name;
    new_node->parent = old_node;
    new_node->level = old_node->level + 1;
    if (is_left) {
        old_node->left = new_node;
    } else {
        old_node->right = new_node;
    }
    new_node->left = nullptr;
    new_node->right = nullptr;
    VertexesSet.insert(new_node->name);
}

void Help1(BinaryTree &MyTree, Node* old_node, std::queue<Node*> &QueueOfVertexes, // to simplify CreateBinaryTree1()
           std::set<int> &VertexesSet, int& counter, bool is_left) {
    std::string input;
    int name;
    std::cin >> input;
    if (!(input == "NULL" || input == "'NULL'")) {
        name = atoi(input.c_str());
        Node *new_node = new Node;
        DefineNewNode(new_node, name, old_node, is_left, VertexesSet);
        QueueOfVertexes.push(new_node);
        ++counter;
    }
}

void CreateRoot(Node* Root, int name) { // friend to Node
    Root->name = name;
    std::cout << std::endl;
    Root->parent = nullptr;
    Root->left = nullptr;
    Root->right = nullptr;
    Root->level = 0;
}

void HelpToCBT1(Node* old_node, bool is_left) { // friend to Node
    if (is_left) {
        std::cout << "Enter the left child of " << old_node->name << " (type 'NULL' if it doesn't exist) ";
    } else {
        std::cout << "Enter the right child of " << old_node->name << " (type 'NULL' if it doesn't exist) ";
    }
}

Node* CreateBinaryTree1(BinaryTree &MyTree) {
    std::cout << "Let's create a tree. Please, enter the number of vertexes: ";
    int Size;
    std::cin >> Size;
    std::cout << std::endl;
    if (Size <= 0) {
        return nullptr;
    }
    std::queue<Node*> QueueOfVertexes; // is used to store added vertexes
    int counter = 1; // is used to count the number of vertexes given
    std::cout << "Enter Root: ";
    Node* Root = new Node;
    int name;
    std::cin >> name;
    std::set<int> VertexesSet;
    VertexesSet.insert(name);
    CreateRoot(Root, name);
    MyTree.insert(Root, 0, true);
    QueueOfVertexes.push(Root);
    Node* old_node; // variable
    while (counter < Size) { // while the number of given vertex < Size
        if (QueueOfVertexes.empty()) { // but we can't add children
            std::cout << "Impossible Input" << std::endl;
            return nullptr;
        }
        old_node = QueueOfVertexes.front(); // now we can add children of old_node vertex
        QueueOfVertexes.pop();
        HelpToCBT1(old_node, true);
        Help1(MyTree, old_node, QueueOfVertexes, VertexesSet, counter, true);
        if (counter == Size) {
            continue;
        }
        HelpToCBT1(old_node, false);
        Help1(MyTree, old_node, QueueOfVertexes, VertexesSet, counter, false);
    }
    if (!(VertexesSet.size() == Size)) {
        std::cout << "Vertexes must be different!" << std::endl;
        return nullptr;
    }
    return Root;
}

void HelpToCBT2(Node* new_vertex, int name) { // friend to Node
    new_vertex->name = name;
    new_vertex->left = NULL;
    new_vertex->right = NULL;
}

Node* CreateBinaryTree2(BinaryTree &MyTree) {
    std::cout << "Let's create a tree. Please, enter the number of vertexes: ";
    int Size;
    std::cin >> Size;
    std::cout << std::endl;
    if (Size <= 0) {
        return nullptr;
    }
    std::set<int> Vertexes;
    std::cout << "Enter Root: ";
    Node* Root = new Node;
    int name;
    std::cin >> name;
    Vertexes.insert(name);
    CreateRoot(Root, name);
    MyTree.insert(Root, 0, true);
    int v_parent; // variable
    int v_RL;
    int counter = 1;
    while (counter < Size) {
        std::cout << "Enter the vertex you want to add: ";
        Node* new_vertex = new Node;
        std::cin >> name;
        if (Vertexes.find(name) != Vertexes.end()) {
            std::cout << "The vertex already in the tree, try again" << std::endl;
            continue;
        }
        std::cout << std::endl;
        HelpToCBT2(new_vertex, name);
        std::cout << "Enter it's parent: ";
        std::cin >> v_parent;
        std::cout << std::endl;
        std::cout << "If the new vertex is the left child type '1'. Otherwise type '2' " << std::endl;
        std::cin >> v_RL;
        if (!(v_RL == 1 || v_RL == 2)) {
            std::cout << "Insertion failed, try again" << std::endl;
            continue;
        }
        if (v_RL == 1) {
            if (!MyTree.insert(new_vertex, v_parent, true)) {
                continue;
            } else {
                ++counter;
            }
        }
        else {
            if (!MyTree.insert(new_vertex, v_parent, false)) {
                continue;
            } else {
                ++counter;
            }
        }
        Vertexes.insert(name);
        std::cout << std::endl << "Successful insertion!" << std::endl;
    }
}

//
// Created by julia on 5/24/17.
//


#include<iostream>
#include "w2_BinaryTree.h"
#include "w2_q1.h"
#include "w2_q2.h"
#include "CreateBinaryTree.h"


int main() {
    std::cout << "Choose a way to create a tree." << std::endl;
    std::cout << "Type '1' if you want to enter every level of it" << std::endl;
    std::cout << "Or type '2' if you prefer to build the tree vertex by vertex ";
    int WhichInput;
    BinaryTree MyTree;
    std::cin >> WhichInput;
    if (!(WhichInput == 1 || WhichInput == 2)) {
        std::cout << "Impossible Input" << std::endl;
        return 0;
    }
    if (WhichInput == 1) {
        if (CreateBinaryTree1(MyTree) == nullptr) {
            return 0;
        }
    } else {
        CreateBinaryTree2(MyTree);
    }

    std::cout << "Type '1' to run Q1 or '0' to run Q2: ";
    int WhichProblem;
    std::cin >> WhichProblem;
    if (WhichProblem == 1) {
        // show ancestors
        std::cout << "Enter a vertex: ";
        int key;
        std::cin >> key;
        ShowAncestors(MyTree, key);
        return 0;
    }
    if (WhichProblem == 0) {
        // Common Ancestor
        // rest input data
        std::cout << "Enter two vertexes: ";
        int key1, key2;
        std::cin >> key1 >> key2;
        std::cout << std::endl;
        PrintCommonAncestor(MyTree, key1, key2);
        return 0;
    }
    std::cout << "Not valid input" << std::endl;
    return 0;
}

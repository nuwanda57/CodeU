//
// Created by julia on 5/24/17.
//


#include<iostream>
#include "w2_BinaryTree.h"
#include "w2_q1.h"
#include "w2_q2.h"


int main() {
    std::cout << "Let's create a tree. Please, enter the number of vertexes: ";
    int N;
    std::cin >> N;
    std::cout << std::endl;
    if (N <= 0)
        return 0;
    BinaryTree MyTree = BinaryTree(N);
    if (MyTree.getSize() == -1)
        return 0;

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

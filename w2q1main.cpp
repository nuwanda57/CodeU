//CodeU: Assignment2-Q1
//
//  Created by Julia Semavina on 22.05.2017
//
//  problem specification:
//      Given a Binary Tree and a key, write a function that prints all the ancestors of the key
//      in the given binary tree.
//
//  comments:
//      Data Structures: Node ("Node.h"), BinaryTree (BinaryTree.h")
//      input data:
//          1) Number of vertexes (must be positive integer)
//          2) List of vertexes (all of the vertexes must be different integers)
//          3) Any vertex from the list
//      output data:
//          all the ancestors of the vertex, started with parent
//      ShowAncestors function contains a solution
//


#include <iostream>
#include <vector>
#include <set>

#include "w2BinaryTree.h"


void ShowAncestors(BinaryTree &MyBTree, int key) {
    Node* Starter = MyBTree.find(key);
    if (Starter == NULL) // There is no Node with a name equals to the key
        std::cout << "This vertex doesn't exist!" << std::endl;
    else {
        while (Starter->parent != NULL) { // while Starter is not Root
            Starter = Starter->parent;
            std::cout << Starter->name << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Create a Binary Tree
    std::cout << "Enter number of vertexes: ";
    int N;
    BinaryTree MyBTree;
    std::cin >> N;
    if (N <= 0) {
        std::cout << "Impossible input!" << std::endl;
        return 0;
    }
    std::set<int> Vertexes;
    std::cout << std::endl;
    std::cout << "Enter different vertexes: ";
    int node;
    for (int i = 0; i < N; ++i) {
        std::cin >> node;
        Vertexes.insert(node);
        MyBTree.insert(node);
    }
    if (Vertexes.size() != N) {
        std::cout << "Vertexes must be different" << std::endl;
        return 0;
    }

    // show ancestors
    std::cout << "Enter a vertex: ";
    int key;
    std::cin >> key;
    ShowAncestors(MyBTree, key);
    return 0;
}

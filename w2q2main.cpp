//CodeU: Assignment2-Q2
//
//  Created by Julia Semavina on 22.05.2017
//
//  problem specification:
//      Design an algorithm and write ​ code​ to find the lowest common ancestor of two nodes in a binary tree.
//      Avoid storing additional nodes in a data structure.
//
//  comments:
//      Data Structures: Node ("Node.h"), BinaryTree (BinaryTree.h")
//      input data:
//          1) Number of vertexes (must be positive integer)
//          2) List of vertexes (all of the vertexes must be different integers)
//          3) Two vertexes from the list
//      output data:
//          Common Ancestor
//      idea:
//          It is clear that, if value of a vertex is bigger than value of the Root,
//          the vertex is in the right subTree. Otherwise in the left.
//          So the lowest common ancestor is the vertex that a one of the given vertexes is
//          in the left subTree and the other one is in the right subTree
//          Otherwise both of them are in the same subTree.
//          So we start from the Root. Then go left or right,
//          depending on where the two given vertexes are, till we find the lowest common ancestor
//


#include <iostream>
#include <set>

#include "w2BinaryTree.h"


void PrintCommonAncestor(BinaryTree &MyBTree, int key1, int key2) {
    Node *N1 = MyBTree.find(key1);
    Node *N2 = MyBTree.find(key2);
    if (N1 == NULL || N2 == NULL) {
        std::cout << "Impossible input" << std::endl;
        return;
    }
    Node *Candidate = MyBTree.get_root();
    while (!(key1 >= Candidate->name && key2 <= Candidate->name)) { // the lowest common ancestor
        if (key1 > Candidate->name)
            Candidate = Candidate->right;
        else
            Candidate = Candidate->left;
    }
    std::cout << "Their common ancestor is: " << Candidate->name << std::endl;
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

    // rest input data
    std::cout << "Enter two vertexes: ";
    int key1, key2;
    std::cin >> key1 >> key2;
    std::cout << std::endl;

    // solution
    if (key1 < key2)
        std::swap(key1, key2);
    PrintCommonAncestor(MyBTree, key1, key2);
    return 0;
}
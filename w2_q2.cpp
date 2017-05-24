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
//          follow the instructions
//      output data:
//          Common Ancestor
//      Complexity:
//          O(N^2) in a very bad case: (almost every vertex has the only one child
//          and the number of left children of the Root is almost equal to the number of it's right children)
//          Common Case (almost every vertex has two children): O((log(n))^2)
//          We can achieve better results by storing additional nodes.
//      Idea:
//          At the beginning we have two nodes (N1, N2). Then we start moving them up to the root.
//          One of them (N2) moves faster: we check if N1 equals to N2 or all of it's ancestor.
//          The we move N1 one level up (N1 = N1->parent) and return N2 to it's start position.
//          And do the same: check if this N1 (N1->parent) equals to N2 or any of it's ancestors.
//          We do this till N1 != Root->parent = NULL
//          Thus we've checked every possibility
//



#include <iostream>
#include <set>

#include "w2_BinaryTree.h"


void PrintCommonAncestor(BinaryTree &MyBTree, int key1, int key2) {
    Node *N1 = MyBTree.find(key1);
    Node *N2 = MyBTree.find(key2);
    if (N1 == NULL || N2 == NULL) {
        std::cout << "Impossible input" << std::endl;
        return;
    }
    Node *MovingN2 = N2;
    while (N1 != NULL) {
        while (MovingN2 != NULL && N1->name != MovingN2->name)
            MovingN2 = MovingN2->parent;
        if (MovingN2 != NULL && MovingN2->name == N1->name) {
            std::cout << "Their common ancestor is: " << N1->name;
            return;
        }
        MovingN2 = N2;
        N1 = N1->parent;
    }
}

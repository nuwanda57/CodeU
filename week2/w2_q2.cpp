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
//          O(N) in a very bad case: (almost every vertex has the only one child
//          and the number of left children of the Root is almost equal to the number of it's right children)
//          Common Case (almost every vertex has two children): O(log(n))
//      Idea:
//          At the beginning we have two nodes (N1, N2). N1 equals to N2 only if
//          they are at the same level from the Root. So we move them to the same level
//          and them move them every step up together till their values are the same.
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
    // lets count the lengths of paths from N1 and N2 to the Root
    int N1Level = 0;
    int N2Level = 0;
    Node* vN1 = N1;
    Node* vN2 = N2;
    // count N1Level, N2Level
    while (vN1->parent != NULL) {
        ++N1Level;
        vN1 = vN1->parent;
    }
    while (vN2->parent != NULL) {
        ++N2Level;
        vN2 = vN2->parent;
    }
    // move the vertexes to the same level
    while (N1Level > N2Level) {
        N1 = N1->parent;
        --N1Level;
    }
    while (N2Level > N1Level) {
        N2 = N2->parent;
        --N2Level;
    }
    // find common ancestor
    while (N1->name != N2->name) {
        N1 = N1->parent;
        N2 = N2->parent;
    }
    std::cout << "Their common ancestor is: " << N1->name;
}

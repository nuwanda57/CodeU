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
//      The function is a class BinaryTree member (CommonAncestor)
//



#include <iostream>
#include <set>

#include "w2_BinaryTree.h"


void PrintCommonAncestor(BinaryTree &MyBTree, int key1, int key2) {
    int ancestor = MyBTree.CommonAncestor(key1, key2);
    if (ancestor == NULL) {
        std::cout << "Impossible Input" << std::endl;
    } else {
        std::cout << "Their common ancestor is: " << ancestor << std::endl;
    }
}

//CodeU: Assignment2-Q1
//
//  Created by Julia Semavina on 24.05.2017
//
//  problem specification:
//      Given a Binary Tree and a key, write a function that prints all the ancestors of the key
//      in the given binary tree.
//
//  comments:
//      Data Structures: Node ("Node.h"), BinaryTree (BinaryTree.h")
//      input data:
//          follow the instructions
//      output data:
//          all the ancestors of the vertex, started with parent
//      ShowAncestors function contains a solution
//

#include <iostream>
#include <vector>
#include "w2_BinaryTree.h"


const void ShowAncestors(BinaryTree &MyBTree, int key) {
    std::vector<int> ancestors = MyBTree.ReturnAncestors(key);
    for (int i = 0; i < ancestors.size(); ++i) {
        std::cout << ancestors[i] << " ";
    }
    std::cout << std::endl;
}


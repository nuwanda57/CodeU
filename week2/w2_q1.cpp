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
#include "w2_BinaryTree.h"


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

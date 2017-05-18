//CodeU: Q2
//
//  Created by Julia Semavina on 18.05.2017
//
//  problem specification:
//      Implement an algorithm to find the kth to last element of a singly linked list
//
//  comments:
//      list length is unknown
//      if K is bigger than the size of the list the answer will be IMPOSSIBLE INPUT
//      KthToLast function contains a solution
//

#include <iostream>
#include <vector>


struct Node {
    char value;
    Node* next;
};

Node* CreateSinglyLinkedList() {
    Node *Head = new Node;
    std::cin >> Head->value;
    Node *elem1 = Head;
    Node *elem2 = new Node;
    while (std::cin >> elem2->value) {
        elem1->next = elem2;
        elem1 = elem2;
        elem2 = new Node;
    }
    elem1->next = NULL;
    return (Head);
};

Node* KthToLast(Node* Head, int K, bool &problem) {
    Node* Elem = Head;
    // pass through the list till K nodes are passed
    for (int i = 0; i < K; ++i) {
        if (Elem->next != NULL)
            Elem = Elem->next;
        else { // K is bigger than the list length
            problem = true;
            std::cout << "IMPOSSIBLE INPUT" << std::endl;
            return Elem;
        }
    }
    // Now we use another pointer with the same speed,
    // that stars from the Head
    Node *FutureResult = Head;
    // When the first pointer reaches the end of the list
    // The second pointer points at the answer
    while (Elem->next != NULL){
        Elem = Elem->next;
        FutureResult = FutureResult->next;
    }
    return (FutureResult);
}

void ClearMemory(Node* Head) {
    Node* Next = Head;
    while (Next->next != NULL) {
        Head = Next->next;
        delete Next;
        Next = Head;
    }
}

int main() {
    // input Data
    int K;
    std::cin >> K;
    Node* Head = CreateSinglyLinkedList();
    // main part
    bool problem = false; // is used to check if the input is valid
    Node* Result = KthToLast(Head, K, problem);
    // result
    if (!problem)
        std::cout << Result->value << std::endl;
    ClearMemory(Head);
    return 0;
}

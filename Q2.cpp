//CodeU: Q2
//
//  Created by Julia Semavina on 18.05.2017
//
//  problem specification:
//      Implement an algorithm to find the kth to last element of a singly linked list
//
//  comments:
//      list length is unknown
//      if the list is empty the answer will be IMPOSSIBLE INPUT
//      if K is bigger than the size of the list the answer will be IMPOSSIBLE INPUT
//      if K<0: also IMPOSSIBLE INPUT
//      KthToLast function contains a solution
//

#include <iostream>
#include <vector>

template <typename T>
struct Node {
    T value;
    Node* next;
};

template <typename T>
Node<T>* CreateSinglyLinkedList() {
    Node<T> *Head = new Node<T>;
    std::cout << "Enter a list of elements" << std::endl;
    std::cin >> Head->value;
    Node<T> *elem1 = Head;
    Node<T> *elem2 = new Node<T>;
    while (std::cin >> elem2->value) {
        elem1->next = elem2;
        elem1 = elem2;
        elem2 = new Node<T>;
    }
    elem1->next = NULL;
    return Head;
};

template <typename T>
Node<T>* KthToLast(Node<T>* Head, int K) {
    if (K < 0 || Head->value == NULL)
        return NULL;
    Node<T>* Elem = Head;
    // pass through the list till K nodes are passed
    for (int i = 0; i < K; ++i) {
        if (Elem->next != NULL)
            Elem = Elem->next;
        else // K is bigger than the list length
            return NULL;
    }
    // Now we use another pointer with the same speed,
    // that starts from the Head
    Node<T> *FutureResult = Head;
    // When the first pointer reaches the end of the list
    // The second pointer points at the answer
    while (Elem->next != NULL){
        Elem = Elem->next;
        FutureResult = FutureResult->next;
    }
    return FutureResult;
}

template <typename T>
void ClearMemory(Node<T>* Head) {
    Node<T>* Next = Head;
    while (Next->next != NULL) {
        Head = Next->next;
        delete Next;
        Next = Head;
    }
}

template <typename T>
void MainFunction() {
    // input Data
    std::cout << "enter a positive integer" << std::endl;
    int K;
    std::cin >> K;
    Node<T>* Head = CreateSinglyLinkedList<T>();
    // main part
    Node<T>* Result = KthToLast(Head, K);
    // result
    if (Result == NULL)
        std::cout << "IMPOSSIBLE INPUT" << std::endl;
    else
        std::cout << Result->value << std::endl;
    ClearMemory(Head);
}

int main() {
    std::cout << "enter type" << std::endl;
    std::string type;
    std::cin >> type;
    MainFunction<char>();
    return 0;
}

//CodeU: Q1
//
//  Created by Julia Semavina on 17.05.2017
//
//  problem specification:
//      Given two strings, write a method to decide if one is a permutation of the other
//
//  comments:
//      register is ignored
//

#include <iostream>
#include <map>


char lowercase(char a) {
    if (a <= 'Z' && a >= 'A')
        return (a - ('Z' - 'z'));
    return a;
}

bool is_permutation(std::string &A, std::string &B) {
    // check if the lengths are equal
    if (A.length() != B.length())
        return false;
    // make a dictionary from string A,
    // keys - different elements of string A
    // values - number of each key in string A
    std::map<char, int> A_elements;
    char x;
    for (int i = 0; i < A.length(); ++i) {
        x = lowercase(A[i]);
        if (A_elements.find(x) == A_elements.end())
            A_elements[x] = 1;
        else
            A_elements[x] += 1;
    }
    // check if string B consists of elements in the dictionary
    for (int i = 0; i < B.length(); ++i) {
        x = lowercase(B[i]);
        if (A_elements.find(x) == A_elements.end())
            return false;
        if (A_elements[x] == 0)
            return false;
        A_elements[x]--;
    }
    return true;
}

int main() {
    std::string A, B;
    std::cin >> A >> B;
    if (is_permutation(A, B))
        std::cout << "Yes";
    else
        std::cout << "No";
    return 0;
}
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


bool is_permutation(const std::string &A, const std::string &B) {
    // check if the lengths are equal
    if (A.length() != B.length())
        return false;
    // make a dictionary from string A,
    // keys - different elements of string A
    // values - number of each key in string A
    std::map<char, int> A_elements;
    for (char x: A) {
        x = tolower(x);
        A_elements[x] ++;
    }
    // check if string B consists of elements in the dictionary
    // Important! We also need to check if the length of B
    // equals to the number of elements in the dictionary
    // But the check was already done in the beginning of the function
    for (char x: B) {
        x = tolower(x);
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
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    return 0;
}

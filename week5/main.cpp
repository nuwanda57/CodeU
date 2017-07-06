//
// Created by julia on 7/6/17.
//
// Problem specification:
//      Given a dictionary (a list of words in lexicographic order)
//      of all words in an unknown/invented language, find the alphabet
//      (an ordered list of characters) of that language.
//
// Solution:
//      Topological sort (WordGraph method)
//
// - empty input and incorrect given dictionary - wrong input
//
//


#include <iostream>
#include <vector>
#include "WordGraph.h"


std::vector<std::string> read_input() {
    std::vector<std::string> GivenDictionary;
    int NumberOfWords;
    std::cout << "Enter the number of words in the dictionary:" << std::endl;
    std::cin >> NumberOfWords;
    std::string new_word;
    std::cout << "Enter the words in alphabetic order:" << std::endl;
    for (int i = 0; i < NumberOfWords; ++i) {
        std::cin >> new_word;
        GivenDictionary.push_back(new_word);
    }
    return (GivenDictionary);
}


void show(std::vector<char> TheAlphabet) {
    if (TheAlphabet.size() == 0) {
        std::cout << "Something wrong with the input" << std::endl;
        return;
    }
    for (int i = 0; i < TheAlphabet.size(); ++i) {
        std::cout << TheAlphabet[i] << " ";
    }
    std::cout << std::endl;
}


int main() {
    std::vector<std::string> GivenDictionary = read_input();
    WordGraph Graph(GivenDictionary);
    std::vector<char> TheAlphabet = Graph.Alphabet();
    show(TheAlphabet);
    return 0;
}
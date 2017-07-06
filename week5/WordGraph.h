//
// Created by julia on 7/6/17.
//

#ifndef WEEK5_WORDGRAPH_H
#define WEEK5_WORDGRAPH_H


#include <iostream>
#include <vector>


class WordGraph {
private:
    std::vector<std::vector<int>> Connections_;
    std::vector<bool> IsUsed_; // is used for Alphabet method
    std::vector<short> State_; // is used for is_solution method
    void DFS(std::vector<char>& answer, int starter, std::vector<bool>& trouble);
    const bool is_solution();
public:
    WordGraph(std::vector<std::string>& GivenDictionary);
    std::vector<char> Alphabet();
};


#endif //WEEK5_WORDGRAPH_H

//
// Created by julia on 7/6/17.
//

#include "WordGraph.h"


WordGraph::WordGraph(std::vector<std::string> &GivenDictionary) {
    std::vector<int> connection (0);
    for (int i = 0; i < 128; ++i) {
        IsUsed_.push_back(false);
        Connections_.push_back(connection);
    }
    int Size = GivenDictionary.size();
    std::string first_word; // variable
    std::string second_word; // variable
    for (int i = 0; i < Size - 1; ++i) {
        int index = 0;
        first_word = GivenDictionary[i];
        second_word = GivenDictionary[i + 1];
        int border = std::min(first_word.length(), second_word.length());
        while (index < border && first_word[index] == second_word[index]) { // before adding a connection
            IsUsed_[(int)first_word[index]] = true;
            ++index;
        }
        if (index < border) { // adding a connection
            Connections_[(int)second_word[index]].push_back((int)first_word[index]);
        }
        while (index < first_word.length()) { // after adding a connection
            IsUsed_[(int)first_word[index]] = true;
            ++index;
        }
    }
    if (Size != 0) {
        first_word = GivenDictionary[Size - 1];
        for (int i = 0; i < first_word.length(); ++i) {
            IsUsed_[(int)first_word[i]] = true;
        }
    }
}


void WordGraph::DFS(std::vector<char>& answer, int starter, std::vector<bool>& trouble) {
    State_[starter] = 1;
    for (int i = 0; i < Connections_[starter].size(); ++i) {
        int new_vertex = Connections_[starter][i];
        if (State_[new_vertex] == 0) {
            DFS(answer, new_vertex, trouble);
        } else {
            if (State_[new_vertex] == 1) {
                trouble[0] = true;
            }
        }
    }
    State_[starter] = 2;
    answer.push_back((char)starter);
}


std::vector<char> WordGraph::Alphabet() {
    std::vector<bool> trouble (1, false);
    for (int i = 0; i < 128; ++i) {
        State_.push_back(0);
    }
    std::vector<char> answer;
    for (int i = 0; i < 128; ++i) {
        if (IsUsed_[i] && State_[i] == 0) {
            DFS(answer, i, trouble);
            if (trouble[0]) {
                State_.clear();
                answer.clear();
                return answer;
            }
        }
    }
    State_.clear();
    return answer;
}

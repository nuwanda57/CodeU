//
// Created by julia on 6/8/17.
//

#ifndef WEEK_3_WORD_H
#define WEEK_3_WORD_H

#include <iostream>
#include <set>


class Dictionary {
private:
    std::set<std::string> Self_;
    std::set<std::string> Prefixes_;
public:
    Dictionary();

    const bool is_word(std::string word);
    const bool is_prefix(std::string word);
    void insert(std::string word);
};


#endif //WEEK_3_WORD_H

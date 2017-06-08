//
// Created by julia on 6/8/17.
//

#ifndef WEEK_3_WORD_H
#define WEEK_3_WORD_H

#include <iostream>
#include <set>


class word {
private:
    std::string object_;
public:
    word(std::string object);

    const bool is_word(std::set<std::string> TheDictionary);
    const bool is_prefix(std::set<std::string> Prefixes);
};


#endif //WEEK_3_WORD_H

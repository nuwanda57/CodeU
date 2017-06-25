//
// Created by julia on 6/8/17.
//

#include "word.h"


Dictionary::Dictionary() {
}

const bool Dictionary::is_word(std::string word) {
    return Self_.find(word) != Self_.end();
}

const bool Dictionary::is_prefix(std::string word) {
    return Prefixes_.find(word) != Prefixes_.end();
}

void Dictionary::insert(std::string word) {
    Self_.insert(word);
    std::string word1 = "";
    for (int i = 0; i < word.length(); ++i) {
        word1 = word1 + word[i];
        Prefixes_.insert(word1);
    }
}

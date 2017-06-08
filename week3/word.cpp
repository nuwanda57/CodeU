//
// Created by julia on 6/8/17.
//

#include "word.h"


word::word(std::string object) {
    object_ = object;
}

const bool word::is_word(std::set<std::string> TheDictionary) {
    return TheDictionary.find(object_) != TheDictionary.end();
}

const bool word::is_prefix(std::set<std::string> Prefixes) {
    return Prefixes.find(object_) != Prefixes.end();
}

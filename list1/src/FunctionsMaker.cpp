#include "FunctionsMaker.h"

FunctionsMaker::FunctionsMaker(const std::string &pattern) {
    this->pattern = pattern;
    this->patternSize = pattern.size();
    this->function = std::vector<int>(this->patternSize, -1);
}

std::vector<int> FunctionsMaker::generate() {
    int pointer = -1;

    for (int i = 1; i < this->patternSize; i++) {
        while (pointer >= 0 && this->pattern[pointer + 1] != this->pattern[i])
            pointer = this->function[pointer];
        if (this->pattern[pointer + 1] == this->pattern[i])
            pointer++;
        this->function[i] = pointer;
    }

    return this->function;
}

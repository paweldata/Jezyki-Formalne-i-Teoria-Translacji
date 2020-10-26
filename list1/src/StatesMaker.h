#ifndef STATESMAKER_H
#define STATESMAKER_H


#include <vector>

#include "State.h"

class StatesMaker {
public:
    explicit StatesMaker(const std::string &pattern);
    std::vector<State> generate();

private:
    void calculateAndSetState(int index, char currChar);

    std::vector<State> states;
    std::string pattern;
    int patternSize;
};


#endif //STATESMAKER_H

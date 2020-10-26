#include "StatesMaker.h"

StatesMaker::StatesMaker(const std::string &pattern) {
    this->pattern = pattern;
    this->patternSize = pattern.size();
    this->states = std::vector<State>(this->patternSize + 1, State());
}

std::vector<State> StatesMaker::generate() {
    for (int i = 0; i <= this->patternSize; i++) {
        for (const char& currChar : this->pattern) {
            this->calculateAndSetState(i, currChar);
        }
    }
    
    return this->states;
}

void StatesMaker::calculateAndSetState(int i, char currChar) {
    int currState = std::min(this->patternSize, i + 1);
    std::string patternSuffix(this->pattern.substr(i == this->patternSize ? 1 : 0, i) + currChar);

    while(currState > 0 && this->pattern.compare(0, currState, patternSuffix) != 0) {
        patternSuffix.erase(0, 1);
        currState--;
    }

    this->states[i].setStateIndex(currChar, currState);
}

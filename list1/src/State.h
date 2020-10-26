#ifndef STATE_H
#define STATE_H

#include <map>
#include <vector>

class State {
public:
    State() {this->map = std::map<uint8_t, int>(); }

    int returnNewStateIndex(uint8_t currChar) { return this->map[currChar]; }
    void setStateIndex(uint8_t currChar, int stateIndex) { this->map[currChar] = stateIndex; }

private:
    std::map<uint8_t, int> map;
};


#endif //STATE_H

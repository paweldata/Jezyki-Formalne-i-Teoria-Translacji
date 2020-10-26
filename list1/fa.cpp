#include <cstdio>
#include <vector>

#include "src/State.h"
#include "src/StatesMaker.h"
#include "src/Parameters.h"
#include "src/Utf8.cpp"

int main(int argc, char **argv) {
    Parameters param(argc, argv);

    if (!param.ifCorrect()) {
        Parameters::showError();
        return -1;
    }

    std::vector<State> states = StatesMaker(param.pattern).generate();
    const uint32_t desireState = param.pattern.size();
    const uint32_t patternSize = utf8::getSizeInUtf8(param.pattern);

    uint8_t currChar = 0;
    uint32_t currState = 0;
    uint64_t index = 0;

    while (param.input >> std::noskipws >> currChar) {
        currState = states[currState].returnNewStateIndex(currChar);
        utf8::increaseIndexIfNecessary(index, currChar);
        if (currState == desireState)
            printf("%lu\n", index - patternSize);
    }

    return 0;
}

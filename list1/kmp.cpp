#include <cstdio>
#include <vector>

#include "src/FunctionsMaker.h"
#include "src/Parameters.h"
#include "src/Utf8.cpp"

int main(int argc, char **argv) {
    Parameters param(argc, argv);

    if (!param.ifCorrect()) {
        Parameters::showError();
        return -1;
    }

    const std::vector<int> f = FunctionsMaker(param.pattern).generate();
    const uint32_t desirePointer = param.pattern.size() - 1;
    const uint32_t patternSize = utf8::getSizeInUtf8(param.pattern);

    uint8_t currChar = 0;
    uint64_t index = 0;
    int pointer = -1;

    while (param.input >> std::noskipws >> currChar) {
        utf8::increaseIndexIfNecessary(index, currChar);
        while (pointer >= 0 && currChar && uint8_t(param.pattern[pointer + 1]) != currChar)
            pointer = f[pointer];
        if (uint8_t(param.pattern[pointer + 1]) == currChar)
            pointer++;
        if (pointer == desirePointer) {
            printf("%lu\n", index - patternSize);
            pointer = f[pointer];
        }
    }

    return 0;
}

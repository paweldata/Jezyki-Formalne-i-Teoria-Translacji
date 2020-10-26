#ifndef PARAMETERS_H
#define PARAMETERS_H


#include <fstream>
#include <vector>

struct Parameters {
    Parameters(int argc, char** argv) {
        if (argc < 2)
            return;
        this->pattern = argv[1];
        this->input = std::ifstream(argv[2]);
    }

    bool ifCorrect() const { return !this->pattern.empty() && this->input.is_open(); }

    static void showError() {
        printf("Give parameters:\n"
               "./fa <pattern> <filename>\n");
    }

    std::string pattern;
    std::ifstream input;
};


#endif //PARAMETERS_H

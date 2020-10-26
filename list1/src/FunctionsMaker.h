#ifndef FUNCTIONSMAKER_H
#define FUNCTIONSMAKER_H


#include <vector>
#include <string>

class FunctionsMaker {
public:
    explicit FunctionsMaker(const std::string& pattern);
    std::vector<int> generate();

private:
    std::vector<int> function;
    std::string pattern;
    int patternSize;
};


#endif //FUNCTIONSMAKER_H

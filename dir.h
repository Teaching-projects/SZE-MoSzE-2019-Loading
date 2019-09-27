#include <iostream>
#include <string>

#ifndef DIR_H
#define DIR_H

class Dir {
    std::string dirname;
    std::string parentname;
public:
    Dir(std::string, std::string);
    std::string getName();
    std::string getParent();
};

#endif /* DIR_H */

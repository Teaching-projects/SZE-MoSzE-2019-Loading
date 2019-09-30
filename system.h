#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include "dir.h"

class System {
    std::vector<Dir*> dirs;
    const std::string user = "User@User:";
    std::string currentFolder = "/";
    std::string path = "/";
public:
    std::string getCurrentFolder();
    void mkdir(std::string);
    void ls();
    void cd(std::string);
    void cdBack();
    void printPath();
};

#endif /* SYSTEM_H */

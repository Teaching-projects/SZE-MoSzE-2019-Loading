#ifndef SYSTEM_H
#define SYSTEM_H

#include "dir.h"
#include "file.h"
#include <vector>

class System {
    std::vector<Dir*> dirs;
    std::vector<File*> files;
    const std::string user = "Domain@Host:";
    std::string currentFolder = "/";
    std::string path = "/";
public:
    std::string getCurrentFolder();
    void mkdir(std::string);
    void ls();
    void cd(std::string);
    void cdBack();
    void printPath();
    void rm(std::string);
    bool hasChild(std::string);
    bool isExist(std::string);
    std::string getChild(std::string);
    void rmrf(std::string);
    void touch(std::string);
};

#endif // SYSTEM_H

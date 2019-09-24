#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include "dir.h"

class System {
    std::vector<Dir*> dirs;
    std::string currentFolder = "/";
public:
    std::string getCurrentFolder();
    void mkDir(std::string);
    void ls();
    void cd(std::string);
    void cdBack();
};

#endif /* SYSTEM_H */

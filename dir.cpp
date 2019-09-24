#include "dir.h"

Dir::Dir(std::string name, std::string parentname){
    this->dirname = name;
    this->parentname = parentname;
}

std::string Dir::getName(){
    return this->dirname;
}

std::string Dir::getParent(){
    return this->parentname;
}

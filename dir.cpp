#include "dir.h"

Dir::Dir(std::string dirname, std::string parentname) : dirname(dirname), parentname(parentname) {}

std::string Dir::getName() {return dirname;}

std::string Dir::getParent() {return parentname;}

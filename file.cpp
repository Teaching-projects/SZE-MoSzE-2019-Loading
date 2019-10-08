#include "file.h"

File::File(std::string name, std::string parent) : name(name), parent(parent) {}

std::string File::getName() { return name; }

std::string File::getParent() { return parent; }
